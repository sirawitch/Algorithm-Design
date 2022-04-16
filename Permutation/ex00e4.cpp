#include<bits/stdc++.h>
int a,b;
int x[22];
void f(int len){
if(len==b){
    int c=0;
    for(int i=0;i<b;++i)if(x[i]==1)++c;
    if(c==a){for(int i=0;i<b;++i){printf("%d",x[i]);} printf("\n");}
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
