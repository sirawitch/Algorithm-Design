#include<bits/stdc++.h>
using namespace std;
int a,x,y,mov;
bool check;
map<vector<vector<int> >,int> m;
pair<int,int> dir[]={ {1,0},{-1,0},{0,1},{0,-1} },zeropos;
vector<vector<int> >temp(4),puzzle(4);
priority_queue<pair<int,vector<vector<int> > > >pq;
int error(vector<vector<int> >& v){
  int sum=0;
  for(int i=0;i<4;++i){
    for(int j=0;j<4;++j){
      if(v[i][j]==0)continue;
      sum+=abs((v[i][j]-1)/4-i)+abs((v[i][j]-1)%4-j);//distance from solution
    }
  }
  return sum;
}
main(){
  for(int i=0;i<4;++i){
    for(int j=0;j<4;++j){
      scanf("%d",&a);
      puzzle[i].push_back(a);
      temp[i].push_back(i*4+j+1);
    }
  }
  temp[3][3]=0;
  if(puzzle==temp){printf("0");return 0;}
  pq.push({-error(puzzle),puzzle});
  m[puzzle]=0;
  while(!pq.empty()){
    puzzle=pq.top().second;
    pq.pop();
    check=false;
    for(int i=0;i<=3;++i){//serch zero position
      for(int j=0;j<=3;++j){
        if(puzzle[i][j]==0){
          zeropos={i,j}; check=true; break;
        }
        if(check)break;
      }
    }
    mov=m[puzzle];
    for(int i=0;i<4;++i){
      x=zeropos.first+dir[i].first;
      y=zeropos.second+dir[i].second;
      if(x>=0&&x<=3&&y>=0&&y<=3){
        swap(puzzle[x][y],puzzle[zeropos.first][zeropos.second]);
        if(puzzle==temp){
          printf("%d",mov+1); return 0;
        }
        if(m.count(puzzle)==0){//if don't go to this state before then push the state
          pq.push({-mov-1-error(puzzle),puzzle});
          m[puzzle]=mov+1;
        }
        swap(puzzle[x][y],puzzle[zeropos.first][zeropos.second]);
      }
    }
  }
}
