#include<iostream>
#include<vector>

using namespace std;

int find(vector<int> &graph,int a);
void union_algorithm(vector<int>&graph,int a,int b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int>graph(n+1);
    for(int i=0;i<=n;i++){
        graph[i]=i;
    }//initialize value with their index


    int c,a,b;
    for(int i=0;i<m;i++){
        cin>>c>>a>>b;
        if(c==0){ //make a connection-make an edge(union)
            union_algorithm(graph,a,b);
        }
        else if (c==1){//c==1 ask the connection(find)
            int root1=find(graph,graph[a]);
            int root2=find(graph,graph[b]);

            if(root1!=root2){
                cout<<"NO"<<'\n';
            }
            else{
                cout<<"YES"<<"\n";
            }
        }
    }

    // for(int i=0;i<=n;i++)
    // {
    //     cout<<graph[i]<<" ";
    // }
    
    return 0;
}

int find(vector<int> &graph,int a)
{
    if(graph[a]!=a){
        graph[a]=find(graph,graph[a]);//여기를 처음에 graph[graph[a]]로 이중으로 보내버림;;
        return graph[a];
    }
    else{
        return graph[a];
    }
}

void union_algorithm(vector<int>&graph,int a,int b)
{
    
        int root1=find(graph,a);//여기도 불필요하게 graph[a]로 넣지 말고 알아서 찾아주니 a로 바로 넣어줘도 상관 없음
        int root2=find(graph,b);
        if(root1==root2){
            return;
        }

        if(root1<root2){
            graph[root2]=root1;//근본적인걸 바꾸어줘야지 b에 있는 값을 바꾸어주면 겉핥는 것 밖에 안됨... root의 값을 변경한다!!
        }
        else{
            graph[root1]=root2;
        }
    
}