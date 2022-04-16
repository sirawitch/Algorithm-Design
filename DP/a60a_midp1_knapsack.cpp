#include<bits/stdc++.h>
using namespace std;
int n,m,v[501],w[501],dp[501][501];
void f(vector<int> &ans,int a,int b){
  if(dp[a][b]==0)return;
  if(dp[a-1][b]==dp[a][b])f(ans,a-1,b);
  else {ans.push_back(a); f(ans,a-1,b-w[a]);}
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;++i)cin>>v[i];
  for(int i=1;i<=n;++i)cin>>w[i];
  for(int i=0;i<=n;++i){
    for(int j=0;j<=m;++j){
      cin>>dp[i][j];
    }
  }
  vector<int> ans;
  f(ans,n,m);
  cout<<ans.size()<<"\n";
  for(auto it:ans){
    cout<<it<<" ";
  }
}
