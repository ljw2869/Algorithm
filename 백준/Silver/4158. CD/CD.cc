#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(true){
        int n,m;
        cin>>n>>m;
        if(n==0&&m==0) break;
        vector<int>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        vector<int>b(n);
        for(int i=0;i<m;i++)
            cin>>b[i];

        int idx1=0,idx2=0;
        int cnt=0;
        while(idx1<n&&idx2<m){
            if(a[idx1]==b[idx2]){
                cnt++;
                idx1++;
                idx2++;
            }
            else if(a[idx1]<b[idx2]){
                idx1++;
            }
            else{
                idx2++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}