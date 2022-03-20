#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
int r,c,x,y,z;
char C[105][105];
int dis[105][105];
queue<pair<int,pair<int,int>>>q;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>r>>c;
  for(int i=0;i<r;++i){
    cin>>C[i];
  }
  for(int i=0;i<r;++i){
    for(int j=0;j<c;++j){
      dis[i][j]=2e9;
    }
  }
  dis[0][0]=0;
  q.push(mp(0,mp(0,0)));
  while(!q.empty()){
    x=q.front().first;
    y=q.front().second.first;
    z=q.front().second.second;
    q.pop();
    if(y>0){
      if(dis[y-1][z]>x+1&&C[y-1][z]!='#'){
        dis[y-1][z]=x+1;
        q.push(mp(dis[y-1][z],mp(y-1,z)));
      }
    }
    if(y<r){
      if(dis[y+1][z]>x+1&&C[y+1][z]!='#'){
        dis[y+1][z]=x+1;
        q.push(mp(dis[y+1][z],mp(y+1,z)));
      }
    }
    if(z>0){
      if(dis[y][z-1]>x+1&&C[y][z-1]!='#'){
        dis[y][z-1]=x+1;
        q.push(mp(dis[y][z-1],mp(y,z-1)));
      }
    }
    if(z<c){
      if(dis[y][z+1]>x+1&&C[y][z+1]!='#'){
        dis[y][z+1]=x+1;
        q.push(mp(dis[y][z+1],mp(y,z+1)));
      }
    }
  }
  if(dis[r-1][c-1]==2e9)cout<<-1;
  else cout<<dis[r-1][c-1];
}
