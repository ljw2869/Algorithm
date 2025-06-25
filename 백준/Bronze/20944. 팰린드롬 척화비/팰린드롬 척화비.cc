#include<iostream>
#include<string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;
    std::string s(n,'a'); //std::string(length,char)생성자는 length만큼char 를 반복해서 문자열을 만들어준다
    cout<<s;

    return 0;
}

