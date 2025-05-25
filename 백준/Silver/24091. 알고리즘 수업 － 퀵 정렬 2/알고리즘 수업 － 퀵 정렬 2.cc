#include<iostream>
#include<vector>

using namespace std;
#define endl '\n'


int K;
int cnt=0;

void swap(vector<int>&A,int S,int E){
    int temp=A[S];
    A[S]=A[E];
    A[E]=temp;
    cnt++;
    if(cnt==K){
        for(int idx=0;idx<A.size();idx++){
            cout<<A[idx]<<" ";
        }
        exit(0);
    }

}

int partition(vector<int>&A,int S,int E){
    int pivot=A[E];
    int i=S-1;
    for(int j=S;j<E;j++){
        if(A[j]<=pivot)
            swap(A,++i,j);
    }
    if(i+1!=E)
        swap(A,i+1,E);
    return i+1;
}


void quick_sort(vector<int>&A,int S,int E){
    if(S<E){
        int q=partition(A,S,E);//분할
        quick_sort(A,S,q-1);//왼쪽 부분 배열 정렬
        quick_sort(A,q+1,E);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin>>N>>K;

    vector <int> A(N,0);    
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    quick_sort(A,0,N-1);//k번 교환한 직후의 배열A를 출력
    cout<<"-1"; // K번 교환이 이루어지지 않은 경우 -1 출력
    return 0;
}