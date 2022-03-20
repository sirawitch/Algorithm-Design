#include<bits/stdc++.h>
using namespace std;
int n,a=-5000,A[500001];
long long dp[500002][2],mn=0,ans=0,sum=0;
main()
{ios_base::sync_with_stdio(false), cin.tie(NULL);
cin>>n;
for(int i=1;i<=n;++i){
    cin>>A[i]; a=max(A[i],a);
    sum+=A[i];
    mn=min(mn,sum);
    dp[i][0]=max(sum-mn,dp[i-1][0]);
}
sum=0;
mn=0;
for(int i=n;i>=1;--i){
    sum+=A[i];
    mn=min(mn,sum);
    dp[i][1]=max(sum-mn,dp[i+1][1]);
}
for(int i=1;i<n;++i){
    ans=max(dp[i][0]+dp[i+1][1],ans);
}
if(a<=0)cout<<a;
else{cout<<ans;

}
}
