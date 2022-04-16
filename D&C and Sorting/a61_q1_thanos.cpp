#include<bits/stdc++.h>
using namespace std;
int p,k,a,b,d;
vector<int>v;
long long f(int l,int r){
  int low=lower_bound(v.begin(),v.end(),l)-v.begin();
  int high=upper_bound(v.begin(),v.end(),r)-v.begin();
  if(l==r){
    if(high!=low)return (long long)b*(long long)(high-low);
    return (long long)a;
  }
  int md=(l+r)>>1;
  long long ans1;
  if(high!=low)ans1=(long long)b*(long long)(r-l+1)*(long long)(high-low);
  else return (long long)a;
  return min(ans1,f(l,md)+f(md+1,r));
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>p>>k>>a>>b;
  for(int i=0;i<k;++i){
    cin>>d; v.push_back(d-1);
  }sort(v.begin(),v.end());
  d=1;
  for(int i=1;i<=p;++i)d*=2;
  cout<<f(0,d-1);
}
