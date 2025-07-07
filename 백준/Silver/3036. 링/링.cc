#include<iostream>
#include<vector>

using namespace std;

int gcd(int a,int b)//유클리드 호제법(뒤에 있는 수가 작은 수라고 약속한다)
{
    if(b==0){ //이전 재귀에서 나누어 떨어지게 된 a%b는 이때의 b를 가져와야 함으로 (현재의 a)return a를 해준다
        return a;
    }
    return gcd(b,a%b); //mod연산을 하게 되면 당연히 b보다 작은 값이 나오기 때문에 재귀로 넣을 때는 두번째 매개변수에 넣어주게 된다
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    
    vector<int>circle(n,0);
    int first;
    for(int i=0;i<n;i++){
        if(i==0){
            cin>>first;
        }
        else{
            cin>>circle[i];
        }
    }
    //각 배열의 최대 공약수를 구한 후 first와 각 원의 지름에 최대공약수를 나누어서 출력한다
    for(int i=1;i<n;i++){
        int greatest_common_divisor=gcd(first,circle[i]);
        cout<<first/greatest_common_divisor<<"/"<<circle[i]/greatest_common_divisor<<"\n";
    }
    return 0;
}