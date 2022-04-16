#include<stdio.h>
int n,m,a[1000],i;
long long x,l,r,mid;
bool c(long long k){
  long long sum=n;
  for(int i=0;i<n;++i){
    sum+=(k/a[i]);
  }
  if(sum>=x)return true;
  return false;
}
main(){
  scanf("%d%d",&n,&m);
  for(i=0;i<n;++i){
    scanf("%d",&a[i]);
  }
  for(i=0;i<m;++i){
    scanf("%lld",&x);
    l=0; r=1e18;
    while(l<r){
      mid=(l+r)>>1;
      if(c(mid))r=mid;
      else l=mid+1;
    }
    printf("%lld\n",l);
  }
}
