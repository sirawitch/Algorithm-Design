#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
int M[21],L[21];
vector<int> v;
int pos[21];
bool Mx,Lx;
void perm(int c){
  if(c==n){
    for(int it:v){
      printf("%d ",it);
    }
    printf("\n");
  }
  else{
    for(int i=0;i<n;++i){Mx=false; Lx=false;
      if(M[i]==-1)Mx=true;
      else if(pos[M[i]]==-1)Mx=true;
      if(L[i]==-1)Lx=true;
      else if(pos[L[i]]!=-1)Lx=true;
      if(pos[i]==-1&&Mx&&Lx){v.push_back(i); pos[i]= c;perm(c+1); pos[i]=-1;v.pop_back();}
    }
  }
}
main(){
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;++i){pos[i]=-1;M[i]=-1; L[i]=-1;}
  for(int i=0;i<m;++i){
    scanf("%d%d",&a,&b);
    M[a]=b; L[b]=a;
  }
  perm(0);
}
