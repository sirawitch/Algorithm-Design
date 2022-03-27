#include<bits/stdc++.h>
using namespace std;
int n,m,a;
vector<int> v[1001];
bool vs[1001];
stack<int> s;
void dfs(int u){
  vs[u]=true;
  for(auto &it:v[u]){
    if(!vs[it])dfs(it);
  }
  s.push(u);
}
main(){
  ios_base::sync_with_stdio(false);
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>m;
    for(int j=0;j<m;++j){
      cin>>a;
      v[a].push_back(i);
    }
  }
  for(int i=0;i<n;++i){
    if(!vs[i])dfs(i);
  }
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
}
