#include <bits/stdc++.h>
using namespace std;
int n,e,x,y;
vector<int>G[50],color(50);//Graph, color for each node(0 is don't color)
bool check(int index,int col){//dfs for check possible color
  if(index==n)return true;
  for(int i=1;i<=col;++i){
    bool ok=true;
    for(auto &it:G[index]){//check for can use this color?
      if(color[it]==i){
        ok=false;
        break;
      }
    }
    if(ok){
      color[index]=i;
      if(check(index+1,col))return true;
    }
  }
  color[index]=0; //reset color
  return false;
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>e;
  while(e--){
    cin>>x>>y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for(int i=1;i<=n;++i){
    if(check(0,i)){//start with node 0 and test for i color
      cout<<i; return 0;
    }
  }
}
