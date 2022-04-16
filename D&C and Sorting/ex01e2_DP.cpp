#include<stdio.h>
int n,A[100001],mn=0,ans=-2e9;
main(){
  scanf("%d",&n);
  for(int i=1;i<=n;++i){
    scanf("%d",&A[i]);
    A[i]+=A[i-1];
    if(mn>A[i-1])mn=A[i-1];
    if(A[i]-mn>ans)ans=A[i]-mn;
  }
  printf("%d",ans);
}
