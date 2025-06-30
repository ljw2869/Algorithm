#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;

    vector<long long>dist(n-1);
    vector<long long>price(n);

    for(int i=0;i<n-1;i++){
        cin>>dist[i];
    }
    for(int i=0;i<n;i++){
        cin>>price[i];
    }

    long long sum=0;
    long min_price=1000000001;;

    for(int i=0;i<n-1;i++){
        if(min_price>price[i]){
            min_price=price[i];
        }
        sum+=min_price*dist[i];
    }
    cout<<sum<<endl;
    
    return 0;
}