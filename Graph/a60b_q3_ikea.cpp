#include<bits/stdc++.h>
using namespace std;
int n,e,a,b;
vector<int> v[1001];
bool B[1001],ans;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>e;
  while(e--){
    cin>>a>>b;
    v[b].push_back(a);
  }
  for(int i=0;i<5;++i){
    fill(B,B+n,false);
    ans=false;
    for(int j=0;j<n;++j){
      cin>>a;
      B[a]=true;
      for(auto &it:v[a]){
        if(B[it]==false)ans=true;
      }
    }
    if(ans==true)cout<<"FAIL\n";
    else cout<<"SUCCESS\n";
  }
}
