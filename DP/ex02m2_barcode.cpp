#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int dp[31][31][31][2],i,j,x,y,ans=0;
//first ลำดับ
//second เปลี่ยนแล้วกี่รอบ
//third ซ้ำแล้วกี่ตัว
//fourth 0/1
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>m>>k;
  dp[0][0][1][0]=1;
  for(i=1;i<n;++i){
    for(j=0;j<=k;++j){
        for(x=1;x<=m;++x){
            if(j==0&&x==1);
            else if(j==0){
                dp[i][j][x][0]=dp[i-1][j][x-1][0];
            }
            else if(x==1){
                for(y=1;y<=m;++y){
                dp[i][j][1][0]+=dp[i-1][j-1][y][1];
                dp[i][j][1][1]+=dp[i-1][j-1][y][0];}
            }
            else{
                dp[i][j][x][0]+=dp[i-1][j][x-1][0];
                dp[i][j][x][1]+=dp[i-1][j][x-1][1];
            }
            if(i==n-1&&j==k)ans+=dp[i][j][x][0]+dp[i][j][x][1];
        }
    }
  }
  cout<<ans;
}
