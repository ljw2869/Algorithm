#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long N;
    cin>>N;
    long result=N;//실제 자신의 값으로 초기화 해주기
    
    //오일러 피 문제
    for(long p=2;p<=sqrt(N);p++){
        if(N%p==0){
            result=result-result/p;
        }
        while(N%p==0){
            N=N/p;
        }
    }
    if(N>1){
        result=result-result/N;//제곱근보다 큰 약수를 다루지 않고 빠져 나온 경우 마지막으로 나누어 주어야 할 소인수가 N에 있기 때문에 마지막에 나누어주면 됨
    }//예시로 10의 결과는 제곱근이 3 정도라 2만 나누고 N은 5가 될 것이기에 1이 아닌 N은 마지막에 한번 나누어준다
    cout<<result;
    return 0;
}