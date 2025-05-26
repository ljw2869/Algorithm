#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,L;

    cin>>N>>L;

    vector<int>A(N,0);
    vector<bool>covered(1001,true);


    for(int i=0;i<N;i++){
        cin>>A[i];
        covered[A[i]]=false;
    }
    sort(A.begin(),A.end());


    int cnt=0,result=0;
    int idx=A[cnt];
    while(idx<1001&&cnt<N){
        if(covered[idx]==false){
            covered[idx]=true;
            result++;
            while(A[cnt]<idx+L&&cnt<N){
                covered[A[cnt]]=true;
                cnt++;
            }
            idx=A[cnt];
        }
        else
            idx=A[cnt++];//상황을 잘 구분해야 하는게, 그냥 else를 안하면 다음 idx를 검사안하고 하나 건너 뛰는 문제가 발생
    }
    cout<<result<<endl;
    return 0;
}

