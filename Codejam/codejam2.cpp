#include<bits/stdc++.h>
using namespace std;
int t;
int c[3],m[3],y[3],k[3];
int cm,mm,ym,km,ans;
main(){
    scanf("%d",&t);
    for(int i=1;i<=t;++i){
        cm=1e9,mm=1e9,ym=1e9,km=1e9; ans=1e6;
        for(int a=0;a<3;++a){
            scanf("%d%d%d%d",&c[a],&m[a],&y[a],&k[a]);
            cm=min(c[a],cm);
            mm=min(m[a],mm);
            ym=min(y[a],ym);
            km=min(k[a],km);
        }
        printf("Case #%d: ",i);
        if(cm+mm+ym+km<1e6){printf("IMPOSSIBLE\n");continue;}
        printf("%d ",cm);
        ans-=cm;
        if(ans<=mm){printf("%d ",ans); ans=0;}
        else {printf("%d ",mm); ans-=mm;}
        if(ans<=ym){printf("%d ",ans); ans=0;}
        else {printf("%d ",ym); ans-=ym;}
        if(ans<=km){printf("%d\n",ans); ans=0;}
        else {printf("%d\n",km); ans-=km;}
    }
}
