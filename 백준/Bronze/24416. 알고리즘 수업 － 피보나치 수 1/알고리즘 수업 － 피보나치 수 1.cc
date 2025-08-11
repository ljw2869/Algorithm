#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static vector<long>fin;
static int result1=0;
static int result2=0;

long fibR(int n)
{
    if(n==1 ||n==2)
    {
        result1++;
        return 1;
    }
    else
        return (fibR(n-1)+fibR(n-2));
}

long fibonacci(int n)
//문제에 나와있는 수도코드 그대로 작성-
//메모이제이션이 필요없는 이유는 이 문제에서는 단순히 하나의 값만 물어보기 때문에 n까지만 만들고 종료하면 됨
//만약 여러번 물어보는 문제라면 dp배열 값이 이미 저장된 값이 있는지 확인하는 코드가 필요할 듯
{
    fin[1]=fin[2]=1;

    for(int i=3;i<=n;i++)
    {
        fin[i]=fin[i-1]+fin[i-2];
        result2++;
    }
    return fin[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    

    fin.resize(42);
    int n;
    cin>>n;
    fibR(n);
    fibonacci(n);
    cout<<result1<<" "<<result2;

    return 0;
}

