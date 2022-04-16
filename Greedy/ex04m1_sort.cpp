#include<bits/stdc++.h>
using namespace std;
int ans=0;
int num[4],N=0;
vector<int> V,s;
main(){
  int n,a,b=0;
  vector<int>v;
  scanf("%d",&n);
  for(int i=0;i<n;++i){
    scanf("%d",&a); v.push_back(a);
    num[a]++;
    if(a==1)V.push_back(i);
  }
  for(int i=0;i<num[1];++i){
        s.push_back(v[i]);
    if(v[i]!=1){v[i]=1;
++ans;
    }
  }
  sort(s.begin(),s.end());
  int i=0;
  for(auto it:V){
      v[it]=s[i++];
  }
   for(int i=0;i<num[3];++i){
    if(v[n-i-1]!=3){++ans;
    }
  }
  cout<<ans;
}
