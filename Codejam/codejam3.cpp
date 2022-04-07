#include<bits/stdc++.h>
using namespace std;
main(){
int t,n,s,ans;
vector<int> v;
scanf("%d",&t);
for(int i=1;i<=t;++i){
    scanf("%d",&n);
    v.clear();
    ans=0;
    for(int a=0;a<n;++a){
        scanf("%d",&s);
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(int a=0;a<n;++a){
        if(v[a]>=ans+1)++ans;
    }
    printf("Case #%d: %d\n",i,ans);
}
}
