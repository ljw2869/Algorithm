#include<iostream>
#include<vector>

using namespace std;

static vector<pair<int,int>> graph[10002];
static vector<bool> visited;

int result=0;
int endpoint=0;

void DFS(int node,int len){
    // if(visited[node])
    //     return;
    visited[node]=true;

    if(len>result){
        result=len;
        endpoint=node;
    }
    //가장 많이 쓰이는 auto edge하고 edge의 first,second로 사용해도 된다.... 이 코드는 복사 방지에 유용
    for(const pair<int,int>&edge: graph[node]){ 
        if(!visited[edge.first]){
            DFS(edge.first,len+edge.second);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    visited.resize(n+1);

    int u,v,w;
    for(int i=0;i<n-1;i++){
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    DFS(1,0);//가장 멀리 있는 점을 구하기

    result=0;
    fill(visited.begin(),visited.end(),false); //fill함수가 c++컨테이너 전용으로 안전, 범용적인 초기화 방법(memset은 타입 제약 많음(char,int))
    DFS(endpoint,0);//가장 멀리 있는 점을 기준으로 깊이우선탐색하여 최대 지름 구하기
    cout<<result;

    return 0;
}
