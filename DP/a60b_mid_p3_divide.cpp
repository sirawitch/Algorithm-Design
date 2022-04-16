#include<bits/stdc++.h>
using namespace std;
int dp[501][501],n,k;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;++i){
    for(int j=1;j<=k;++j){
      if(j>i)break;
      if(j==1||j==i)dp[i][j]=1;
      else dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1])%1997;
    }
  }
  cout<<dp[n][k];
}
