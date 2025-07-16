#include<iostream>
#include<vector>

using namespace std;

int graph[201]={0,};

int FIND(int a);
void UNION(int a,int b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n;
    cin>>m;

    for(int i=1;i<=n;i++){
        graph[i]=i;//자신의 인덱스로 초기화(실제 1~N까지의 인덱스만 사용할 것이라 이렇게 초기화함)
    }

    int connection;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>connection;
            if(connection==1){
                if(FIND(i+1)!=FIND(j+1))
                    UNION(i+1,j+1);//양방향 그래프라도 그냥 합집합 연산을 하기 때문에 궂이 여기서는 양방향을 신경쓸 필요 없을 듯
            }
            else{
                continue;
            }
        }
    }
    int a,b;//a는 대표노드(시작 노드, 루트노드), b는 a와 연결되어 있는 지 확인(비교)하는 대입할 때 쓰이는 노드
    for(int i=0;i<m;i++)
    {
        if(i==0){
            cin>>a;
        }
        else{
            cin>>b;
            if(FIND(a)!=FIND(b)){
                cout<<"NO"<<"\n";
                return 0;
            }
            else{
                continue;
            }
        }
    }
    cout<<"YES"<<"\n";
    return 0;
    //위와 같이 작성하면 발생할 수 있는 예외상황:n이 1인데 이무것도 연결이 안 된 경우? n=1,m=0& n=1,m=1, 0이런 경우는 바로 yes가 나올 수도
}

int FIND(int a)//a는 인덱스를 넘겨 받는 것이다
{
    if(graph[a]==a)//인덱스와 값이 같으면 대표노드라는 의미
        return a;
    else //대표노드가 아니면 
        return graph[a]=FIND(graph[a]);
}
void UNION(int a,int b)
{
    a=FIND(a);
    b=FIND(b);
    if(a==b)
        return;
    if(a<=b){
        graph[b]=a;
        return;
    }
    else{
        graph[a]=b;
        return;
    }
}



