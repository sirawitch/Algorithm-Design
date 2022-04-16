#include<stdio.h>
int f[45]={1,1},n,i;
main(){
  scanf("%d",&n);
  for(i=2;i<n;++i)f[i]=f[i-1]+f[i-2];
  printf("%d",f[n-1]);
}
