#include<iostream>

#include<queue>
using namespace std;

#define endl '\n'
typedef pair<long long int, int> node;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int a,b;
    cin>>a>>b;
    queue<node>q;
    q.push(make_pair(a,0));
    int depth=0;
    while(!q.empty()){
        node x=q.front();
        q.pop();
        if(x.first==b){
            cout<<x.second+1<<endl;
            return 0;
        }
        if(x.first*2<=b)
            q.push(make_pair(x.first*2,x.second+1));

        if(x.first*10+1<=b)
            q.push(make_pair(x.first*10+1,x.second+1));
    }
    cout<<-1<<endl;
    return 0;
}
