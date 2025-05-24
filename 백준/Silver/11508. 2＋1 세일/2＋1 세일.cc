#include<iostream>
#include<algorithm>
#include<vector>

#include<cmath>
using namespace std;
#define endl '\n'

bool compare(int i,int j){// greater<int> is used to sort in descending order
    return i>j; // this function is used as "sort(A.begin(),A.end(),compare);"
}

int main(){


    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;

    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    int res=0;
    if (N==1){
        res=A[0];
    }
    else if (N==2){
        res=A[0]+A[1];
    }
    else{
        sort(A.begin(),A.end(),greater<int>());
        for(int i=0;i<N;i++){
            if (i%3==2)
                continue;
            else
                res+=A[i];
        }
    }
    cout<<res<<endl;
    return 0;
}