#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static vector<long>finA;
static vector<long>finB;

long fiba(int n)

{
    finA[0]=1;
    finA[1]=0;

    for(int i=2;i<=n;i++)
    {
        finA[i]=finA[i-1]+finA[i-2];
    }
    return finA[n];
}
long fibb(int n)

{
    finB[0]=0;
    finB[1]=1;

    for(int i=2;i<=n;i++)
    {
        finB[i]=finB[i-1]+finB[i-2];
    }
    return finB[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    

    finA.resize(46);
    finB.resize(46);
    int n;
    cin>>n;
    cout<<fiba(n)<<" "<<fibb(n);

    return 0;
}

