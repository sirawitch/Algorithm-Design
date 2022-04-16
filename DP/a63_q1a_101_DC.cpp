#include<bits/stdc++.h>
long long n,dp[41][4][4];
long long v[4],s[41],m=100000007 ;
long long base[4][4],c[4][4],sum=0;
main(){
  std::cin>>n;
  n-=2;
  dp[0][0][0]=1;
  dp[0][0][3]=1;
  dp[0][1][0]=1;
  dp[0][2][1]=1;
  dp[0][2][3]=1;
  dp[0][3][1]=1;
  dp[0][3][3]=1;
  base[0][0]=1;
  base[1][1]=1;
  base[2][2]=1;
  base[3][3]=1;
  v[0]=1;;
  v[1]=1;
  v[2]=1;
  v[3]=1;
  v[4]=1;
  s[0]=1;
  for(int i=1;i<=40;++i){
    s[i]=s[i-1]*2;
    for(int x=0;x<4;++x){
      for(int y=0;y<4;++y){
        for(int z=0;z<4;++z){
          dp[i][x][y]+=(dp[i-1][x][z]*dp[i-1][z][y]);
        }
      }
    }
    for(int x=0;x<4;++x)for(int y=0;y<4;++y)dp[i][x][y]%=m;
  }
  for(int i=40;i>=0;--i){
    if(n>=s[i]){
      n-=s[i];
      for(int x=0;x<4;++x)for(int y=0;y<4;++y)c[x][y]=0;
      for(int x=0;x<4;++x){
      for(int y=0;y<4;++y){
        for(int z=0;z<4;++z){
          c[x][y]+=(dp[i][x][z]*base[z][y]);
        }
      }
    }
    for(int x=0;x<4;++x){
      for(int y=0;y<4;++y){base[x][y]=c[x][y]%m;}
    }
  }}
  for(int x=0;x<4;++x){
    for(int y=0;y<4;++y){
      sum+=base[x][y]*v[y];
    }
  }
  std::cout<<sum%100000007 ;
}
