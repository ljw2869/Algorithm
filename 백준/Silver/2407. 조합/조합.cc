#include<iostream>
using namespace std;

string arr[105][105];//각 위치에 조합의 값을 저장하는 문자열 배열

string add(string num1,string num2)
{
    string num="";
    int sum=0;
    int size=max(num1.size(),num2.size());

    for(int i=0;i<size||sum;i++)
    {
        if(num1.size()>i)sum+=num1[i]-'0';
        if(num2.size()>i)sum+=num2[i]-'0';

        num+=sum%10+'0';
        sum/=10;
    }
    return num;
}

string combination(int n,int m)
{
    string &ans=arr[n][m];//참조 연산자 사용으로 arr[n][m]에, 나중에 add한 결과를 받아서 저장이 됨
    //reference로 별도의 대입 코드 없이 메모이제이션 배열이 채워지는 구조, 별도의 복사 없이 배열의 값을 직접 조작하기 때문에 ans수정시 배열 값이 수정됨
    if(n==m||m==0)
    {
        ans="1";
        return ans;
    }
    if(ans!="")
        return ans;//만약 저장되어 있다면 그대로 문자열 반환
    ans=add(combination(n-1,m-1),combination(n-1,m));
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;
    combination(n,m);
    for(int i=arr[n][m].size()-1;i>=0;i--)
        cout<<arr[n][m][i];

    return 0;
}

