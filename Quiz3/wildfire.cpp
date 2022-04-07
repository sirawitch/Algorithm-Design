#include<bits/stdc++.h>
using namespace std;
int n,m,k,b[5000],f[5000],u,v,sum=0;
void dfs(int x,vector<vector<int> > &G,vector<bool> &vs){
    sum-=b[x];
    vs[x]=true;
    for(auto &it:G[x]){
        if(!vs[it]){
            dfs(it,G,vs);
        }
    }
}
main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>m>>k;
    vector<vector<int> > G(n);
    vector<bool> vs(n);
    for(int i=0;i<n;++i){
        cin>>b[i]; sum+=b[i];
    }
    for(int i=0;i<k;++i){
        cin>>f[i];
    }
    for(int i=0;i<m;++i){
        cin>>u>>v;
        G[u].push_back(v);
    }
    for(int i=0;i<k;++i){
        if(!vs[f[i]]){
            dfs(f[i],G,vs);
        }
        cout<<sum<<" ";
    }
}
