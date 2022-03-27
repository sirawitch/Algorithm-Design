#include<bits/stdc++.h>
using namespace std;
vector<int> E[100001];
int deg[100001],p[100001],x=0;
bool B[100001],ans[100001];
int co[100001];
bool cycle(int a,int u){
  co[a]=1;
  for(auto it:E[a]){
    if(it==u)continue;
    if(co[it]==1)return true;
    if(co[it]==2)continue;
    return cycle(it,a);
  }
  co[a]=2;
  return false;
}
void dfs(int a,int b){
  B[a]=true;
  p[a]=b;
  if(deg[a]>=3)ans[b]=true;
  for(auto it:E[a]){
    if(!B[it]){
      dfs(it,b);
    }
  }
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  int v,e,a,b;
  cin>>v>>e;
  while(e--){
    cin>>a>>b;
    deg[a]++,deg[b]++;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  for(int i=0;i<v;++i)p[i]=i;
  for(int i=0;i<v;++i){
    if(p[i]==i)dfs(i,i);
  }
  for(int i=0;i<v;++i){
    if(p[i]==i){
      if(ans[i]==false){
        if(!cycle(i,i))x++;
      }
    }
  }
  cout<<x;
}
