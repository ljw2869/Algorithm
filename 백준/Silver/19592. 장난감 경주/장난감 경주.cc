#include<iostream>
#include<vector>

using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;

        vector<int>v(n);

        double min=1e9;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(i!=n-1)
                min=std::min(min,double(x)/double(v[i]));
            else if(i==n-1){

                //cout<<"min time is: "<<min<<endl;
                if(double(x)/double(v[i])<min){//부스터를 쓰지 않고도 단독 우승 가능
                    cout<<0<<endl;
                    break;
                }//궂이 위와 같은 코드도 괜찮지만,
                //max값을 저장하여 이제까지의 최댓값보다 방금 입력 받은 마지막 값이 더 크다면 0출력하게 해도 됨
                
                else{
                    double result=-1;
                    for(int z=2;z<=y;z++){
                        if(1+double(x-z)/double(v[i])<min){
                            result=z;
                            break;
                        }
                    }
                    if(result==-1){
                        cout<<-1<<endl;
                    }
                    else{
                        cout<<result<<endl;
                    }
                }
            }
        }
    }
    return 0;
}