#include<bits/stdc++.h>
using namespace std;
int n,m,a[11],i;
int dp[11][10001];
bool b[11][10001];
vector<int> v;
queue<int> q,q2;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;++i){
    cin>>a[i];
  }
  for(int i=0;i<=100;++i){
    v.push_back(i*i);
  }
  for(int i=0;i<=n;++i){
    for(int j=0;j<=m;++j){
        dp[i][j]=2e9;
    }
  }
  for(int i=0;i<=n;++i){
    dp[i][0]=0;
  }
  q.push(0);
  for(int i=1;i<=n;++i){
    if(i%2==1){
    while(!q.empty()){
      if(b[i][q.front()]){q.pop(); continue;}
      b[i][q.front()]=true;
      for(int k=1;k<=100;++k){
        if(v[k]+q.front()>m)break;
        q2.push(q.front()+v[k]);
        dp[i][q.front()+v[k]]=min(dp[i][q.front()+v[k]],dp[i-1][q.front()]+(k-a[i])*(k-a[i]));
      }
      q.pop();
    }
    }
    else{
       while(!q2.empty()){
      if(b[i][q2.front()]){q2.pop(); continue;}
      b[i][q2.front()]=true;
      for(int k=1;k<=100;++k){
        if(v[k]+q2.front()>m)break;
        q.push(q2.front()+v[k]);
        dp[i][q2.front()+v[k]]=min(dp[i][q2.front()+v[k]],dp[i-1][q2.front()]+(k-a[i])*(k-a[i]));
      }
      q2.pop();
    }
    }
  }
  if(dp[n][m]==2e9)cout<<"-1";
  else cout<<dp[n][m];
}
