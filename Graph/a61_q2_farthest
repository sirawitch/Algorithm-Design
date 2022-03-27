#include<bits/stdc++.h>
using namespace std;
bool vs[1001];
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  int n,a,dis[1000],ans=0;
  vector<pair<int,int> >v[1001];
  priority_queue<pair<int,int> >pq;
  bool check=false;
  cin>>n;
  for(int i=0;i<n;++i){dis[i]=2e9;
    for(int j=0;j<n;++j){
      cin>>a;
      if(i==j)continue;
      if(a==-1)continue;
      v[i].push_back({j,a});
    }
  }
  dis[0]=0;
  pq.push({0,0});
  while(!pq.empty()){
    a=pq.top().second;
    pq.pop();
    if(vs[a])continue;
    vs[a]=true;
    for(auto &it:v[a]){
      if(!vs[it.first]&&dis[it.first]>dis[a]+it.second){
        dis[it.first]=dis[a]+it.second;
        pq.push({-dis[it.first],it.first});
      }
    }
  }
  for(int i=0;i<n;++i){
    if(dis[i]==2e9){check=true; break;}
    else ans=max(ans,dis[i]);
  }
  if(check)cout<<-1;
  else cout<<ans;
}
