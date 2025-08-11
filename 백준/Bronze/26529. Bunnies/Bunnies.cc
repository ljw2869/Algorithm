#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long>fin;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    

    fin.resize(46);
    fin[0]=1;
    fin[1]=1;
    for(int i=2;i<46;i++)
    {
        fin[i]=fin[i-1]+fin[i-2];
    }
        
    int n;
    cin>>n;
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        cout<<fin[a]<<"\n";
    }

    return 0;
}

