//BFS로 구현한 코드
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<vector<int>>graph;

vector<int>depth;
vector<int>parent;
vector<bool>visited;

static int n,m;

int LCA(int a,int b);
void BFS(int root);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    graph.resize(n+1);
    depth.resize(n+1);
    parent.resize(n+1);
    visited.resize(n+1,false);

    int a,b;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    BFS(1);//1번 노드부터 BFS로 탐색하면서 parent와 depth를 채워준다
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        cout<<LCA(a,b)<<"\n";
    }

    return 0;
}

void BFS(int root)
{
    queue<int>q;

    q.push(root);
    visited[root]=true;
    depth[root]=0;//여기를 처음에 깊이를 1로 두고 아래 자식 노드를 다룰 때도 level에 1을 넣어서 오류가 발생(일관성 있게 작성하자...)

    int now_size=1;
    int count=0;
    int level=1;

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        for(int next:graph[cur])
        {
            if(!visited[next])
            {
                visited[next]=true;
                q.push(next);
                parent[next]=cur;
                depth[next]=level;
            }
        }
        count++;
        if(count==now_size)//이렇게 되면 결국에는 1, 2, 4...등 깊이가 때에 맞게 업데이트가 됨
        {
            count=0;
            now_size=q.size(); //now_size는 다음 깊이에서 다루게 될 노드의 개수
            level++;
        }
    }
}

int LCA(int a,int b)
{
    if(depth[a]<depth[b])
    {
        int tmp=a;
        a=b;
        b=tmp;
    }//무조건 a쪽이 깊이가 깊은 쪽으로 설정하기 위해서(아래의 반복문을 a기준으로 돌리려고)
    
    while(depth[a]!=depth[b])
    {
        a=parent[a];
    }

    while(a!=b)//두 노드가 같을 때 까지
    {
        a=parent[a];
        b=parent[b];
    }
    return a;
}