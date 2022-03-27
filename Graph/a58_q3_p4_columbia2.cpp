#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
using namespace std;
bool vs[3][441][441];
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  int m,n,a,b,c,d,V[441][441],dis[3][441][441];
  cin>>m>>n;
  priority_queue<pair<int,pair<int,pair<int,int> > > >pq;
  for(int i=0;i<m;++i){
    for(int j=0;j<n;++j){
      cin>>V[i][j];
      dis[0][i][j]=2e9;
      dis[1][i][j]=2e9;
      dis[2][i][j]=2e9;
    }
  }
  dis[0][0][0]=0;
  dis[1][0][0]=0;
  dis[2][0][0]=0;
  pq.push(mp(0,mp(0,mp(0,0))));
  while(!pq.empty()){
    a=pq.top().x;
    b=pq.top().y.x;
    c=pq.top().y.y.x;
    d=pq.top().y.y.y;
    pq.pop();
    if(vs[b][c][d])continue;
    vs[b][c][d]=true;
    if(c-1>=0&&!vs[b][c-1][d]&&dis[b][c-1][d]>dis[b][c][d]+V[c-1][d]){
      dis[b][c-1][d]=dis[b][c][d]+V[c-1][d];
      pq.push(mp(-dis[b][c-1][d],mp(b,mp(c-1,d))));
    }
    if(c+1<m&&!vs[b][c+1][d]&&dis[b][c+1][d]>dis[b][c][d]+V[c+1][d]){
      dis[b][c+1][d]=dis[b][c][d]+V[c+1][d];
      pq.push(mp(-dis[b][c+1][d],mp(b,mp(c+1,d))));
    }
    if(d-1>=0&&!vs[b][c][d-1]&&dis[b][c][d-1]>dis[b][c][d]+V[c][d-1]){
      dis[b][c][d-1]=dis[b][c][d]+V[c][d-1];
      pq.push(mp(-dis[b][c][d-1],mp(b,mp(c,d-1))));
    }
    if(d+1<n&&!vs[b][c][d+1]&&dis[b][c][d+1]>dis[b][c][d]+V[c][d+1]){
      dis[b][c][d+1]=dis[b][c][d]+V[c][d+1];
      pq.push(mp(-dis[b][c][d+1],mp(b,mp(c,d+1))));
    }
    if(b==2)continue;
    for(int i=1;i<=2;++i){
      if(c-i>=0&&!vs[b+1][c-i][d]&&dis[b+1][c-i][d]>dis[b][c][d]){
        dis[b+1][c-i][d]=dis[b][c][d];
        pq.push(mp(-dis[b+1][c-i][d],mp(b+1,mp(c-i,d))));
      }
      if(c+i<m&&!vs[b+1][c+i][d]&&dis[b+1][c+i][d]>dis[b][c][d]){
        dis[b+1][c+i][d]=dis[b][c][d];
        pq.push(mp(-dis[b+1][c+i][d],mp(b+1,mp(c+i,d))));
      }
      if(d-i>=0&&!vs[b+1][c][d-i]&&dis[b+1][c][d-i]>dis[b][c][d]){
        dis[b+1][c][d-i]=dis[b][c][d];
        pq.push(mp(-dis[b+1][c][d-i],mp(b+1,mp(c,d-i))));
      }
      if(d+i<n&&!vs[b+1][c][d+i]&&dis[b+1][c][d+i]>dis[b][c][d]){
        dis[b+1][c][d+i]=dis[b][c][d];
        pq.push(mp(-dis[b+1][c][d+i],mp(b+1,mp(c,d+i))));
      }
    }
    if(c-1>=0&&d-1>=0&&!vs[b+1][c-1][d-1]&&dis[b+1][c-1][d-1]>dis[b][c][d]){
      dis[b+1][c-1][d-1]=dis[b][c][d];
      pq.push(mp(-dis[b+1][c-1][d-1],mp(b+1,mp(c-1,d-1))));
    }
    if(c-1>=0&&d+1<n&&!vs[b+1][c-1][d+1]&&dis[b+1][c-1][d+1]>dis[b][c][d]){
      dis[b+1][c-1][d+1]=dis[b][c][d];
      pq.push(mp(-dis[b+1][c-1][d+1],mp(b+1,mp(c-1,d+1))));
    }
    if(c+1<m&&d-1>=0&&!vs[b+1][c+1][d-1]&&dis[b+1][c+1][d-1]>dis[b][c][d]){
      dis[b+1][c+1][d-1]=dis[b][c][d];
      pq.push(mp(-dis[b+1][c+1][d-1],mp(b+1,mp(c+1,d-1))));
    }
    if(c+1<m&&d+1<n&&!vs[b+1][c+1][d+1]&&dis[b+1][c+1][d+1]>dis[b][c][d]){
      dis[b+1][c+1][d+1]=dis[b][c][d];
      pq.push(mp(-dis[b+1][c+1][d+1],mp(b+1,mp(c+1,d+1))));
    }
  }
  for(int i=0;i<m;++i){
    for(int j=0;j<n;++j){
      cout<<min({dis[0][i][j],dis[1][i][j],dis[2][i][j]})<<" ";
    }cout<<"\n";
  }
}
