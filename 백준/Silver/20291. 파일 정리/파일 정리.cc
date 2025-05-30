#include<iostream>
#include<map>
#include<cstring>

using namespace std;
#define endl '\n'



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin>>N;
    string name,file_names;
    map<string,int>files;
    int idx, files_idx;

    for(int i=0;i<N;i++){
        cin>>name;
        idx=name.find('.');
        file_names=name.substr(idx+1);
        files[file_names]++;
    }

    for(auto t:files){
        cout<<t.first<<" "<<t.second<<endl;
    }
    return 0;
}