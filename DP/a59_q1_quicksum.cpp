#include<bits/stdc++.h>
using namespace std;
int qs[1001][1001],n,m,k,a,b,c,d;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>m>>k;
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
      cin>>a;
      qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+a;
    }
  }
  for(int i=0;i<k;++i){
    cin>>a>>b>>c>>d;
    cout<<qs[c+1][d+1]-qs[c+1][b]-qs[a][d+1]+qs[a][b]<<"\n";
  }
}
