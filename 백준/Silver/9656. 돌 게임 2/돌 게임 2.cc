#include<iostream>

using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    if(n%2==1)
        cout<<"CY"<<endl;
    else
        cout<<"SK"<<endl;
    
    return 0;
}