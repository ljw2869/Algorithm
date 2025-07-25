#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 987654321
vector<vector<pair<int,int>>>graph;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n,m,start;
    cin>>n>>m;
    graph.resize(n+1);
    cin>>start;

    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        graph[u].push_back({v,w});//그래프에는 그냥 연결 노드, 간선 가중치 순서로 들어감
    }

    vector<int> distance(n+1,INF);
    distance[start]=0;//시작점은 0으로 초기화
    pq.push(make_pair(0,start)); //우선순위 큐에 가중치가 먼저 쌍의 첫번째 원소로 들어가야 가중치 작은 순으로 들어감

    while(!pq.empty()){

        int cost=pq.top().first;//가중치
        int cur=pq.top().second;//현재 지나가는 노드의 번호

        pq.pop();

        // if(cost>distance[cur])continue;
        //현재 노드의 최소 경로가 이전에 다른 노드에 의해 갱신된 경우 현재의 최소비용을 쓰지 말아야 하기 때문에(이미 작아서 아래 코드로 갱신할 필요 없음) 넘어간다

        for(int i=0;i<graph[cur].size();i++)//현재의 노드와 그래프에 연결된 노드들을 탐색
        {
            int weight=graph[cur][i].second;//그래프의 연결된 가중치
            int next=graph[cur][i].first;//그래프에 연결된 다음 노드의 번호
            
            if(cost+weight<distance[next])
            {
                distance[next]=cost+weight;
                pq.push(make_pair(cost+weight,next));
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(distance[i]==INF)
            cout<<"INF"<<"\n";
        else
            cout<<distance[i]<<"\n";
    }

    
    
    return 0;
}

