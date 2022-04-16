#include<bits/stdc++.h>
using namespace std;
int n,dp[10001],A[10001],mx=0;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;++i){
    cin>>A[i];
  }
  for(int i=1;i<=n;++i){
    if(i==1||i==2)dp[i]=A[i];
    else dp[i]=max(dp[i-2]+A[i],dp[i-3]+A[i]);
    mx=max(mx,dp[i]);
  }
  cout<<mx;
}
