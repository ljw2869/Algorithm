#include<iostream>
#include<vector>
#include<queue>

using namespace std;

static int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    vector<vector<int>>graph(n+1);

    int a,b;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //위와 같이 그래프구조가 아래에서 1이라고 루트노드를 주고 bfs로 탐색하는 순간 트리로 인식
    vector<int>result(n+1,0);

    queue<int>q;
    q.push(1);
    //1이라는 루트를 기준으로 bfs를 돌리면 1에서부터 연결되어 아래로 내려가면서 탐색하게 되니
    //1에서 가깝게 연결된 노드가 분명히 부모노드이므로 먼저 큐에 들어온 노드가 무조건 부모가 된다
    while(!q.empty())
    {
        int now=q.front();
        q.pop();

        for(int i:graph[now]){
            if(result[i]==0){
                result[i]=now;
                q.push(i);
            }
        }
    }

    for(int i=2;i<=n;i++)
        cout<<result[i]<<"\n";
    return 0;
}

