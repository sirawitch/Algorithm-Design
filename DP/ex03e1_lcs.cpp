#include<bits/stdc++.h>
using namespace std;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  char s[502],s2[502];
  int dp[502][502];
  cin>>s>>s2;
  int x=strlen(s),y=strlen(s2);
  for(int i=0;i<=x;++i){
    for(int j=0;j<=y;++j){
      if(i==0)dp[i][j]=0;
      else if(j==0)dp[i][j]=0;
      else if(s[i-1]==s2[j-1])dp[i][j]=max({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]+1});
      else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }
  }
  cout<<dp[x][y];
}
