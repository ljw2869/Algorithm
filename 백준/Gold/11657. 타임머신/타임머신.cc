#include<iostream>
#include<vector>

#define INF 987654321
using namespace std;

vector<long long> dist;
//node 1<=N<=500, edge 1<=M<=6000, weight -10000<=W<=10000
//total distance could be over "int" range

struct Edge{
    int start;
    int end;
    int weigth;
};

vector<Edge>graph;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    int a,b,c;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        graph.push_back({a,b,c});
    }

    dist.resize(n+1,INF);
    dist[1]=0;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<graph.size();j++)
        {
            int s=graph[j].start;
            int e=graph[j].end;
            int w=graph[j].weigth;

            if(dist[s]==INF)continue;//이미 시작 값이 정해져 있지 않다면 업데이트 불가능 하니 넘어가기
            if(dist[s]+w<dist[e])
            {
                dist[e]=dist[s]+w;//update
            }
        }
    }

    //음수 사이클 판별로 1번만 더 돌리기

    for(int j=0;j<graph.size();j++)
    {
        int s=graph[j].start;
        int e=graph[j].end;
        int w=graph[j].weigth;

        if(dist[s]==INF)continue;//이미 시작 값이 정해져 있지 않다면 업데이트 불가능 하니 넘어가기
        if(dist[s]+w<dist[e])
        {
            cout<<-1<<"\n";
            return 0;
        }
    }


    //print result
    for(int i=2;i<=n;i++)
    {
        if(dist[i]==INF){
            cout<<-1<<"\n";
        }
        else{
            cout<<dist[i]<<"\n";
        }
    }
    

    return 0;
}