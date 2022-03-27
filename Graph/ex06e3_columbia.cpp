#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
bool vs[401][401];
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  int r,c,A[401][401];
  int dis[401][401],a,b;
  priority_queue<pair<int,pair<int,int> > >pq;
  cin>>r>>c;
  for(int i=0;i<r;++i){
    for(int j=0;j<c;++j){
      cin>>A[i][j]; dis[i][j]=2e9;
    }
  }
  dis[0][0]=0;
  pq.push(mp(0,mp(0,0)));
  while(!pq.empty()){
    a=pq.top().second.first;
    b=pq.top().second.second;
    pq.pop();
    if(vs[a][b])continue;
    vs[a][b]=true;
    if(a-1>=0&&!vs[a-1][b]&&dis[a-1][b]>dis[a][b]+A[a-1][b]){
      dis[a-1][b]=dis[a][b]+A[a-1][b];
      pq.push(mp(-dis[a-1][b],mp(a-1,b)));
    }
    if(a+1<r && !vs[a+1][b]&& dis[a+1][b]>dis[a][b]+A[a+1][b]){
dis[a+1][b]=dis[a][b]+A[a+1][b];
pq.push(mp(-dis[a+1][b],mp(a+1,b)));}
if(b-1>=0 && !vs[a][b-1] && dis[a][b-1]>dis[a][b]+A[a][b-1]){
dis[a][b-1]=dis[a][b]+A[a][b-1];
pq.push(mp(-dis[a][b-1],mp(a,b-1)));}
if(b+1<c && !vs[a][b+1]&& dis[a][b+1]>dis[a][b]+A[a][b+1]){
dis[a][b+1]=dis[a][b]+A[a][b+1];
pq.push(mp(-dis[a][b+1],mp(a,b+1)));}
  }
  for(int i=0;i<r;++i){
    for(int j=0;j<c;++j){
      cout<<dis[i][j]<<" ";
    }cout<<"\n";
  }
}
