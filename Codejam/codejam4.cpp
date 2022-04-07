#include<bits/stdc++.h>
using namespace std;
vector<int> d,PM;
int t,f[1001],p[1001],deg[1001],n;
long long ans;
bool vs[1001],PMB[1001];
int dfs(int x){vs[x]=true;
    if(vs[p[x]]==true){
        return f[x];
    }
    else{
        return max(f[x],dfs(p[x]));
    }
}
void pm(int len){
    if(len==d.size()){
        long long A=0;
        for(int i=0;i<d.size();++i){
            A+=dfs(PM[i]);
        }
        ans=max(ans,A);
        for(int i=1;i<=n;++i)vs[i]=false;
    }
    else{
        for(int i=0;i<d.size();++i){
            if(!PMB[i]){
                PM.push_back(d[i]); PMB[i]=true;
                pm(len+1); PMB[i]=false; PM.pop_back();
            }
        }
    }
}
main(){
scanf("%d",&t);
for(int i=1;i<=t;++i){
    scanf("%d",&n);
    ans=0;
    for(int a=1;a<=n;++a){
        scanf("%d",&f[a]); deg[a]=0;
    }
    for(int a=1;a<=n;++a){
        scanf("%d",&p[a]);
         deg[p[a]]++;
    }
    for(int a=1;a<=n;++a){
        if(deg[a]==0)d.push_back(a);
    }
    pm(0);
    d.clear();
    printf("Case #%d: %lld\n",i,ans);
}
}
