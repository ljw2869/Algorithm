#include<iostream>
#include<vector>
#include<algorithm>

#define INF 987654321
using namespace std;
int graph[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
                graph[i][j]=INF;
            else
                graph[i][j]=0;
        }
        
    }

    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }

    for(int k=1;k<=n;k++)
    {
        for(int s=1;s<=n;s++)
        {
            for(int e=1;e<=n;e++)
            {
                graph[s][e]=min(graph[s][e],graph[s][k]+graph[k][e]);
            }
        }
    }
    int MIN=INF,idx=-1;
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            cnt+=graph[i][j];
        }
        if(MIN>cnt){
            MIN=cnt;
            idx=i;
        }
    }
    cout<<idx<<"\n";

    
    return 0;
}