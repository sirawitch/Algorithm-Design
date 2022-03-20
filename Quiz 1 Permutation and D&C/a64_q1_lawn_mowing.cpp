#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a,b;
long long qs[500001],l,r,md;
bool check(long long x){
    if(a==0){
        if(qs[x]+(k)*(x+1)<=b)return true;
        return false;
    }
     if(qs[x]-qs[a-1]+k*(x-a+1)<=b)return true;
        return false;
}
main(){
scanf("%lld%lld%lld",&n,&m,&k);
for(long long i=0;i<n;++i){
    scanf("%lld",&qs[i]);
    if(i!=0)qs[i]+=qs[i-1];
}
for(long long i=0;i<m;++i){
    scanf("%lld%lld",&a,&b);
    if(a==0&&qs[0]+k>b){printf("0\n");continue;}
    else if(qs[a]-qs[a-1]+k>b){printf("0\n");continue;}
    l=a; r=n-1;
    while(l<r){
        md=(l+r+1)>>1;
        if(check(md))l=md;
        else r=md-1;
    }
    if(a==0)printf("%lld\n",qs[r]);
    else printf("%lld\n",qs[r]-qs[a-1]);
}
}
