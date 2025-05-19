#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<int> a(n);

    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> c(n);
    for (int i=0;i<n;i++){
        if (i>=1){
            c[i]=a[i]+c[i-1];
        }
        else{
            c[i]=a[i];
        }
    }


    for (int i=0;i<m;i++){
        int r,l;
        cin>>r>>l;
        if (r>=2)
            cout<<c[l-1]-c[r-2]<<endl;
        else
            cout<<c[l-1]<<endl;
    }
    return 0;
}