#include<iostream>
#include<vector>

#define INF 987654321
using namespace std;

int graph[51][51];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    char tmp;
    //그래프 입력받기 및 초기화
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>tmp;
            if(i==j)
            {
                graph[i][j]=0;
                continue;
            }
            else if(tmp=='Y'){
                graph[i][j]=1;
            }
            else{
                graph[i][j]=INF;
            }
        }
    }

    //플로이드 워셜로 친구 관계를 최단거리로 저장하기
    for(int k=0;k<n;k++)
    {
        for(int s=0;s<n;s++)
        {
            for(int e=0;e<n;e++)
            {
                if(graph[s][e]>graph[s][k]+graph[k][e])
                    graph[s][e]=graph[s][k]+graph[k][e];
            }
        }
    }
    int Max=0;
    for(int i=0;i<n;i++)
    {
        int total=0;
        for(int j=0;j<n;j++)
        {
            if(graph[i][j]==1||graph[i][j]==2)
                total++;
        }
        if(Max<total)
            Max=total;
    }
    cout<<Max<<"\n";

    
    return 0;
}