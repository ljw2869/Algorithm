#include<iostream>
#include<vector>

using namespace std;

int parent[51]={0,};

void UNION(int a,int b);
int FIND(int a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        parent[i]=i;//각 루트를 루트노드로 초기화
    }

    int true_cnt;
    cin>>true_cnt;

    vector<int> true_known(true_cnt);
    int tmp;
    for(int i=0;i<true_cnt;i++){
        cin>>true_known[i];//진실을 아는 사람을 업데이트-이제 진실을 아는 사람은 루트노드가 될 것
    }

    vector<vector<int>>party(m);

    for(int i=0;i<m;i++){
        int cnt,root;//해당 파티 안에 진실을 아는 사람이 있는지 유무(없는 것으로 초기화)
        cin>>cnt;
        
        for(int j=0;j<cnt;j++){
            int person;
            cin>>person;
            party[i].push_back(person);
            if(j==0){
                root=person;
            }
            else{
                UNION(person,root);
            }
        }
    }
    int result=0;
    
    if(true_cnt==0){
        cout<<m<<"\n"; 
        return 0;
    }
    else{
        for(int i=0;i<m;i++){//각 파티당 아무나 한명만 골라 진실을 알고 있는 사람들과 같은 집합인지만 검사하면 됨
            int flag=0;
            for(int j=0;j<true_cnt;j++){
                if(FIND(party[i][0])==FIND(true_known[j])){//만약 진실 알고있는 사람과 만난적이 있는 집합이면 거짓말 하면 안됨
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                result++;
        }
        cout<<result<<"\n";
    }

    return 0;
    
}

void UNION(int a,int b)
{
    a=FIND(a);
    b=FIND(b);
    
    if(a==b)
        return;
    else if(a<b){
        parent[b]=a;
        return;
    }
    else
    {
        parent[b]=a;
        return;
    }
}
int FIND(int a)
{
    if(parent[a]==a)
        return a;
    else{
        return parent[a]=FIND(parent[a]);
    }
}



