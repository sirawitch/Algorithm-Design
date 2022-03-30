#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
int n,a,b,x,y;
int p,q,r;
bool TB[1003][1003],vs[1003][1003];
int H[1003][1003],ans=2e9;
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin >> n >> a >> b;
  for(int i=0;i<n;++i){
    cin >> x >> y;
    TB[x][y]=true;
  }
  for(int i=0;i<=1000;++i){
    for(int j=0;j<=1000;++j)H[i][j]=2e9;
  }
  H[a][b]=0;
  pq.push(mp(0,mp(a,b)));
  while(!pq.empty()){
    p=pq.top().first;
    q=pq.top().second.first;
    r=pq.top().second.second;
    pq.pop();
    if(vs[q][r])continue;
    vs[q][r]=true;
    if(q==1||r==1||q==1000||r==1000){ans=min(ans,H[q][r]);continue;}
    if(!vs[q-1][r]&&H[q-1][r]>H[q][r]+1&&TB[q-1][r]){
      H[q-1][r]=H[q][r]+1;
      pq.push(mp(H[q-1][r],mp(q-1,r)));
    }
    if(!vs[q-1][r]&&H[q-1][r]>H[q][r]&&!TB[q-1][r]){
      H[q-1][r]=H[q][r];
      pq.push(mp(H[q-1][r],mp(q-1,r)));
    }
    if(!vs[q+1][r]&&H[q+1][r]>H[q][r]+1&&TB[q+1][r]){
      H[q+1][r]=H[q][r]+1;
      pq.push(mp(H[q+1][r],mp(q+1,r)));
    }
    if(!vs[q+1][r]&&H[q+1][r]>H[q][r]&&!TB[q+1][r]){
      H[q+1][r]=H[q][r];
      pq.push(mp(H[q+1][r],mp(q+1,r)));
    }
    if(!vs[q][r-1]&&H[q][r-1]>H[q][r]+1&&TB[q][r-1]){
      H[q][r-1]=H[q][r]+1;
      pq.push(mp(H[q][r-1],mp(q,r-1)));
    }
    if(!vs[q][r-1]&&H[q][r-1]>H[q][r]&&!TB[q][r-1]){
      H[q][r-1]=H[q][r];
      pq.push(mp(H[q][r-1],mp(q,r-1)));
    }
    if(!vs[q][r+1]&&H[q][r+1]>H[q][r]+1&&TB[q][r+1]){
      H[q][r+1]=H[q][r]+1;
      pq.push(mp(H[q][r+1],mp(q,r+1)));
    }
    if(!vs[q][r+1]&&H[q][r+1]>H[q][r]&&!TB[q][r+1]){
      H[q][r+1]=H[q][r];
      pq.push(mp(H[q][r+1],mp(q,r+1)));
    }
  }
  cout<<ans;
}