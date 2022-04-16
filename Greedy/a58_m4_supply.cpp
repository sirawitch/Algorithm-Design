#include<bits/stdc++.h>
using namespace std;
int n,m,k,d,e,l,p=0;
vector<pair<int,pair<int,int> > >v;
queue<int> s,s2;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>n>>m>>k;
  for(int i=0;i<k;++i){
    cin>>d>>e>>l;
    v.push_back(make_pair(d,make_pair(e,l)));
  }
  sort(v.begin(),v.end());
  for(auto &it:v){
    if(it.second.first==0){
      s2.push(it.second.second);
      if(s.empty()||s2.empty())cout<<"0\n";
      else{
    cout<<s.front()<<"\n"; s.pop();s2.pop();}
    }
    else {
            s.push(it.second.second);
            if(s.empty()||s2.empty())cout<<"0\n";
            else{
            cout<<s2.front()<<"\n"; s2.pop(); s.pop();}
    }
  }
}
