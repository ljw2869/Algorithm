#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>>graph;
vector<vector<int>>dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    graph.resize(n,vector<int>(m));
    dp.resize(n,vector<int>(m,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int num;
            cin>>num;
            graph[i][j]=num;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0&&j==0)
                dp[i][j]=graph[i][j];
            if(i>0&&j>0){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+graph[i][j]);
            }
            if(i>0){
                dp[i][j]=max(dp[i][j],dp[i-1][j]+graph[i][j]);
            }
            if(j>0){
                dp[i][j]=max(dp[i][j],dp[i][j-1]+graph[i][j]);
            }
        }
    }
    
    cout<<dp[n-1][m-1]<<"\n";

    return 0;
}

