#include<bits/stdc++.h>
using namespace std;
int f,w,n;
int A[10000],ans=1,tid;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>f>>w>>n;
  for(int i=0;i<f;++i){
    cin>>A[i];
  }
  sort(A,A+f);
  tid=A[0]+2*w;
  for(int i=0;i<f;++i){
    if(tid<A[i]){
      tid=A[i]+2*w; ++ans;
    }
  }
  cout<<ans;
}
