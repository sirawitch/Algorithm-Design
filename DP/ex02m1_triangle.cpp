#include<bits/stdc++.h>
using namespace std;
int n,A[101][101],mx=0;
main(){
  cin>>n;
  for(int i=0;i<n;++i){
    for(int j=0;j<=i;++j){
      cin>>A[i][j];
      if(i==0);
      else if(j==0)A[i][j]+=A[i-1][0];
      else if(j==i)A[i][j]+=A[i-1][j-1];
      else A[i][j]+=max(A[i-1][j-1],A[i-1][j]);
      mx=max(mx,A[i][j]);
    }
  }
  cout<<mx;
}
