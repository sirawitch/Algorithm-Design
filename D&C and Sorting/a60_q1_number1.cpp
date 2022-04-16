#include<bits/stdc++.h>
using namespace std;
long long bi[31],n,l,r;
long long ans=0;
long long A[31];
void f(long long ll,long long rr,int val,int i){
  int md=(ll+rr)>>1;
  if(val==1){
    ++ans;
    return;
  }
  if(ll<=i&&i<=md-1)f(ll,md-1,val>>1,i);
  else if(md+1<=i&&i<=rr)f(md+1,rr,val>>1,i);
  else if(md==i&&val%2==1)++ans;
}
main(){
  scanf("%lld%lld%lld",&n,&l,&r);
  A[0]=1; bi[0]=1;
  int i;
  for(i=1;i<=30;++i){bi[i]=bi[i-1]*2; A[i]=A[i-1]*2+1;}
  for(i=30;i>=0;--i){if(n>=bi[i]){break;}}
  long long x=A[i];
  for(int i=l;i<=r;++i)f(1,x,n,i);
  printf("%lld",ans);
}
