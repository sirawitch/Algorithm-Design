#include<bits/stdc++.h>
int n,m,a,i,j;
using namespace std;
vector<int> A;
vector<pair<int,pair<int,int> > >sum;
bool b;
bool check(int val,int l,int r){
  if(l==r){
    if(sum[l].first==val&&sum[l].second.first!=j&&sum[l].second.second!=j)return true;
    return false;
  }
  if(sum[l].first<=val&&sum[r].first>=val){
    int md=(l+r)>>1;
    return check(val,l,md)||check(val,md+1,r);
  }
  return false;
}
main(){
  scanf("%d%d",&n,&m);
  for(i=0;i<n;++i){scanf("%d",&a); A.push_back(a);}
  for(i=0;i<n;++i){
    for(j=0;j<i;++j)sum.push_back({A[i]+A[j],make_pair(i,j)});
  }
  sort(sum.begin(),sum.end());
  for(i=0;i<m;++i){scanf("%d",&a); b=false;
    for(j=0;j<n;++j){
      if(check(a-A[j],0,sum.size()-1)){b=true; break;}
    }
    if(b)printf("YES\n");
    else printf("NO\n");
  }
}
