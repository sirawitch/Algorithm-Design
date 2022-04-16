#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int dp[4001],x,y,z;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>a>>b>>c;
    for(int i=1;i<=n;++i){
      x=-2e9,y=-2e9,z=-2e9;
        if(i>=a)x=dp[i-a];
        if(i>=b)y=dp[i-b];
        if(i>=c)z=dp[i-c];
        dp[i]=max({x,y,z})+1;
  }
  cout<<dp[n];
}
