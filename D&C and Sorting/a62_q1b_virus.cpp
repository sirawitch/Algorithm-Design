#include<bits/stdc++.h>
int n,k,s=1;
int A[1000];
using namespace std;
bool c(int l,int r){
  bool b=false;
    if(r-l==1){
        if(A[l]==0&&A[l+1]==1)return true;
        else return false;
    }
    else{
    int md=(l+r)>>1;
    int md2=(md+l)>>1;
    b=c(l,md);
    if(!b){
      for(int i=l;i<=md2;++i)swap(A[i],A[md-i+l]);
      b=c(l,md);
      for(int i=l;i<=md2;++i)swap(A[i],A[md-i+l]);
    }
  if(b){
    return c(md+1,r);
  }
  return false;
  }
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>k;
  while(k--)s*=2;
  for(int i=0;i<n;++i){
    for(int j=0;j<s;++j){
      cin>>A[j];
    }
    if(c(0,s-1))cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
}
