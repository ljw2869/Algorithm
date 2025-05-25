#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;
#define endl '\n'

void swap(vector<int>&A,int S,int E)
{
    int temp=A[S];
    A[S]=A[E];
    A[E]=temp;
}

int partition(vector<int>&A,int S,int E){
    if(S+1==E){//2개만 있어서 정렬을 궂이 하지 않아도 될 때
        if(A[S]>A[E]){
            swap(A[S],A[E]);
        }
        return E;
    }
    //중간을 피벗으로 설정
    int M=(S+E)/2;
    swap(A,S,M);
    int pivot=A[S];
    int i=S+1;
    int j=E;
    while(i<=j){
        while(pivot<A[j]&&j>0) j--;
        while(pivot>A[i]&&i<A.size()-1)i++;
        if(i<=j) swap(A,i++,j--);
    }
    A[S]=A[j];//j는 항상 피벗보다 작은 값이므로
    //피벗을 j위치로 이동
    A[j]=pivot;
    return j;//피벗의 위치를 반환
}

void quick_sort(vector<int>& A, int S,int E,int K){
    int pivot=partition(A,S,E);
    //재귀적으로 퀵정렬을 돌리며 정렬
    if (pivot==K){
        return;
    }
    else if(K<pivot){
        quick_sort(A,S,pivot-1,K);
    }
    else{
        quick_sort(A,pivot+1,E,K);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,K;
    cin>>N>>K;

    vector <int>A(N,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    quick_sort(A,0,N-1,K-1);
    cout<<A[K-1]<<endl;

    
    return 0;
}