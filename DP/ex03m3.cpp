#include<bits/stdc++.h>
using namespace std;
int n,k,A[10001];
deque<int> D;
long long dp[10001],mn=2e17;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;++i){
    cin>>A[i];
  }
  dp[0]=0;
  for(int i=1;i<=n;++i){
    if(i<=k+1){
      dp[i]=A[i];
      while(!D.empty()){
        if(dp[D.back()]>dp[i])D.pop_back();
        else break;
      }
      D.push_back(i);
      if(i>=n-k)mn=min(mn,dp[i]);
    }
    else{
      if(D.front()<i-2*k-1)D.pop_front();
      dp[i]=dp[D.front()]+A[i];
      while(!D.empty()){
        if(dp[D.back()]>dp[i])D.pop_back();
        else break;
      }
      D.push_back(i);
      if(i>=n-k){
        mn=min(mn,dp[i]);
      }
    }
  }
  cout<<mn;
}
