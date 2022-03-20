#include<bits/stdc++.h>
using namespace std;
int n,a,m,ID[1001],S[1001],id=0,low[1001],k;
vector<int> v[1001];
vector<int> ans;
stack<int> s;
void dfs(int u){
  s.push(u);
  S[u]=1;
  ID[u]=low[u]=id++;
  for(auto &it:v[u]){
    if(ID[it]==-1)dfs(it);
    if(S[it]==1)low[u]=min(low[u],low[it]);
  }
  if(ID[u]==low[u]){k=0;
    while(!s.empty()){++k;
      a=s.top();
      s.pop();
      S[a]=0;
      low[a]=ID[u];
      if(a==u)break;
    }
    ans.push_back(k);
  }
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>m;
    for(int j=0;j<m;++j){
      cin>>a; v[i].push_back(a);
    }
  }
  for(int i=0;i<n;++i)ID[i]=-1;
  for(int i=0;i<n;++i){
    if(ID[i]==-1){
      dfs(i);
    }
  }
  sort(ans.begin(),ans.end());
  for(auto &it:ans){
    cout<<it<<" ";
  }
}
