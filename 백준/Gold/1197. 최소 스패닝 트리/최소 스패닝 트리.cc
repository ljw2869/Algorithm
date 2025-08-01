#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>parent;

struct Edge{
    int start;
    int end;
    int weight;//가중치는 음수일 수 있다. 
};

bool cmp(Edge a, Edge b)
{
    return a.weight<b.weight;
}

int Find(int a)//재귀함수가 아니라 반복문으로 시간초과 문제를 미리 피해보자
{
    if(parent[a]!=a)
        return parent[a]=Find(parent[a]);//경로단축
    return parent[a];
}
void Union(int a,int b)
{
    a=Find(a);
    b=Find(b);

    if(a==b)return;

    if(a<b){
        parent[b]=a;
    }
    else{
        parent[a]=b;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int v,e;
    cin>>v>>e;
    vector<Edge>graph;
    parent.resize(v+1);//유니온 파인드를 위한 그래프
    for(int i=1;i<=v;i++)
    {
        parent[i]=i;
    }

    int a,b,c;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        graph.push_back({a,b,c});
    }
    
    sort(graph.begin(),graph.end(),cmp); //가중치기준 오름차순 정렬
    
    //오름차순 정렬 확인 출력용 코드
    // for(int i=0;i<e;i++)
    // {
    //     cout<<graph[i].start<<" "<<graph[i].end<<" "<<graph[i].weight<<"\n";
    // }

    int total=0;//최종적으로 사용한 간선의 개수가 v-1개여야 한다
    int result=0;

    for(auto edge:graph)
    {
        if(total<v-1)
        {
            int s=edge.start;
            int e=edge.end;
            int w=edge.weight;

            if(Find(s)!=Find(e))
            {
                Union(s,e);
                result+=w;
                total++;
            }
        }
        else break;
    }
    cout<<result<<"\n";
    
    return 0;
}