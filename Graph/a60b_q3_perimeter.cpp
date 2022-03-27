#include<bits/stdc++.h>
using namespace std;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  int n,e,k,dis[1001],a,b,ans=0;
  cin>>n>>e>>k;
  vector<int> v[1001];
  queue<int> q;
  for(int i=0;i<=n;++i)dis[i]=2e9;
  dis[0]=0;
  while(e--){
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  q.push(0);
  while(!q.empty()){
    a=q.front();
    q.pop();
    for(auto it:v[a]){
      if(dis[it]>dis[a]+1){
        dis[it]=dis[a]+1; q.push(it);
      }
    }
  }
  for(int i=0;i<=n;++i){
    if(dis[i]==k)++ans;
  }
  cout<<ans;
}
