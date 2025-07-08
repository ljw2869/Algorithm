#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int>visited;
vector<vector<int>>graph;

int cnt=0;

void bfs(int start){
    queue<int>q;
    q.push(start);
    visited[start]=++cnt;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i:graph[top]){
            if(visited[i]==0){
                visited[i]=++cnt;
                q.push(i);
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m,r;
    cin>>n>>m>>r;

    visited.resize(n+1,0);
    graph.resize(n+1);

    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<n+1;i++){
        sort(graph[i].begin(),graph[i].end());
    }

    bfs(r);//여기에 왜 1을 넣었는지;;; 입력 받은대로 시작 정점 r에서 시작한다
    for(int i=1;i<n+1;i++){
        cout<<visited[i]<<"\n";
    }
    
    return 0;
}