#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
vector<int>v;
vector<pair<int,pair<int,int> > > E;
int l,r,md,n;
bool vs[5001];
int p[5001];
int root(int u){
  if(p[u]==u)return u;
  return p[u]=root(p[u]);
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  int m,q,a,b,c;
  cin>>n>>m>>q;
  while(m--){
    cin>>a>>b>>c;
    E.push_back(mp(c,mp(a,b)));
  }
  for(int i=0;i<n;++i)p[i]=i;
  sort(E.begin(),E.end());
  for(auto &it:E){
    a=root(it.second.first);
    b=root(it.second.second);
    if(a!=b){
      v.push_back(it.first);
      p[a]=b;
    }
  }
  while(q--){
    cin>>a;
    cout<<v[n-1-a]<<"\n" ;
  }
}
