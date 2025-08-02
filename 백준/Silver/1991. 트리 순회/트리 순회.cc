#include<iostream>
#include<vector>

using namespace std;

static int n;//알파벳 개수만큼 노드가 최대로 있을 수 있으므로 26개 이하의 n이다.
static int tree[26][2];//각 알파벳의 오른쪽 자식 노드의 인덱스(0)와 왼쪽 자식 노드의 인덱스(1)를 저장하는 트리구조

void preOrder(int s);
void inOrder(int s);
void postOrder(int s);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;

    char p,r,l;
    for(int i=0;i<n;i++)
    {
        cin>>p>>r>>l;
        char node=p-'A';

        if(r=='.'){
            tree[node][0]=-1;
        }
        else{
            tree[node][0]=r-'A';
        }

        if(l=='.'){
            tree[node][1]=-1;
        }
        else{
            tree[node][1]=l-'A';
        }
    }
    preOrder(0);
    cout<<"\n";
    inOrder(0);
    cout<<"\n";
    postOrder(0);

    return 0;
}

void preOrder(int s)//현재->왼쪽->오른쪽
{
    cout<<(char)(s+'A');
    if(tree[s][0]!=-1)
        preOrder(tree[s][0]);
    if(tree[s][1]!=-1)
        preOrder(tree[s][1]);
}
void inOrder(int s)//왼쪽->현재->오른쪽
{
    if(tree[s][0]!=-1)
        inOrder(tree[s][0]);
    cout<<(char)(s+'A');
    if(tree[s][1]!=-1)
        inOrder(tree[s][1]);
}
void postOrder(int s)//왼쪽->오른쪽->현재
{
    if(tree[s][0]!=-1)
        postOrder(tree[s][0]);
    if(tree[s][1]!=-1)
        postOrder(tree[s][1]);
    cout<<(char)(s+'A');
}