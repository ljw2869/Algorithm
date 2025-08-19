#include<iostream>
#include<vector>
#define endl "\n"

using namespace std;

static int n,m;
static vector<int>A;
static vector<bool>v;

void backtracking(int length);
void print();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    A.resize(m,0);
    v.resize(n,false);

    backtracking(0);
    
    
    return 0;
}

void backtracking(int length)
{
    if(length==m)
    {
        print();
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!v[i])
        {
            v[i]=true;
            A[length]=i;
            backtracking(length+1);
            v[i]=false;
        }
    }
}

void print()
{
    for(int i=0;i<m;i++)
    {
        cout<<A[i]+1<<" ";
    }
    cout<<endl;
}
