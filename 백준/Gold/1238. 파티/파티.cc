#include<iostream>
#include<vector>
#include<queue>

#define INF 987654321

using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq2;
vector<pair<int,int>>graph[2][1001];

vector<int>s2e_distance;
vector<int>e2s_distance;
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n,m,x;
    cin>>n>>m>>x;//n은 전체 노드의 개수, m은 간선의 개수, x는 시작점


    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[0][a].push_back(make_pair(b,c));
        graph[1][b].push_back(make_pair(a,c));
    }

    s2e_distance.resize(n+1,INF);
    e2s_distance.resize(n+1,INF);

    s2e_distance[x]=0;
    e2s_distance[x]=0;

    pq.push({0,x});
    while(!pq.empty())
    {
        int cur=pq.top().second;//방문하지 않은 최소 거리를 가진 노드
        int cost=pq.top().first;//가중치

        pq.pop();
        if(cost>s2e_distance[cur])continue;

        for(int i=0;i<graph[0][cur].size();i++)
        {
            int node=graph[0][cur][i].first;//연결 노드의 번호
            int weight=graph[0][cur][i].second;//연결 간선의 가중치

            if(cost+weight<s2e_distance[node]){
                s2e_distance[node]=cost+weight;
                pq.push({cost+weight,node});
            }
        }
    }

    pq2.push({0,x});
    while(!pq2.empty())
    {
        int cur=pq2.top().second;//방문하지 않은 최소 거리를 가진 노드
        int cost=pq2.top().first;//가중치

        pq2.pop();
        if(cost>e2s_distance[cur])continue;

        for(int i=0;i<graph[1][cur].size();i++)
        {
            int node=graph[1][cur][i].first;//연결 노드의 번호
            int weight=graph[1][cur][i].second;//연결 간선의 가중치

            if(cost+weight<e2s_distance[node]){
                e2s_distance[node]=cost+weight;
                pq2.push({cost+weight,node});
            }
        }
    }

    int max=0;
    for(int i=1;i<=n;i++)
    {
        if(max<s2e_distance[i]+e2s_distance[i])
        {
            max=s2e_distance[i]+e2s_distance[i];   
        }
    }
    cout<<max<<"\n";
    
    return 0;
}

