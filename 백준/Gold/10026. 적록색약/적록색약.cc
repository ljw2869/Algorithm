#include<iostream>
#include<string>
#define endl '\n'

using namespace std;

char arr[101][101];
bool visited[101][101];
string temp;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void DFS(int x,int y,int N);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;
    int cnt=0;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        for(int k=0;k<N;k++)
        {
            arr[i][k] = temp[k];
            visited[i][k] = false;
        }
        
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j]){
                DFS(i,j,N);
                cnt++;
            }
        }
    }
    cout<<cnt<<" ";
    cnt=0;
    //다음 적록색맹을 위해 그림변형

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visited[i][j]=false;
            if(arr[i][j]=='G')
                arr[i][j]='R'; //적록색맹은 G를 R로 인식
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j]){
                DFS(i,j,N);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}

void DFS(int x,int y,int N)
{
    visited[x][y]=true;
    for(int i=0;i<4;i++){
        
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&ny>=0&&nx<N&&ny<N&&!visited[nx][ny])
            if(arr[nx][ny]==arr[x][y]){
                DFS(nx,ny,N);
            }
    }
}

