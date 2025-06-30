#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'

using namespace std;
//이번 풀이는 문제의 의도대로 이분탐색을 사용해서 구해볼 예정(O(n)+O(n long n)+O(log n))
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].second>>v[i].first;//시작시간과 종료시간 순서로 입력 받는다
        //이후에 정렬은 쌍의 첫번째 원소를 우선순위로 정렬하기 때문에 종료시간을 우선순위로 두기 위해서 first에 종료시간 받음
    }
    sort(v.begin(),v.end());
    int cnt=0;
    int end_time=-1;
    for(int i=0;i<n;i++){
        if(v[i].second>=end_time){
            end_time=v[i].first;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}