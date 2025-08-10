#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static int N,K;
vector<vector<int>>dp;
vector<pair<int,int>>bag_list;

int DP(int n,int k);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>N>>K;
    bag_list.resize(N+1);
    dp.assign(N+1,vector<int>(K+1,-1));//모든 값을 -1로 초기화

    int a,b;
    for(int i=1;i<=N;i++)
    {
        cin>>a>>b;
        bag_list[i]={a,b};//w,v
    }
    DP(N,K);
    cout<<dp[N][K];

    return 0;
}

int DP(int n,int k)
{
    if(n<=0||k<=0) 
        return 0;
    if(dp[n][k]!=-1)//메모이제이션 조건 추가
        return dp[n][k];
    //n번재 아이템을 안 넣는 경우
    int notTake=DP(n-1,k);
    //n번째 아이템을 넣는 경우
    int take=0;
    if(k>=bag_list[n].first)
        take=DP(n-1,k-bag_list[n].first)+bag_list[n].second;
    return dp[n][k]=max(take,notTake);
}
