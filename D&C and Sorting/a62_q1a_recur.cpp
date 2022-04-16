#include<bits/stdc++.h>
int A[256][256],a,b,s=1;
void f(int a,int b,int lx,int ly,int rx,int ry){
  if(a==0)A[lx][ly]=b;
  else{
    int mdx=(lx+rx)>>1;
    int mdy=(ly+ry)>>1;
    f(a-1,b,lx,ly,mdx,mdy);
    f(a-1,b-1,lx,mdy+1,mdx,ry);
    f(a-1,b+1,mdx+1,ly,rx,mdy);
    f(a-1,b,mdx+1,mdy+1,rx,ry);
  }
}
main(){
  scanf("%d%d",&a,&b);
  for(int i=0;i<a;++i)s*=2;
  f(a,b,0,0,s-1,s-1);
  for(int i=0;i<s;++i){
    for(int j=0;j<s;++j){
      printf("%d ",A[i][j]);
    }printf("\n");
  }
}
