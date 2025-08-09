#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

vector<vector<int>>Tree;
vector<bool>visited;
vector<int>depth;
int parent[21][100001];//노드가 100000개가 최대이므로 최대 깊이는 21보다 작다

void BFS(int root);
int LCA(int a,int b);

static int n,m;
static int kmax=0;//실제 그래프의 최대 깊이를 저장하는 변수

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    Tree.resize(n+1);
    visited.resize(n+1,false);
    depth.resize(n+1);

    int tmp=1;
    while(tmp<=n)
    {
        tmp<<=1;//2씩 곱해주기
        kmax++;
    }//아니면 로그 함수를 쓰고 floor함수를 사용해서 트리의 깊이를 구해주어도 됨

    int a,b;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        Tree[a].push_back(
            b);
        Tree[b].push_back(a);
    }

    BFS(1);
    for(int k=1;k<=kmax;k++)
    //0번째는 그냥 바로 위의 부모노드이고 BFS로 모두 만들어 둠
    //작은 k에서부터 시작해야 하는 이유는 결국 점화식에서 더 작은 인덱스의 값에 기반해서 만들어지기 때문
    {
        for(int j=1;j<n+1;j++)
        {
            parent[k][j]=parent[k-1][parent[k-1][j]];
        }
    }

    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        cout<<LCA(a,b)<<"\n";
    }

    return 0;
}

void BFS(int root)
{
    queue<int>q;

    q.push(root);
    visited[root]=true;

    int level=1;//현재 루트노드의 레벨은 0이고 현재 루트노드에 연결된 노드들의 깊이를 대입해주기 위해 1로 초기화
    int now_size=1;
    int cnt=0;

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        for(int next:Tree[cur])
        {
            if(!visited[next])
            {
                q.push(next);
                visited[next]=true;//잊지 말고 꼭 넣어주기!!
                depth[next]=level;
                parent[0][next]=cur;//0번째 부모는 2^0번째 부모, 즉 바로 위의 부모
            }
        }
        cnt++;
        if(cnt==now_size)
        {
            cnt=0;
            now_size=q.size();
            level++;
        }
    }
    /*
    위와 같이 다양한 변수를 사용해서 자식 노드들의 깊이를 알맞게 넣어줄 수 있지만 간단히 
    depth[next] = depth[cur] + 1; // 부모 깊이 + 1
    다음과 같은 코드를 작성하면 헷갈릴 일이 없게 됨....
    */
}

int LCA(int a,int b)
{
    if(depth[a]>depth[b])
    {
        int tmp=a;
        a=b;
        b=tmp;
    }//깊이가 더 깊은 쪽을 b로 맞춰준다


    /*****************여기부터가 제일 중요한 부분 ***************/
    //깊이 맞춰주기-이것 또한 시간을 빠르게 줄여줄 수 있는 방법
    for(int k=kmax;k>=0;k--)
    {
        if(pow(2,k)<=depth[b]-depth[a])
        {
            b=parent[k][b];//b의 k번째 위에 있는 부모로 점프해서 parent배열에 저장해둔 그 부모의 노드 번호로 바로 갱신
        }
    }

    //같은 깊이에서 부모 찾기- 시간을 빠르게 줄여주는 방법(k번째 부모로 함께 건너 뛰기)
    for(int k=kmax;k>=0;k--)
    {
        if(parent[k][a]!=parent[k][b]) //부모가 같지 않을 때 까지 k번째 부모로 점프하며 올라간다
        {
            a=parent[k][a];
            b=parent[k][b];
        }
    }
    //만약 k=0이 된 시점에서도 a와 b가 같은 지점에 도달(부모노드 찾음)하지 않았다면 
    //현재 다른 노드를 가리키고 있고 바로 위의 노드가 부모노드이므로 한칸만 부모 노드로 올라가 값을 갱신
    if(a!=b)
    {
        a=parent[0][a];
    }
    return a;
}