#include<bits/stdc++.h>
using namespace std;
int n,m,dp[500][500];
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      cin>>dp[i][j];
      if(i==0&&j==0);
      else if(i==0)dp[i][j]+=dp[i][j-1];
      else if(j==0)dp[i][j]+=dp[i-1][j];
      else dp[i][j]+=max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+dp[i][j]});
    }
  }
  cout<<dp[n-1][m-1];
}
