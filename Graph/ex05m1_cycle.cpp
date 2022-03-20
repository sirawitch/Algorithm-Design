#include<bits/stdc++.h>
using namespace std;
int B[1001];
vector<int> v[1001];
bool dfs(int u,int bef){
  B[u]=1;
  for(auto &it:v[u]){
    if(it!=bef){
      if(B[it]==2);
      else if(B[it]==1)return true;
      else if(dfs(it,u)==true)return true;
    }
  }
  B[u]=2;
  return false;
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
 int t,n,e,a,b,c;
 cin>>t;
  while(t--){
    for(int i=0;i<1000;++i){v[i].clear();B[i]=0;}
    cin>>n>>e;
    c=0;
    while(e--){
      cin>>a>>b;
      v[a].push_back(b); v[b].push_back(a);
    }
    for(int i=0;i<n;++i){
      if(B[i]==0){
        if(dfs(i,-1)){c=1; printf("YES\n");break;
        }
    }
    }
    if(c==1)continue;
    printf("NO\n");
  }
}
