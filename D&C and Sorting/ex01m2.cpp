#include<stdio.h>
int A[100000],ans=0,B[100000],n,i,j,k;
void ms(int l,int r){
  if(l==r)return;
  int md=(l+r)>>1;
  ms(l,md);
  ms(md+1,r);
  i=l,j=md+1,k=l;
  while(i<=md||j<=r){
    if(i>md)B[k++]=A[j++];
    else if(j>r)B[k++]=A[i++];
    else if(A[i]<=A[j])B[k++]=A[i++];
    else{ans+=md-i+1;
      B[k++]=A[j++];
    }
  }
  for(i=l;i<=r;++i)A[i]=B[i];
}
int main(){
  scanf("%d",&n);
  for(i=0;i<n;++i)scanf("%d",&A[i]);
  ms(0,n-1);
  printf("%d",ans);
}
