#include<bits/stdc++.h>
int n,k,s=1;
int a,qs[300000],i,j;
bool c(int l,int r){
    if(l+1==r)return true;
    int md=(l+r)>>1;
    int a=qs[md]-qs[l-1];
    int b=qs[r]-qs[md];
    if(a!=b&&a!=b+1&&a+1!=b)return false;
    if(c(l,md)&&c(md+1,r))return true;
    return false;
}
main(){
scanf("%d%d",&n,&k);
while(k--)s*=2;
for(i=0;i<n;++i){
    qs[0]=0;
    for(j=1;j<=s;++j){
        scanf("%d",&a);
        qs[j]=qs[j-1]+a;
    }
    if(c(1,s))printf("yes\n");
    else printf("no\n");
}
}
