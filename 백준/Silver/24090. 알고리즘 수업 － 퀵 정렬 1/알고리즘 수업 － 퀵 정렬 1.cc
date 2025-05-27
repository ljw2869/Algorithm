#include<iostream>
#include<vector>

using namespace std;
#define endl '\n'

void quick_sort(vector<int>&A,int S,int E,int K);
int partition(vector<int>&A,int S,int E,int K);
void swap(vector<int>&A,int a,int b);

int cnt=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,K;
    cin>>N>>K;

    vector<int>A(N,0);
    for(int i=0;i<N;i++)
        cin>>A[i];
    quick_sort(A,0,N-1,K);
    cout<<"-1"<<endl;
    return 0;
}

void swap(vector<int>&A,int a,int b){
    int temp=A[a];
    A[a]=A[b];
    A[b]=temp;
    //cout<<"SWAP RESULT: "<<A[a]<<" "<<A[b]<<endl;
}

int partition(vector<int>&A,int S,int E,int K){
    int pivot=A[E];
    int i=S-1;
    for(int j=S;j<E;j++){
        if(A[j]<=pivot){
            swap(A,++i,j);
            cnt++;

            if(cnt==K){
                cout<<A[i]<<" "<<A[j]<<endl;
                exit(0);
                return -100;
            }
        }
    }
    if(i+1!=E){
        swap(A,i+1,E);
        cnt++;

        if(cnt==K){
            cout<<A[i+1]<<" "<<A[E]<<endl;
            exit(0);
            return -100;
        }
    }
    return i+1;
}

void quick_sort(vector<int>&A,int S,int E,int K){
    if(S<E){
        int q=partition(A,S,E,K); 
        if(q==-100) return; // If we found the K-th swap, exit early
        quick_sort(A,S,q-1,K); 
        quick_sort(A,q+1,E,K);
    }

}

