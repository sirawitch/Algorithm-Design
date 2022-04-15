#include<iostream>
int n,ans=0;
bool col[12],UL[30],UR[30];//column use,diagon upleft use,diagon upright use
void rec(int len){
    if(len==n){++ans; return;}
    for(int i=0;i<n;++i){
        int ul=12+i-len,ur=i+len; //plus 12 to get positive(no array with negative index)
        if(!col[i]&&!UL[ul]&&!UR[ur]){
            col[i]=true;
            UL[ul]=true;
            UR[ur]=true;
            rec(len+1);
            col[i]=false;
            UL[ul]=false;
            UR[ur]=false;
        }
    }
}
main(){
    std::ios_base::sync_with_stdio(false),std::cin.tie(0);
    std::cin>>n;
    rec(0);
    std::cout<<ans;
}
