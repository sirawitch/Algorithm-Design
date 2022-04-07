#include<bits/stdc++.h>
using namespace std;
int t,r,c;
main(){
    scanf("%d",&t);
    for(int i=1;i<=t;++i){
        scanf("%d%d",&r,&c);
        printf("Case #%d:\n",i);
        for(int a=0;a<r*2+1;++a){
            for(int b=0;b<c*2+1;++b){
                if(a==0&&b==0)printf(".");
                else if(a==0&&b==1)printf(".");
                else if(a==1&&b==0)printf(".");
                else if(a%2==0&&b%2==0)printf("+");
                else if(a%2==0&&b%2==1)printf("-");
                else if(a%2==1&&b%2==0)printf("|");
                else printf(".");
            }
            printf("\n");
        }
    }
}
