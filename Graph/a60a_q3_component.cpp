#include<bits/stdc++.h>
using namespace std;
vector<int> E[10001];
int p[10001],ans=0;
bool vs[10001];
void dfs(int a,int b){
  p[a]=b;
  vs[a]=true;
  for(auto &it:E[a]){
    if(!vs[it])dfs(it,b);
  }
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  int v,e,a,b;
  cin>>v>>e;
  while(e--){
    cin>>a>>b;
    E[a].push_back(b);E[b].push_back(a);
  }
  for(int i=1;i<=v;++i)p[i]=i;
  for(int i=1;i<=v;++i){
    if(p[i]==i){
      ++ans; dfs(i,i);
    }
  }
  cout<<ans;
}
