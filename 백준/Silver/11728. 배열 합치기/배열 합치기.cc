#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    cin>>N>>M;

    vector<int> A(N),B(M);

    for (int i=0;i<N;i++)
        cin>>A[i];
    for(int i=0;i<M;i++)
        cin>>B[i];

    vector<int>C(N+M);
    int s1=0,s2=0;
    int index=0;

    while(index<N+M){
        if(s1<N&&s2<M){
            if(A[s1]<B[s2]){
                C[index++]=A[s1++];
            }
            else{
                C[index++]=B[s2++];
            }
        }
        else if(s1==N)
            C[index++]=B[s2++];
        else
            C[index++]=A[s1++];
    }

    for(int i=0;i<index;i++)
        cout<<C[i]<<" ";
    cout<<endl;


    return 0;
}