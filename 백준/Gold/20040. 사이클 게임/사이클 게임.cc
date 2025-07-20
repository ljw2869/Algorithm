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
        if(result&&!flag){ //계속 그래프를 그리면서 그 이후에도 사이클이 생기도록 입력을 받았을 때 계속 출력을 하면 안되고 처음으로 사이클이 생긴 부분에서만 출력해야 함!!!(출력 초과 문제)
            cout<<i+1<<"\n";
            flag=true;
        }
    }
    if(flag==false)
        cout<<0<<"\n";
    
    return 0;
    
}



