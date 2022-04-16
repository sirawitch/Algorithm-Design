#include<bits/stdc++.h>
int n,x,y,mx=-2e9,mx2=-2e9,ans;
using namespace std;
vector<pair<int,int> > p;
main(){
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>x>>y; p.push_back({x,y});
  }ans=n;
  sort(p.begin(),p.end(),greater<pair<int,int> >());
  mx2=p[0].second;
  for(int i=1;i<n;++i){

    if(p[i].first!=p[i-1].first){
      mx=mx2;
    }
    if(p[i].second<=mx)--ans;
    mx2=max(p[i].second,mx2);
  }
  printf("%d",ans);
}
