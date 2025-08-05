#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
vector<pair<long long,long long>>segTree;

int FindMin(int a,int b);
int FindMax(int a,int b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n,m,num;
    cin>>n>>m;
    
    int k=(int)ceil(log2(n));
    int Treesize=pow(2,k+1);
    int LeafStartIdx=Treesize/2;
    segTree.resize(Treesize,{-1,-1});//-1로 초기화 하여 이 값은 없는 값이라고 이 문제에서 약속하자
    int i;
    for(i=LeafStartIdx;i<LeafStartIdx+n;i++)
    {
        cin>>num;
        segTree[i]={num,num};
    }
    //set the tree to parent node
    i--;
    while(i>1)
    {
        if(segTree[i].first==-1)//해당 위치에 값이 없으므로 부모노드를 갱신할 수 없음
        {   
            i--; 
            continue;
        }
        if(segTree[i/2].first==-1)//부모 노드에 아직 값이 들어가지 않았다면
        {
            segTree[i/2].first=segTree[i].first;//자신의 값이 가장 최소일 것임
        }
        else{
            segTree[i/2].first=(segTree[i/2].first<segTree[i].first?segTree[i/2].first:segTree[i].first);
            //만약 이전에 자식 노드의 값으로 갱신이 된 경우 둘을 비교하여 작은 값을 저장
        }

        if(segTree[i/2].second==-1)//부모 노드에 아직 값이 들어가지 않았다면
        {
            segTree[i/2].second=segTree[i].second;//자신의 값이 가장 최대일 것임
        }
        else{
            segTree[i/2].second=(segTree[i/2].second>segTree[i].second?segTree[i/2].second:segTree[i].second);
            //만약 이전에 자식 노드의 값으로 갱신이 된 경우 둘을 비교하여 큰 값을 저장
        }
        i--;
    }

    //세그먼트 잘 만들어졌는지 확인 코드
    // for(int i=1;i<Treesize;i++)
    // {
    //     cout<<segTree[i]<<" ";
    // }
    // cout<<"\n";

    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        int realStart=a+LeafStartIdx-1;
        int realEnd=b+LeafStartIdx-1;
        cout<<FindMin(realStart,realEnd)<<" "<<FindMax(realStart,realEnd)<<"\n";
    }

    return 0;
}
int FindMin(int a,int b)
{
    int Min=2000000000;
    while(a<=b)
    {
        if(a%2==1){
            Min=(Min>segTree[a].first?segTree[a].first:Min);
            a++;
        }
        if(b%2==0)
        {
            Min=(Min>segTree[b].first?segTree[b].first:Min);
            b--;
        }
        a/=2;
        b/=2;
    }
    return Min;
}

int FindMax(int a,int b)
{
    int Max=-1;
    while(a<=b)
    {
        if(a%2==1){
            Max=(Max<segTree[a].second?segTree[a].second:Max);
            a++;
        }
        if(b%2==0)
        {
            Max=(Max<segTree[b].second?segTree[b].second:Max);
            b--;
        }
        a/=2;
        b/=2;
    }
    return Max;
}