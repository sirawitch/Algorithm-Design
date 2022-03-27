#include<bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  int n,e,s,a,b,c;
  int dis[101];
  bool check=false;
  vector<pair<int,pair<int,int> > >E;
  cin>>n>>e>>s;
  for(int i=0;i<e;++i){
    cin>>a>>b>>c;
    E.push_back(mp(a,mp(b,c)));
  }
  for(int i=0;i<n;++i)dis[i]=2e9;
  dis[s]=0;
  for(int i=0;i<n-1;++i){
    for(auto &it:E){
      if(dis[it.S.F]>dis[it.F]+it.S.S&&dis[it.F]!=2e9){
        dis[it.S.F]=dis[it.F]+it.S.S;
      }
    }
  }
  for(auto &it:E){
    if(dis[it.S.F]>dis[it.F]+it.S.S&&dis[it.F]!=2e9){
      check=true; break;
    }
  }
  if(check)cout<<-1;
  else{
    for(int i=0;i<n;++i){
      cout<<dis[i]<<" ";
    }
  }
}
