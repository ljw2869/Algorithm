#include<iostream>
#include<vector>
#include<queue>

#define INF 987654321
using namespace std;

int node[1005][1005]={INF,};
priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;

int Ddist[1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            node[i][j]=INF;
    }
    for(int i=1;i<=n;i++){
        node[i][i]=0;
        Ddist[i]=INF;
    }

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(node[u][v]>w){//여기가 핵심!! 두 노드 사이 여러 개의 간선이 연결될 수 있는데 최솟값만을 저장함
            node[u][v]=w;
        }
    }

    int start,end;
    cin>>start>>end;

    Ddist[start]=0;

    pq.push(make_pair(0,start));//각 쌍은 {가중치(거리), 노드}로 저장되어 있음

    while(!pq.empty()){
        //최소거리x와 그때의 노드 번호U
        int x=pq.top().first;
        int U=pq.top().second;
        pq.pop();

        //이 노드에서 나가는 간선들을 확인한 후 그 간선에 연결된 노드들의 최소거리를 업데이트
        for(int i=1;i<=n;i++){ 
            int W=node[U][i]; //그래프에서의 간선 가중치

            if(W==INF)
                continue;//볼 가치 없이 건너뛰기
            
            if(x+W<Ddist[i]){
                Ddist[i]=x+W;
                pq.push(make_pair(x+W,i));
            }
        }
    }
    cout<<Ddist[end]<<"\n";
    
    return 0;
}

