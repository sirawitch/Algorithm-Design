#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
int p[1001],ans;
int root(int n){
  if(p[n]==n)return n;
  return p[n]=root(p[n]);
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  int n,A[1001][1001];
  vector<pair<int,pair<int,int> > >E;
  cin>>n;
  for(int i=0;i<n;++i){p[i]=i;
    for(int j=i+1;j<n;++j){
      cin>>A[i][j];
      E.push_back(mp(A[i][j],mp(i,j)));
    }
  }
  sort(E.begin(),E.end());
  for(auto &it:E){
    if(root(it.second.first)!=root(it.second.second)){
      ans+=it.first;
      p[root(it.second.first)]=root(it.second.second);
    }
  }
  cout<<ans;
}
