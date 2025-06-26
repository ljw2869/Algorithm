#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int n,m,q;
    cin>>n>>m>>q;
    vector<int>a(n,0),b(m,0);
    int type,r,c,v;
    for(int i=0;i<q;i++){
        cin>>type;
        if(type==1){
            cin>>r>>v;
            a[r-1]+=v;
        }
        else{
            cin>>c>>v;
            b[c-1]+=v;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i]+b[j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

