#include<bits/stdc++.h>
using namespace std;
int n,dp[10001],i,mx=0;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n;
  for(i=1;i<=n;++i){
    cin>>dp[i];
    switch(i){
      case 1: break;
      case 2:break;
      case 3:break;
      case 4:dp[i]+=max({dp[i-3],dp[i-4]});break;
      default:dp[i]+=max({dp[i-3],dp[i-4],dp[i-5]});
    }
    mx=max(mx,dp[i]);
  }
  cout<<mx;
}
