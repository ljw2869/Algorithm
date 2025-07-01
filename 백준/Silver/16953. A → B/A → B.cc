#include<iostream>

#include<queue>
using namespace std;

#define endl '\n'
typedef pair<long long int, int> node;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int a,b;
    cin>>a>>b;
    int result=1;//이게 결과값
    //b에서 a로 내려가면서 만들수 있으면 출력하는 과정을 반복-그리디
    //b에서 a로 내려가는 과정이면 계산하는 과정에서 int자료형의 범위를 벗어나는 경우가 없다
    while(true){
        if(a==b){
            break;
        }
        else if(a>b){
            cout<<-1<<endl;
            return 0;
        }
        
        if(b%2==0){
            b/=2;
        }
        else if(b%10==1){
            b=(b-1)/10;
        }
        else{
            cout<<-1<<endl;
            return 0;
        }
        result++;
    }
    cout<<result<<endl;
    return 0;
}