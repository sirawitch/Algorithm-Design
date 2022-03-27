#include<bits/stdc++.h>
using namespace std;
bool bl[100001];
int n,a,b,deg[100001],ans=0;
vector<int> v[100001];
queue<int>q;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>a>>b; v[a].push_back(b); v[b].push_back(a);
    deg[a]++;deg[b]++;
  }
  for(int i=0;i<n;++i){
    if(deg[i]==1)q.push(i);
  }
  while(!q.empty()){
    a=q.front();
    q.pop();
    if(bl[a])continue;
    bl[a]=true;
    for(auto &it:v[a]){
      if(bl[it]==true)continue;
      if(--deg[it]==1)q.push(it);
    }
  }
  for(int i=0;i<n;++i){
    if(deg[i]==2)++ans;
  }
  cout<<ans;
}
