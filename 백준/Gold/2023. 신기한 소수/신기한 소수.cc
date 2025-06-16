#include<iostream>

using namespace std;
#define endl '\n'


void DFS(int number,int jarisu);
bool isPrime(int number);

static int N;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    DFS(2,1); //첫번째 파라미터는 시작 소수, 두번째 파라미터는 해당 소수의 자리수
    DFS(3,1);
    DFS(5,1);
    DFS(7,1);
    
    return 0;
}

void DFS(int number,int jarisu){
    if (jarisu==N)
    {
        if(isPrime(number))
        {
            
            cout<<number<<endl;
        }
        return;
    }
    for(int i=1;i<=9;i+=2)
    {
        if(i==5) continue; // 5는 제외
        if(isPrime(number*10+i)){
            DFS(number*10+i,jarisu+1);
        }
    }
}

bool isPrime(int number){
    for(int i=2;i<=number/2;i++)
    {
        if(number%i==0)
            return false;
    }
    return true;
}