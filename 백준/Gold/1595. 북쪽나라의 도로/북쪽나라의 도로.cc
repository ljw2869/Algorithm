#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
#define endl '\n'
int endpoint=0;
int result=0;

static vector<pair<int,int>>tree[10001];
static bool visited[10001];

void DFS(int p,int len);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int a,b,c;
    while(cin>>a>>b>>c){
        tree[a].push_back(make_pair(b,c));
        tree[b].push_back(make_pair(a,c));
    }
    DFS(1,0);
    result=0;
    memset(visited,false,sizeof(visited));
    DFS(endpoint,0);
    cout<<result;

    return 0;
}

void DFS(int p,int len){
    visited[p]=true;
    if(len>result)
    {
        result=len;
        endpoint=p;
    }
    for(auto&e:tree[p]){
        if(!visited[e.first])
        {
            DFS(e.first,len+e.second);
        }
    }
}