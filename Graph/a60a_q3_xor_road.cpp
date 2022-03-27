#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
int n,A[2001],p[2001];
long long ans=0;
vector<pair<int,pair<int,int> > >v;
int root(int x){
  if(p[x]==x)return x;
  else return p[x]=root(p[x]);
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>A[i]; p[i]=i;
  }
  for(int i=0;i<n;++i){
    for(int j=i+1;j<n;++j){
      v.push_back(mp(-(A[i]^A[j]),mp(i,j)));
    }
  }
  sort(v.begin(),v.end());
  for(auto &it:v){
    if(root(it.second.first)!=root(it.second.second)){
      ans-=it.first;
      p[root(it.second.first)]=p[root(it.second.second)];
    }
  }
  cout<<ans;
}
