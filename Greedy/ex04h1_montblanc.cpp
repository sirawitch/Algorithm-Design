#include<bits/stdc++.h>
using namespace std;
int n,d,l=1,r=1000000000 ;
int A[100000];
bool C(int k){
  int N=k,D=1;
  for(int i=0;i<n;){
    if(N<A[i]){
      if(i==0)return false;
      i--;
      D++; N=A[i]+k;
    }
    else{
      ++i;
    }
    if(D>d)return false;
  }
  return true;
}
int X(int k){
  int N=k,D=1;
  for(int i=0;i<n;){
    if(N<A[i]){
      i--;
      D++; N=A[i]+k;
    }
    else{
      ++i;
    }
  }
  return D;
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>d;
  for(int i=0;i<n;++i){
    cin>>A[i];
  }
  while(l<r){
    int md=(l+r)>>1;
    if(C(md)){
      r=md;
    }
    else l=md+1;
  }
  cout<<l<<" "<<X(l);
}
