#include<iostream>
#define endl '\n'
#include <vector>
using namespace std;

static vector <bool> visited;
static vector<vector<int>>A;
static int meet;
void DFS(int x,int y,int depth);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; //노드 수 입력
    cin>>N;
    int x,y;
    cin>>x>>y;

    meet=-1;
    visited=vector<bool>(N+1,false);
    A.resize(N+1);

    int M;
    cin>>M;
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    DFS(x,y,1);
    cout<<meet;
    return 0;
}

void DFS(int x,int y,int depth)
{
    if (meet>=0)
        return;
    visited[x]=true;
    for(int i:A[x]){
        if(!visited[i])
        {
            if(i==y){
                meet=depth;
                return;
            }
            DFS(i,y,depth+1);
        }
    }
    //여기서는 백트레킹을 하지 않아도 부모 자식간의 관계라 다른 경로로 다시 돌아와서 만나는 경우는 없을 것이다
}