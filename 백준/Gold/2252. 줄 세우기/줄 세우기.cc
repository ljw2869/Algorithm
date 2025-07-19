#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<int>>graph(n+1);
    int *arr=new int [n+1]();
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        arr[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(arr[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int top=q.front();
        q.pop();
        cout<<top<<" ";
        for(auto i:graph[top]){
            arr[i]--;
            if(arr[i]==0){
                q.push(i);
            }
        }
    }
    
    delete[] arr;
    return 0;
    
}



