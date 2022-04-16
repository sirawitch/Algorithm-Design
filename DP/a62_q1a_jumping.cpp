#include<bits/stdc++.h>
using namespace std;
int n,dp[1000001],k[1000001];
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;++i){
    cin>>k[i];
  }
  dp[1]=k[1];
  dp[2]=k[1]+k[2];
  dp[3]=max(dp[1]+k[3],dp[2]+k[3]);
  for(int i=4;i<=n;++i){
    dp[i]=max({dp[i-1],dp[i-2],dp[i-3]})+k[i];
  }
  cout<<dp[n];
}
