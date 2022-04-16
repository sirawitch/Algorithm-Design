#include<bits/stdc++.h>
using namespace std;
int n,m,a;
int dp[10001][20];
vector<int> c;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;++i){
    cin>>a; c.push_back(a);
  }
  sort(c.begin(),c.end());
  for(int i=1;i<=m;++i){
    for(int j=0;j<n;++j){
      if(j==0){dp[i][j]=i; continue;}
      else if(c[j]>i)dp[i][j]=dp[i][j-1];
      else dp[i][j]=min({dp[i][j-1],dp[i-c[j]][j-1]+1,dp[i-c[j]][j]+1});
    }
  }
cout<<dp[m][n-1];
}
