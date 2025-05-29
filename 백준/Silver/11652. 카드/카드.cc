#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;

    vector<long long> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());

    int max=0;
    int cnt=0;
    long long result=A[0];
    for(int i=0;i<N-1;i++)
    {
        if(A[i]==A[i+1])cnt++;
        else{
            cnt=0;
        }
        if(cnt>max)
        {    
            max=cnt;
            result=A[i];
        }
    }
    cout<<result<<endl;
    return 0;
}