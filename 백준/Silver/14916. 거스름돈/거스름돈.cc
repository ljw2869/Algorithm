#include<iostream>
#define MAX 100010
#define endl "\n"

using namespace std;

int n,answer;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    

    int n;
    cin>>n;
    if(n==1||n==3) //다음의 경우는 두가지의 동전으로 거스름돈을 줄 수 없는 유일한 경우
    {
        cout<<-1<<endl;
        return 0;
    }
    if(n%5==0)
    {
        cout<<n/5<<endl;
        return 0;
    }
    int five=n/5;
    n%=5;
    if(n%2==0)
    {
        cout<<five+n/2<<endl;
    }
    else{//만약 n이 홀수라면 5를 더해서 짝수로 만들고, 5원으로 거스르는 것을 하나 빼서 2원으로 거슬러준다
        five--;
        n+=5;
        cout<<five+n/2;
    }

    
    
    return 0;
}

