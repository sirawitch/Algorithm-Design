#include<bits/stdc++.h>
using namespace std;
int r,c,dp[1003][1003],mx=0;
char s[1003][1003];
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>r>>c;
  for(int i=0;i<r;++i){
    cin>>s[i];
  }
  for(int i=0;i<r;++i){
    for(int j=0;j<c;++j){
      if(s[i][j]=='0'){dp[i][j]=0; continue;}
      if(i==0||j==0){dp[i][j]=1;}
      else{dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;}
      mx=max(mx,dp[i][j]);
    }
  }
  cout<<mx;
}
