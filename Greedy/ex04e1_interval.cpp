#include<bits/stdc++.h>
using namespace std;
int n,a,ans=1,bef;
vector<int> v1;
vector<pair<int,int> >V;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>a; v1.push_back(a);
  }
  for(int i=0;i<n;++i){
    cin>>a;
    V.push_back({a,v1[i]});
  }
  sort(V.begin(),V.end());
  bef=V[0].first;
  for(int i=1;i<n;++i){
    if(bef<=V[i].second){
      ++ans; bef=V[i].first;
    }
  }
  cout<<ans;
}
