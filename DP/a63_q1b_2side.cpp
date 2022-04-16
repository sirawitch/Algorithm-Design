#include<bits/stdc++.h>
using namespace std;
int n,w,k,l[200001],r[200001],mx=0,dp[200001][2];
deque <int> d,d2;
int mx2[2][51],dp2[200001][2][51];
void solve(){
  for(int i=1;i<=n;++i){
    for(int j=1;j<=k;++j){
      if(i<=w){
        dp2[i][0][1]=l[i];
        dp2[i][1][1]=r[i];
        mx=max({mx,dp2[i][0][j],dp2[i][1][j]}); break;
      }
      else{
       dp2[i][0][j]=mx2[1][j-1]+l[i]; 
       dp2[i][1][j]=mx2[0][j-1]+r[i]; 
       mx2[0][j]=max(mx2[0][j],dp2[i-w][0][j]);
       mx2[1][j]=max(mx2[1][j],dp2[i-w][1][j]);
      }
      mx=max({mx,dp2[i][0][j],dp2[i][1][j]});
    }
  }
  cout<<mx;
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>w>>k;
  for(int i=1;i<=n;++i){
    cin>>l[i];
  }
  for(int i=1;i<=n;++i){
    cin>>r[i];
  }
  if(k!=n){
    solve(); return 0;
  }
  for(int i=1;i<=n;++i){
    if(i<=w){
      dp[i][0]=l[i];
      dp[i][1]=r[i];
    }
   else{
      if(d.empty())dp[i][1]=r[i];
      else dp[i][1]=r[i]+dp[d.front()][0];
      if(d2.empty())dp[i][0]=l[i];
      else dp[i][0]=l[i]+dp[d2.front()][1];
      while(!d.empty()){
        if(dp[d.back()][0]>dp[i-w][0])break;
        d.pop_back();
      }
      while(!d2.empty()){
        if(dp[d2.back()][1]>dp[i-w][1])break;
        d2.pop_back();
      }
      d2.push_back(i-w);
      d.push_back(i-w);
    }
    mx=max({mx,dp[i][0],dp[i][1]});
  }
  cout<<mx;
}
