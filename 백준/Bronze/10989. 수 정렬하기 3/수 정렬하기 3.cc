#include<iostream>

using namespace std;
#define endl '\n'

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int count[10001]={0};

    int number=0;

    for(int i=0;i<n;i++){
        cin>>number
        ;
        count[number]++;
    }

    for(int i=0;i<10001;i++){
        if(count[i]!=0){
            for(int j=0;j<count[i];j++)
            {
                cout<<i<<endl;
            }
        }
    }

    return 0;
}