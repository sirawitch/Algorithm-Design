#include<bits/stdc++.h>
using namespace std;
int n;
float w;
float X[100001],Y[100001];
double ans=0;
priority_queue<pair<float,pair<float,float> > >pq;
main(){
  scanf("%f%d",&w,&n);
  for(int i=0;i<n;++i){
    scanf("%f",&X[i]);
  }
  for(int i=0;i<n;++i){
    scanf("%f",&Y[i]);
    pq.push(make_pair(X[i]/Y[i],make_pair(X[i],Y[i])));
  }
  while(!pq.empty()&&w>0){
    if(w>=pq.top().second.second){
      ans+=pq.top().second.first;
      w-=pq.top().second.second;
    }
    else{
      ans+=w*pq.top().first;
      w=0;
    }
    pq.pop();
  }
  printf("%.4lf",ans);
}
