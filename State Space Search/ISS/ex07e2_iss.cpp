#include<bits/stdc++.h>
using namespace std;
int n,ans;
void iss(int sum,int bef){
  if(sum==n)++ans;
  for(int i=bef;i<=n;++i){
    if(i+sum>n)break;
    iss(sum+i,i);//next must >= before
  }
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n;
  iss(0,1);//least number to use is 1
  cout<<ans;
}
