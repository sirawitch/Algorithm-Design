#include<bits/stdc++.h>
using namespace std;
int a,b,n,e,k;
vector<int>v[1001];
int num[1001],i;
bool B[1001];
void dfs(int u,int K){
  if(K>k)return;
  if(B[u]==false){num[i]++;}
  B[u]=true;
  for(auto &it:v[u]){
      dfs(it,K+1);
    }
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  int pos=-1;
  cin >> n >> e >> k;
  while(e--){
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(i=0;i<n;++i){
    for(int j=0;j<n;++j)B[j]=false;
    dfs(i,0);
    pos=max(pos,num[i]);
  }
  cout<<pos;
}
