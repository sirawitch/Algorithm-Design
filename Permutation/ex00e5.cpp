#include<bits/stdc++.h>
int a,b;
int x[22];
void f(int len){
if(len==a){
    int c=0,d=0;
    for(int i=0;i<a;++i){if(x[i]==1)d=std::max(d,++c);
    else c=0;
    }
    if(d>=b){for(int i=0;i<a;++i){printf("%d",x[i]);} printf("\n");}
    return ;
}
x[len]=0;
f(len+1);
x[len]=1;
f(len+1);
}
main(){
scanf("%d%d",&a,&b);
f(0);
}
