#include<bits/stdc++.h>
using namespace std;
int n,m= 100000007;
int dp[2][3];
main(){
ios_base::sync_with_stdio(false),cin.tie(0);
cin>>n;
dp[1][0]=1;
dp[1][1]=1;
dp[1][2]=1;
for(int i=2;i<=n;++i){
    dp[i&1][0]=dp[(i+1)&1][0]+dp[(i+1)&1][1]+dp[(i+1)&1][2];
    dp[i&1][1]=dp[(i+1)&1][0]+dp[(i+1)&1][2];
    dp[i&1][2]=dp[(i+1)&1][0]+dp[(i+1)&1][1];
    dp[i&1][0]%=m;
    dp[i&1][1]%=m;
    dp[i&1][2]%=m;
}
cout<<(dp[n&1][0]+dp[n&1][1]+dp[n&1][2])%m;
}
