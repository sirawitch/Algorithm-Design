#include<stdio.h>
long long a,c;
long long ans[32],bi[32];
long long f(int num){
    for(int i=31;i>=0;--i){
      if(num>=bi[i]){
        return (f(num-bi[i])*ans[i])%c;
      }
    }
    return 1;
}
main(){
  int b;
  scanf("%lld%d%lld",&a,&b,&c);
  a=a%c;
  ans[0]=a;
  bi[0]=1;
  for(int i=1;i<=31;++i){
    ans[i]=(ans[i-1]*ans[i-1])%c;
    bi[i]=bi[i-1]*2;
  }
  printf("%lld",f(b));
}
