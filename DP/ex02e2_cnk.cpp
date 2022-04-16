#include<bits/stdc++.h>
int n,k,dp[31][31];
main(){
  std::cin>>n>>k;
  for(int i=1;i<=n;++i){
    for(int j=0;j<=k;++j){
      if(j==0)dp[i][j]=1;
      else if(i==j)dp[i][j]=1;
      else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    }
  }
  std::cout<<dp[n][k];
}
