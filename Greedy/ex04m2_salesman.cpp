#include<bits/stdc++.h>
using namespace std;
int n,m,qs[1001],T[1001],a,b,ans=0;
int dir(int i,int j){
  int ncir;
  ncir=qs[j-1]-qs[i-1];
  if(ncir<0)ncir*=-1;
  return min(ncir,qs[m]-ncir);
}
main(){
ios_base::sync_with_stdio(false),cin.tie(0);
cin>>n>>m;
for(int i=1;i<=m;++i){
  cin>>T[i];
  T[i]++;
}
for(int i=1;i<=m;++i){
  cin>>qs[i];
  qs[i]+=qs[i-1];
}
for(int i=1;i<=n;++i){
  cin>>a>>b;
  ans=0;++a;++b;
  for(int j=1;j<=m;++j){
    if(j==m){
      ans+=min({dir(T[j],T[1]),dir(T[j],a)+dir(b,T[1]),dir(T[j],b)+dir(a,T[1])});
    }
    else{
      ans+=min({dir(T[j],T[j+1]),dir(T[j],a)+dir(b,T[j+1]),dir(T[j],b)+dir(a,T[j+1])});
    }
  }
  cout<<ans<<"\n";
}
}
