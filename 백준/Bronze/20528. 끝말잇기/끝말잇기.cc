#include<iostream>
#include<string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int n,flag=1;
    cin>>n;
    string s;
    char start;
    for(int i=0;i<n;i++){
        cin>>s;
        if(i==0){
            start=s[0];
        }
        else{
            if (s[0]!=start){
                cout<<0; 
                flag=0;
                break;
            }
            else
                continue;
        }
    }
    if(flag)
        cout<<1;

    return 0;
}

