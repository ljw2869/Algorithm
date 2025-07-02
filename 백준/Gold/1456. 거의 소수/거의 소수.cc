#include<iostream>
#include<cmath>
using namespace std;
long A[10000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //10^14의 범위까지의 거의 소수를 판단한다는 것은 최대 10^7까지의 소수만 구하면 제곱해서 판별하기 때문에 10^7까지만 구한다
    long a,b;
    cin>>a>>b;

    //소수 구하기
    for(int i=2;i<10000001;i++){
        A[i]=i;//일단 배열을 2부터 시작해서 자신의 값을 가지고 있는 것으로 초기화
    }
    // 에라토스테네스의 체를 이용해서 소수 구하기
    for(int i=2;i<=sqrt(10000001);i++){
        if(A[i]==0)
            continue;//소수가 아니라면 0으로 설정해놓을 것이라서 이전 수에서 처리가 된, 소수가 아닌 수는 건너뛴다
        for(int j=i+i;j<10000001;j+=i){
            A[j]=0;//j를 i+i로 시작하는 이유는 자기 자신은 소수이기 때문에 0으로 바꾸면 안되기 때문
        }
    }

    //소수의 n제곱(거의 소수)구하기
    //이때 long long 타입으로 쓰지 않으려면 그냥 이항정리로 b에 k의 n-1제곱을 나누어주면 된다
    int cnt=0;
    for(int i=2;i<10000001;i++){
        if(A[i]!=0)
        {
            long temp=A[i];
            while(double(A[i])<=double(b)/double(temp))
            {
                if(double(A[i])>=double(a)/double(temp))
                {
                    cnt++;
                }
                temp=temp*A[i];
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}