#include<iostream>
#include<vector>
#include<queue>
#define INF 100000000

using namespace std;

vector<vector<pair<int,int>>>graph;
vector<int>D[2];

void Dijkstra(int v1,int v2)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq2;
    D[0][v1]=0;
    pq1.push({0,v1});
    while(!pq1.empty())
    {
        int cur=pq1.top().second;
        int cost=pq1.top().first;

        pq1.pop();
        for(int i=0;i<graph[cur].size();i++)
        {
            int next=graph[cur][i].first;
            int weight=graph[cur][i].second;

            if(D[0][next]>cost+weight)
            {
                D[0][next]=cost+weight;
                pq1.push({cost+weight,next});
            }
        }
    }


    D[1][v2]=0;
    pq2.push({0,v2});
    while(!pq2.empty())
    {
        int cur=pq2.top().second;
        int cost=pq2.top().first;

        pq2.pop();
        for(int i=0;i<graph[cur].size();i++)
        {
            int next=graph[cur][i].first;
            int weight=graph[cur][i].second;

            if(D[1][next]>cost+weight)
            {
                D[1][next]=cost+weight;
                pq2.push({cost+weight,next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,e;
    cin>>n>>e;
    graph.resize(n+1);

    int a,b,c;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});//양방향 그래프
    }

    int v1,v2;
    cin>>v1>>v2;
    D[0].resize(n+1,INF); 
    D[1].resize(n+1,INF); 

    Dijkstra(v1,v2);

    int v1tov2=D[0][1]+D[1][n]+D[0][v2];
    int v2tov1=D[1][1]+D[0][n]+D[0][v2];

    if(v1tov2>=INF||v2tov1>=INF){
        cout<<-1<<"\n";
        return 0;
    }
    if(v1tov2>v2tov1)
    {
        cout<<v2tov1<<"\n";
    }
    else{
        cout<<v1tov2<<"\n";
    }

    return 0;
}