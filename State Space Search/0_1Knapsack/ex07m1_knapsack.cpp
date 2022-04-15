#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
vector<pair<double,pair<double,double> > >item;// v/w,value,weight
priority_queue<pair<double,pair<double,pair<double,int> > > >pq;//Value+FKS,Weight remain,Value collect,position
double w,val,a,ans=0,suffix;
int n,i;
double fks(int start,double weight){//Fractional Knapsack from start to n-1
  double val=0;
  if(start==n)return 0;
  for(int i=start;i<n;++i){
    if(weight==0)break;
    if(weight<item[i].S.S){
      val+=item[i].F*weight; weight=0;
    }
    else{
      val+=item[i].S.F; weight-=item[i].S.S;
    }
  }
  return val;
}
main(){
  cin>>w>>n;
  item.resize(n);
  for(int i=0;i<n;++i){
    cin>>a;
    item[i].second.first=a;
  }
  for(int i=0;i<n;++i){
    cin>>a;
    item[i].second.second=a;
    item[i].first=item[i].second.first/a;
  }
  sort(item.begin(),item.end(),greater<pair<double,pair<double,double> > >());
  pq.push({0.0,{w,{0.0,0} } });
  while(!pq.empty()){
    a=pq.top().S.F;
    val=pq.top().S.S.F;
    i=pq.top().S.S.S;
    pq.pop();
    if(i==n){
      ans=max(ans,val); continue;
    }
    suffix=fks(i+1,a);
    if(val+suffix>ans){//don't choose this position
      pq.push({val+suffix,{a,{val,i+1} } });
    }
    if(a>=item[i].S.S){suffix=fks(i+1,a-item[i].S.S);//choose this position
      if(val+item[i].S.F+suffix>ans){
        pq.push({val+item[i].S.F+suffix,{a-item[i].S.S,{val+item[i].S.F,i+1} } });
      }
    }
  }
    cout << fixed << setprecision( 4 )<<ans;
}
