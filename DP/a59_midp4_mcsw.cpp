#include<bits/stdc++.h>
using namespace std;
deque<pair<int,int> >dq;
int n,w,sum=0,a,ans=-2e9;
main(){
  cin>>n>>w;
  dq.push_back({0,-1});
  for(int i=0;i<n;++i){
    scanf("%d",&a);
    sum+=a;
    while(!dq.empty()){
      if(dq.front().second+w>=i)break;
      dq.pop_front();
    }
    if(ans<sum-dq.front().first){
      ans=sum-dq.front().first;
    }
    while(!dq.empty()){
      if(dq.back().first<sum)break;
      dq.pop_back();
    }
    dq.push_back({sum,i});
  }
  printf("%d",ans);
}
