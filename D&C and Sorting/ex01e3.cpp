#include<stdio.h>
int n,m,a[100000],i,x;
int check(int l,int r){
  while(l<r){
    int mid=(l+r+1)/2;
    if(a[mid]<x)l=mid;
    else if(a[mid]==x)return mid;
    else r=mid-1;
  }
  return r;
}
main(){
scanf("%d%d",&n,&m);
for(i=0;i<n;++i){
  scanf("%d",&a[i]);
}
for(i=0;i<m;++i){
  scanf("%d",&x);
  if(x<a[0])printf("-1\n");
  else printf("%d\n",a[check(0,n-1)]);
}
}
