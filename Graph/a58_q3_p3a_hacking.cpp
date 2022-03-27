#include<bits/stdc++.h>
using namespace std;
bool vs[100001];
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  int n,m,k,a,b,ans=0;
  int dis[100001];
  priority_queue<pair<int,int> >pq;
  vector<int> s,t,E[100001];
  cin>>n>>m>>k;
  for(int i=0;i<k;++i){
    cin>>a;
    s.push_back(a);
  }
  for(int i=0;i<n;++i){
    cin>>a;
    t.push_back(a);
    dis[i]=2e9;
  }
  for(int i=0;i<k;++i){
    pq.push({-t[s[i]],s[i]});
    dis[s[i]]=t[s[i]];
  }
  for(int i=0;i<m;++i){
    cin>>a>>b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  while(!pq.empty()){
    a=pq.top().first;
    b=pq.top().second;
    pq.pop();
    if(vs[b])continue;
    vs[b]=true;
    for(auto &it:E[b]){
      if(!vs[it]&&dis[it]>dis[b]+t[it]){
        dis[it]=dis[b]+t[it];
        pq.push({-dis[it],it});
      }
    }
  }
  for(int i=0;i<n;++i){
    ans=max(ans,dis[i]);
  }
  cout<<ans;
}
