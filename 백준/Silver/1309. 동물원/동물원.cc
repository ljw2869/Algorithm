#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[100000]={0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    

    int n;
    cin>>n;
    dp[0]=1;dp[1]=3;dp[2]=7;
    for(int i=3;i<n+1;i++)
    {
        dp[i]=(2*dp[i-1]+dp[i-2])%9901;
    }
    cout<<dp[n]<<"\n";
    
    
    
    return 0;
}

