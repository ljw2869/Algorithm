#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<vector<int>>graph;
vector<pair<int,int>>Tree; //첫번째 인자는 부모노드, 두번째 인자는 깊이
vector<bool>visited;

void DFS(int idx,int parent,int depth){

    visited[idx]=true;
    Tree[idx].first=parent;
    Tree[idx].second=depth;
    
    for(int i:graph[idx]){
        if(visited[i]==false)
        {
            DFS(i,idx,depth+1);
        }
    }
}

int LCA(int a,int b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    graph.resize(n+1);
    Tree.resize(n+1);
    visited.resize(n+1,false);

    int a,b;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(1,0,1);//1번 노드는 루트노드로, 부모 노드가 없으며(0), 깊이는 1로 시작한다

    //탐색 후 트리가 잘 만들어졌는지 확인하는 코드
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<Tree[i].first<<" "<<Tree[i].second<<"\n";
    // }

    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;

        cout<<LCA(a,b)<<"\n";
    }

    return 0;
}


int LCA(int a,int b)
{
    // 깊이를 같게 맞춤
    while(Tree[a].second > Tree[b].second)
        a = Tree[a].first;
    while(Tree[b].second > Tree[a].second)
        b = Tree[b].first;
    
    while(a!=b)//두 노드가 같을 때 까지
    {
        a=Tree[a].first;
        b=Tree[b].first;
    }
    return a;
}