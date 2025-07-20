#include<iostream>
#include<vector>

using namespace std;

vector<int>parent;

int FIND(int a){
    while (a!=parent[a])
        a=parent[a];
    return a;
}

bool UNION(int a,int b)
{
    a=FIND(a);
    b=FIND(b);

    if(a==b){
        return true;
    }
    else if(a<b){
        parent[b]=a;
        return false;
    }
    else{
        parent[a]=b;
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    parent.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }

    int a,b;
    bool result=false;
    bool flag=false;
    for(int i=0;i<m;i++){
        cin>>a>>b;

        result=UNION(a,b);
        if(result){ 
            cout<<i+1<<"\n";
            return 0; 
        }
    }
    cout<<0<<"\n";
    
    return 0;
    
}



