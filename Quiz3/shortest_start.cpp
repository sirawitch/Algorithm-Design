#include<bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,k,v,s[5000],a,b,w,dis[5000],ans=2e9;
    vector<pair<int,pair<int,int> > >G;
    cin>>n>>m>>k;
    cin>>v;
    for(int i=0;i<n;++i)dis[i]=2e9;
    dis[v]=0;
    for(int i=0;i<k;++i){
        cin>>s[i];
    }
    for(int i=0;i<m;++i){
        cin>>a>>b>>w;
        G.push_back(make_pair(a,make_pair(b,w))); //Reverse graph
    }
    for(int i=0;i<n-1;++i){
        for(auto &it:G){
            if(dis[it.second.first]!=2e9&&dis[it.first]>dis[it.second.first]+it.second.second){
                dis[it.first]=dis[it.second.first]+it.second.second;
            }
        }
    }
    for(int i=0;i<k;++i){
        ans=min(ans,dis[s[i]]);
    }
    cout<<ans;
}
