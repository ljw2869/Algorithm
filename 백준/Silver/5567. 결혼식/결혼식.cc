#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>>graph;
vector<bool>visited;
int cnt=0;

void bfs(int start){
    queue<pair<int,int>>q;
    visited[start]=true;
    q.push({start,0});

    while(!q.empty()){
        pair<int,int> top=q.front();
        q.pop();
        for(int i:graph[top.first]){
            if(top.second<2&&!visited[i]){
                q.push({i,top.second+1});
                visited[i]=true;
                cnt++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;

    cin>>n>>m;
    graph.resize(n+1);
    visited.resize(n+1,false);

    int a,b;
 
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);
    cout<<cnt;
    
    return 0;
}