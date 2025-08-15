#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[51][51][51]={{{0},},};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    

    for(int i=0;i<51;i++)
    {
        for(int j=0;j<51;j++)
        {
            for(int k=0;k<51;k++)
            {
                if(i<=0||j<=0||k<=0)
                    dp[i][j][k]=1;
                else if(i>20||j>20||k>20)
                    dp[i][j][k]=dp[20][20][20];
                else if(i<j&&j<k)
                {
                    dp[i][j][k]=dp[i][j][k-1]+dp[i][j-1][k-1]-dp[i][j-1][k];
                }
                else
                    dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k]+dp[i-1][j][k-1]-dp[i-1][j-1][k-1];
            }
        }
    }

    int a=1,b=1,c=1;
    
    while(a!=-1||b!=-1||c!=-1){
        cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1)
            break;
        if(a<=0||b<=0||c<=0)
            cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<dp[0][0][0]<<"\n";
        else if(a>20||b>20||c>20)
            cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<dp[20][20][20]<<"\n";
        else
            cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<dp[a][b][c]<<"\n";
    }
    
    return 0;
}

