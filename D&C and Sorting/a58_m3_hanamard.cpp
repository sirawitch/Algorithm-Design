#include<bits/stdc++.h>
using namespace std;
int n,a[262144];
vector<int> re(int lx,int ly,int rx,int ry){
    vector<int> ans;
    if(lx==rx){
      ans.push_back(a[ly]);
      return ans;
    }
    else if(lx+1==rx){
      ans.push_back(a[ly]+a[ry]);
      ans.push_back(a[ly]-a[ry]);
      return ans;
    }
    int mdx=(lx+rx)>>1;
    int mdy=(ly+ry)>>1;
    vector<int> v1=re(lx,ly,mdx,mdy);
    vector<int> v2=re(lx,mdy+1,mdx,ry);
    for(int i=lx;i<=mdx;++i)ans.push_back(v1[i]+v2[i]);
    for(int i=lx;i<=mdx;++i)ans.push_back(v1[i]-v2[i]);
    return ans;
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>a[i];
  }
  vector<int> ans=re(0,0,n-1,n-1);
  for(int i=0;i<n;++i){
    cout<<ans[i]<<" ";
  }
}
