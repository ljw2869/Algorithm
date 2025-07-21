#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//방향그래프에서 사이클 유무를 판별할 때 DFS사용(visited+ recursive_Stack으로 구현)
bool visited[101]={false,};
bool recStack[101]={false,};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<int>> graph(n+1);
    vector<int> indegree(n+1,0);

    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        vector<int> temp(k);
        for (int j = 0; j < k; j++) {
            cin >> temp[j];
        }
        for (int j = 0; j < k - 1; j++) {
            graph[temp[j]].push_back(temp[j + 1]);
            indegree[temp[j + 1]]++;
        }
    }

    //위상정렬 알고리즘
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>result;
    
    while(!q.empty()){//큐가 비었는데도 모든 노드를 정렬하지 않았다면 사이클이 발생했다는 증거!
        int top=q.front();
        q.pop();
        result.push_back(top);
        
        //cout<<top<<"\n";
        for(auto i:graph[top]){
            if(--indegree[i]==0){
                q.push(i);
            }
        }
    }

    if(result.size()!=n) //사이클 발생해서 불가능
    {
        cout<<0<<"\n";
    }
    else{ //사이클이 없다면 저장된 결과를 출력
        for(int x:result){
            cout<<x<<"\n";
        }
    }

    return 0;
}
