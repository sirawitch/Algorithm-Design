#include<bits/stdc++.h>
using namespace std;
int n,qs[1001][1001],i,mx=-2e9;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n;
  for(i = 1;i<=n;++i){
    for(int j=1;j<=n;++j){
      cin>>qs[i][j];
      qs[i][j]+=qs[i-1][j-1];
    }
  }
  for(i=1;i<=n;++i){
    for(int j=1;j<=n;++j){
      for(int k=1;k<=min(i,j);++k){
        mx=max(mx,qs[i][j]-qs[i-k][j-k]);
      }
    }
  }
  cout<<mx;
}
