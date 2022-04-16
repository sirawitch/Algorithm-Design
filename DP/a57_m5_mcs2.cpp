#include<stdio.h>
int n,a[100000],sum=0,mn=0,sum2=0,ans=-2e9,qs[100000],mx=-2e9;
main(){
  scanf("%d",&n);
  for(int i=0;i<n;++i){
    scanf("%d",&a[i]); sum+=a[i];
    qs[i]=sum;
    if(i!=0)if(mx<a[i])mx=a[i];
  }
  for(int i=0;i<n;++i){
    sum2+=a[i];
    if(mn<qs[i])mn=qs[i];
    if(ans<sum-(sum2-mn))ans=sum-(sum2-mn);
  }
  if(mx<0)printf("%d",mx);
  else printf("%d",ans);
}
