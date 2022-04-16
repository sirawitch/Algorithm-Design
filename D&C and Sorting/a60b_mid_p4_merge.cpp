#include<bits/stdc++.h>
using namespace std;
int A[100000],i;
int n,k,ans=1;
void ms(int l,int r){
  if(l+1==r)return;
  if(ans==k)return;
  int md=(l+r)>>1;
  if(l+2==r){
    swap(A[l],A[l+1]); ans+=2; return;
  }
  if(ans+2==k){
    ans=k; swap(A[md-1],A[md]); return;
  }
  ans+=2;
  ms(l,md);
  ms(md,r);
}
main(){
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;++i)A[i-1]=i;
   ms(0,n);
   if(ans==k)for(int i=1;i<=n;++i)printf("%d ",A[i-1]);
   else printf("-1");
}
