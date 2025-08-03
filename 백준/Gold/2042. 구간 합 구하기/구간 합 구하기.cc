#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<long long>segTree;

void update(int b,long long c,int size);
long long prefixSum(int b,int c,int size);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n,m,t;//n개의 수, m번의 변경, t번의 구간합 계산
    cin>>n>>m>>t;

    int k=(int)ceil(log2(n));
    
    int size=pow(2,k);
    segTree.resize(size*2,0);

    int i;
    long long num;
    for(i=size;i<size+n;i++)
    {
        cin>>num;
        segTree[i]=num;
    }
    i--;
    //부모노드 업데이트
    while(i>1)
    {
        segTree[i/2]+=segTree[i];
        i--;
    }

    int a,b;
    long long c;
    for(int j=0;j<m+t;j++)
    {
        cin>>a>>b>>c;
        if(a==1)
        {//b번째 수를 c로 바꿔라
            update(b,c,size);
        }
        else if(a==2)
        {//b번째 수부터 c번째 수까지의 합을 구하라
            cout<<prefixSum(b,c,size)<<"\n";
        }
    }

    return 0;
}

void update(int b,long long c,int size)
{
    int real_idx=b-1+size;
    segTree[real_idx]=c;//실제 리프노드의 값 갱신
    while(real_idx>1)//부모노드에 저장된 구간합 갱신
    {
        int parent_idx=real_idx/2;
        segTree[parent_idx]=segTree[parent_idx*2]+segTree[parent_idx*2+1];
        real_idx/=2;
    }
}
long long prefixSum(int b,int c,int size)
{
    int start_point=b+size-1;
    int end_point=c+size-1;
    long long sum=0;

    while(start_point<=end_point)
    {
        if(start_point%2==1)  sum+=segTree[start_point++];
        if(end_point%2==0) sum+=segTree[end_point--];

        start_point/=2;
        end_point/=2;
    }
    return sum;

}

