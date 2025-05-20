#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;
    vector<int> A(N,0);
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }

    sort(A.begin(),A.end());

    int result=0;

    for(int k=0;k<N;k++){
        long find=A[k];//이 find가 좋은 수가 아닌 지 맞는 지 찾아볼 것이다.
        int i=0;
        int j=N-1;

        while(i<j){
            if (A[i]+A[j]==find){
                if(i!=k&&j!=k){//여기서 예외 처리는 자기 자신이 들어가면 안된다 (데이터에 정수가 들어가면 자기 자신을 더한 결과가 나올 수 있다.)
                    result++;
                    break;
                }         
                else if(i==k){
                    i++;//자기 자신이 들어가면 안된다. 그러니 자기 자신에 도달하면 i를 증가시키기
                }
                else if(j==k){
                    j--;//자기 자신이 들어가면 안된다. 그러니 자기 자신에 도달하면 j를 감소시키기
                }
            }
            else if(A[i]+A[j]<find){
                i++;
            }
            else{
                j--;
            }
        }
    }
    cout<<result<<endl;
    return 0;
}