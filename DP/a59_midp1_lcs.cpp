#include<bits/stdc++.h>
using namespace std;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  int n,m;
  char s[1005],s2[1005];
  int x[1005][1004];
  string ans="";
  cin>>n>>m;
  cin>>s>>s2;
  for(int i=0;i<=n;++i){
    for(int j=0;j<=m;++j){
      cin>>x[i][j];
    }
    if(i!=0){
      if(x[i-1][m]!=x[i][m])ans+=s[i-1];
    }
  }
  cout<<ans;
}
