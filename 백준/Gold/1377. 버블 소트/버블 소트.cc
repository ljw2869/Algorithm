#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define endl '\n'

// void swap(int &a,int &b){
//     int temp=a;
//     a=b;
//     b=temp;
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    // int N;
    // cin >> N;
    // int *arr=new int[N+1];

    // for(int i=1;i<=N;i++){
    //     cin>>arr[i];
    // }
    // bool change =false;
    // for(int i=1;i<=N+1;i++){
    //     change=false;
    //     for(int j=1;j<=N-i;j++){
    //         if(arr[j]>arr[j+1])
    //         {
    //             change = true;
    //             swap(arr[j],arr[j+1]);
    //         }
    //     }
    //     if(change==false){
    //         cout<<i<<endl;
    //         break;
    //     }
    // }
    // 위와 같이 문제에서 주어진 대로 구현하면 시간복잡도가 O(N^2)이다.
    // 하지만 이 문제는 O(NlogN)으로 해결할 수 있어야 한다.
    
    int N;

    cin>>N;
    vector<pair<int,int>>A(N);

    for(int i=0;i<N;i++){
        cin>>A[i].first;
        A[i].second=i;
    }

    sort(A.begin(),A.end()); //이렇게 정렬을 하면 A[i].first는 오름차순으로 정렬되고, A[i].second는 원래 인덱스가 저장된다.
    int MAX=0;
    for(int i=0;i<N;i++){
        if(A[i].second-i>MAX)
            MAX=A[i].second-i;
    }
    cout<<MAX+1<<endl;

    // 이 문제의 원리는 가장 많이 swap이 된 횟수+1만큼이 이론적으로 마지막으로 정렬을 한 i번째 횟수를 출력하게 되는 것이다.
    // 그 i를 구하기 위해 정말 버블정렬을 가지고 풀면 시간 안에 풀수 없고 
    // 정렬로 nlogn으로 풀고 난 후 배열 중에서 가장 많이 인덱스가 바뀐 만큼 swap이 일어나는 것이라서 최종적으로 한바퀴 더 돌아 마지막이라는 것을 확인하는 +1을 해주는 것이 해답이 된다.
    return 0;
}