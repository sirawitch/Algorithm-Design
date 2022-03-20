#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
using namespace std;
main(){
int k,m,n,i,j,gh,T,sr,sc,t,r,c,X=-1,A,B,C,D;
char s[105][105];
bool bl[2][105][105];
bool Ch=true;
vector<pair<int,pair<int,int> > >Gh;
queue<pair<int,pair<int,pair<int,int> > > >q;
scanf("%d",&k);
while(k--){
    scanf("%d%d%d%d%d%d",&m,&n,&gh,&T,&sr,&sc);
    while(!q.empty())q.pop();
    while(!Gh.empty())Gh.pop_back();
    for(i=0;i<gh;++i){
        scanf("%d%d%d",&t,&r,&c);
        Gh.emplace_back(-t,make_pair(r,c));
    }
    for(i=0;i<m;++i){
        scanf("%s",s[i]);
    }
    sort(Gh.begin(),Gh.end());
    for(i=0;i<m;++i){
        for(j=0;j<n;++j){
            bl[0][i][j]=false; bl[1][i][j]=false;
        }
    }Ch=true; X=-1;
    while(!Gh.empty()){
        if(Gh.back().F!=0)break;
        if(!bl[0][Gh.back().S.F][Gh.back().S.S]){
            bl[0][Gh.back().S.F][Gh.back().S.S]=true;
            q.emplace(0,make_pair(Gh.back().S.F,make_pair(Gh.back().S.S,1)));
        }
        Gh.pop_back();
    }
    if(bl[0][sr][sc]){
        printf("NO\n"); continue;
    }
    q.emplace(0,make_pair(sr,mp(sc,0)));
    while(!q.empty()){
        if(X!=q.front().F){
            X=q.front().F;
            if(Ch==false){
                printf("NO\n"); break;
            }
            if(X==T){
                printf("YES\n"); break;
            }
            Ch=false;
            while(!Gh.empty()){
            if(-Gh.back().F!=X+1)break;
            if(!bl[(X+1)%2][Gh.back().S.F][Gh.back().S.S]){
            bl[(X+1)%2][Gh.back().S.F][Gh.back().S.S]=true;
            q.emplace(X+1,make_pair(Gh.back().S.F,make_pair(Gh.back().S.S,1)));
        }
        Gh.pop_back();
        }
        }
    A=q.front().F; B=q.front().S.F; C=q.front().S.S.F; D=q.front().S.S.S;
    bl[A%2][B][C]=false;
    q.pop();
    if(!bl[(A+1)%2][B][C]){
            bl[(A+1)%2][B][C]=true;
        q.emplace(A+1,mp(B,mp(C,D))); if(D==0)Ch=true;
        }
    if(B>0){
        if(!bl[(A+1)%2][B-1][C]&&s[B-1][C]!='#'){
            bl[(A+1)%2][B-1][C]=true;
            q.emplace(A+1,mp(B-1,mp(C,D))); if(D==0)Ch=true;
        }
    }
    if(C>0){
        if(!bl[(A+1)%2][B][C-1]&&s[B][C-1]!='#'){
            bl[(A+1)%2][B][C-1]=true;
            q.emplace(A+1,mp(B,mp(C-1,D))); if(D==0)Ch=true;
        }
    }
    if(C<n-1){
        if(!bl[(A+1)%2][B][C+1]&&s[B][C+1]!='#'){
            bl[(A+1)%2][B][C+1]=true;
            q.emplace(A+1,mp(B,mp(C+1,D))); if(D==0)Ch=true;
        }
    }
    if(B<m-1){
        if(!bl[(A+1)%2][B+1][C]&&s[B+1][C]!='#'){
            bl[(A+1)%2][B+1][C]=true;
            q.emplace(A+1,mp(B+1,mp(C,D))); if(D==0)Ch=true;
        }
    }
    }
}
}
