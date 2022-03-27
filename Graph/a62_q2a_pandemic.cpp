#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
main(){
 ios_base::sync_with_stdio(false),cin.tie(0);
 int r,c,T,A[501][501],ans=0,x,y,z;
 queue<pair<int,pair<int,int> > >q;
 cin>>r>>c>>T;
 for(int i=0;i<r;++i){
   for(int j=0;j<c;++j){
    cin>>A[i][j];
    if(A[i][j]==1){
      q.push(mp(0,mp(i,j)));
    }
   }
 }
 while(!q.empty()){
  x=q.front().first;
  y=q.front().second.first;
  z=q.front().second.second;
  q.pop();
  if(x>=T)break;
  if(y>0){
    if(A[y-1][z]==0){ A[y-1][z]=1;
      q.push(mp(x+1,mp(y-1,z)));
    }
  }
  if(y<r-1){
    if(A[y+1][z]==0){
      A[y+1][z]=1; q.push(mp(x+1,mp(y+1,z)));
    }
  }
  if(z>0){
    if(A[y][z-1]==0){
      A[y][z-1]=1; q.push(mp(x+1,mp(y,z-1)));
    }
  }
  if(z<c-1){
    if(A[y][z+1]==0){
      A[y][z+1]=1;  q.push(mp(x+1,mp(y,z+1)));
    }
  }
 }
 for(int i=0;i<r;++i){
    for(int j=0;j<c;++j){
        if(A[i][j]==1)ans++;
    }
 }
 cout<<ans;
}
