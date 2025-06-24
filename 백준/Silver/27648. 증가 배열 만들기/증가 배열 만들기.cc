#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int a,b,c;
    cin >> a>>b>>c;
    if(a+b-1<=c){
        cout<<"YES\n";
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                cout<<i+j+1<<" ";
            }
            cout<<"\n";
        }
    }
    else{
        cout<<"NO\n";
    }

    return 0;
}

