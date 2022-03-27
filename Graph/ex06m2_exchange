#include<bits/stdc++.h>
using namespace std;
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  int k,n;
  double r[501][501];
  bool b;
  cin>>k;
  while(k--){b=false;
    cin>>n;
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
        cin>>r[i][j];
      }
    }
    for(int K=0;K<n;++K){if(b)break;
      for(int i=0;i<n;++i){if(b)break;
        for(int j=0;j<n;++j){
          if(b)break;
          if(r[i][j]<r[i][K]*r[K][j])r[i][j]=r[i][K]*r[K][j];
          if(i==j){
            if(r[i][i]>1)b=true;
          }
        }
      }
    }
    if(b)cout<<"YES\n";
    else cout<<"NO\n";
  }
}
