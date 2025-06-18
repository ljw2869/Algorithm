#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
static int arrived;

void DFS(int node,int depth);

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    cin>>N>>M;
    arrived=false;

    A.resize(N);//인접 리스트를 저장할 벡터로, 크기는 N으로 초기화
    visited=vector<bool>(N,false);//방문 여부를 저장하는 벡터로, 초기화
    for(int i=0;i<M;i++){
        int s,e;
        cin>>s>>e;

        //양 방향 그래프이므로 양쪽 모두에 간선을 추가
        A[s].push_back(e);
        A[e].push_back(s);
    }

    for(int i=0;i<N;i++){//모든 노드에 대하여 DFS탐색 시작
        DFS(i,1);
        if(arrived==true){
            break;
        }
    }

    if (arrived){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
    return 0;
}

void DFS(int node,int depth){
    if (depth==5||arrived){
        arrived=true;
        return;
    }

    visited[node]=true;
    for(int i:A[node]){
        if(!visited[i]){
            DFS(i,depth+1);
        }
    }
    visited[node]=false;//백트레킹으로 다음 노드에 대한 깊이 우선탐색을 위해 방문 표시 해제
}