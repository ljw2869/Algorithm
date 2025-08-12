#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static vector<long>fin;

long fibonacci(int n)

{
    fin[0]=fin[1]=1;

    for(int i=2;i<=n;i++)
    {
        fin[i]=fin[i-1]+fin[i-2];
    }
    return fin[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    

    fin.resize(42);
    int n;
    cin>>n;
    cout<<fibonacci(n);

    return 0;
}

