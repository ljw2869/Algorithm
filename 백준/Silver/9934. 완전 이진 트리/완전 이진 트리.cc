#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

static int k;
vector<int>tree[10];//최대 10까지의 깊이까지 차례대로 노드를 추가한다
vector<int>inOrderResult;

void sol(int start,int end,int depth);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>k;//깊이는 최대 10

    int num;
    for(int i=0;i<pow(2,k)-1;i++)//그냥 while(cin>>num)으로 입력받은 만큼만 반복문 돌리기 가능
    {
        cin>>num;
        inOrderResult.push_back(num);
    }

    sol(0,pow(2,k)-2,0);//총 2^k-1개이니까 0에서부터 2^k-2까지 인덱스 있음
    
    for(int i=0;i<k;i++)
    {
        for(auto node:tree[i])
        {
            cout<<node<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

void sol(int start,int end,int depth)
{
    if(start==end)//리프노드 도달
    {
        tree[depth].push_back(inOrderResult[start]);
        return;
    }
    int mid=(start+end)/2;
    tree[depth].push_back(inOrderResult[mid]);
    sol(start,mid-1,depth+1);//왼쪽부터 트리 벡터에 저장한다
    sol(mid+1,end,depth+1);
}

