#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 987654321

int value[1001];
int graph[1001][1001];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//pair중에서 첫번째 값이 작은 순으로 우선순위큐가 만들어진다.

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        value[i]=INF;
        for(int j=1;j<=n;j++){
            graph[i][j]=INF;
        }
        graph[i][i]=0;
    }

    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        if(graph[u][v]>w){
            graph[u][v]=w;
        }
    }

    int s,e;
    cin>>s>>e;
    value[s]=0;

    pq.push(make_pair(0,s));

    while(!pq.empty()){
        int cost=pq.top().first;//첫번째 값에 가중치가 저장되어 있음
        int node=pq.top().second;//최소 가중치를 가지는 노드의 번호
        pq.pop();

        for(int i=1;i<=n;i++)
        {
            int w=graph[node][i];//node와 연결된 간선의 가중치
            if(w==INF)continue;//연결되어 있지 않다면 넘어가기
            if(cost+w<value[i])//만약 node를 거쳐 가는 경로가 다익스트라 값을 저장하는 value값보다 작다면 업데이트
            {
                value[i]=cost+w;
                pq.push(make_pair(cost+w,i)); //값이 업데이트되었다면 우선순위 큐에 넣어서 나중에 검토
            }
        }
    }
    cout<<value[e]<<"\n";
    return 0;
}

