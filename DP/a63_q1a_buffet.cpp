#include<bits/stdc++.h>
using namespace std;
int n,k,m,d[200001],a,b;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>k>>m;
  for(int i=1;i<=n;++i){
    cin>>d[i];
    d[i]+=d[i-1]-m;
  }
  while(k--){
    cin>>a>>b;
    int pos=lower_bound(d+a,d+n+1,b+d[a-1])-d;
    cout<<pos<<"\n";
  }
}
