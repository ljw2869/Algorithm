#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'

using namespace std;
static int cnt;
static vector<int> visited;

void DFS(int start, vector<vector<int>>&graph);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,M,R,u,v;
    cin>>N>>M>>R;

    vector<vector<int>> graph(N+1);
    visited.resize(N+1,0);

    for(int i=0;i<M;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1;i<=N;i++){
        sort(graph[i].begin(),graph[i].end());
    }

    cnt=0;
    visited[R]=++cnt;
    DFS(R,graph);

    for(int i=1;i<N+1;i++){
        cout<<visited[i]<<endl;
    }
    
    return 0;
}

void DFS(int start, vector<vector<int>>&graph)
{
    for (int i:graph[start]){
        if(visited[i]==0){
            visited[i]=++cnt;
            DFS(i,graph);
        }
    }
}