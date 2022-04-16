#include<bits/stdc++.h>
using namespace std;
int n,l,st=-1000,ans=0;
int A[50000];
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>l;
  for(int i=0;i<n;++i){
    cin>>A[i];
  }
  sort(A,A+n);
  for(int i=0;i<n;++i){
    if(st<A[i]){
      ++ans; st=A[i]+l-1;
    }
  }
  cout<<ans;
}
