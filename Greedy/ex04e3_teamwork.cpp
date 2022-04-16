#include<bits/stdc++.h>
using namespace std;
int n,m,a,S[100001];
vector<int>v;
double ans=0;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  std::cout << std::fixed;
  std::cout << std::setprecision(3);
  cin>>n>>m;
  for(int i=1;i<=m;++i){
    cin>>a; v.push_back(a);
  }
  sort(v.begin(),v.end());
  for(int i=0;i<min(m,n);++i){
    S[i]=v[i];
    ans+=S[i];
  }
  for(int i=n;i<m;++i){
    S[i]=S[i-n]+v[i];
    ans+=S[i];
  }
  cout<<ans/m;
}
