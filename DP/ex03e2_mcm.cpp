#include<bits/stdc++.h>
using namespace std;
int n,A[101];
int dp[101][101];
bool B[101][101];
int func(int l,int r){
  if(B[l][r]==true)return dp[l][r];
  dp[l][r]=2e9;
  for(int i=l+1;i<=r;++i){
    dp[l][r]=min(dp[l][r],func(l,i-1)+func(i,r)+A[l]*A[r+1]*A[i]);
  }B[l][r]=true;
  return dp[l][r];
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n;
  for(int i=0;i<=n;++i){
    cin>>A[i];
    dp[i][i]=0;
    B[i][i]=true;
  }
  cout<<func(0,n-1);
}
