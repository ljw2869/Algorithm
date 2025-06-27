#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

int binary_search(const vector<int>&a,const vector<int>&b,int m);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        vector<int>a(n);
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        vector<int>b(m);
        for(int j=0;j<m;j++){
            cin>>b[j];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        cout<<binary_search(a,b,m)<<endl;
    }
    return 0;
}

int binary_search(const vector<int>&a,const vector<int>&b,int m)
{
    int cnt=0;
    for(int i:a){

        //근본적인 이분탐색 코드를 작성해보자
        int s=0,e=m;
        while(s<e){
            int mid=(s+e)/2;
            if(b[mid]<i){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        cnt+=s;


        // int median=m/2;
        // if(b[0]>i){
        //     //cout<<"더할 값이 없음"<<endl;
        //     continue;
        // }
        // else if(b[m-1]<i){
        //     cnt+=m;
        //     //cout<<"한방에 더해버림"<<endl;
        //     continue;
        // }
        // int s=0,e=m-1;
        // bool flag=true;
        // while(s<=e){
        //     median=(s+e)/2;
        //     //cout<<"s:"<<s<<" e:"<<e<<" median:"<<median<<endl;
        //     if(b[median]==i){ //이 원소가 같다고 해서 이 이전의 원소가 무조건 작다는 보장은 없음!! 연속된 원소가 들어갈 수 있으니까!
        //         cnt+=median;
        //         flag=false;
        //         break;
        //     }
        //     else if(b[median]<i){
        //         s=median+1;
        //     }
        //     else if(b[median]>i){
        //         e=median-1;
        //     }
        // }
        // if(flag){
        //     cnt+=s;
        // }

            //아래 코드가 틀린 이유는 a의 원소가 b에 무조건 존재한다는 가정 하에 만들어진 것이라 무한 루프에 빠지게 된다...-강의 내용 그대로 이진 탐색을 구현한 것에 의미가 있다...!!
            // if(median<0||median>=m)
            // {
            //     flag=false;
            //     break;
            // }
            // else if(b[median]==i)
            // {
            //     cnt+=median+1;
            //     flag=false;
            //     break;
            // }
            // else if(b[median]<i)
            // {
            //     median=(median+m)/2;
            // }
            // else if(b[median]>i)
            // {
            //     median=median/2;
            // }
        
    }
    return cnt;
}