#include<bits/stdc++.h>
using namespace std;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  int n,lis[1000],A[1000],mx=0;
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>A[i];
  }
  lis[0]=1;
  for(int i=1;i<n;++i){
    lis[i]=1;
    for(int j=0;j<i;++j){
      if(A[j]<A[i])lis[i]=max(lis[i],lis[j]+1);
    }
    mx=max(mx,lis[i]);
  }
  cout<<mx;
}
