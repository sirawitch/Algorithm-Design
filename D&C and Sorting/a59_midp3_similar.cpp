#include<bits/stdc++.h>
using namespace std;
char s[131100],s2[131100];
int x,y;
bool check(int l1,int r1,int l2,int r2){
  if(l1==r1){
    if(s[l1]==s2[l2])return true;
    return false;
  }
  int md=(l1+r1)>>1;
  int md2=(l2+r2)>>1;
  if(check(l1,md,l2,md2)&&check(md+1,r1,md2+1,r2))return true;
  return check(l1,md,md2+1,r2)&&check(md+1,r1,l2,md2);
}
main(){
  ios_base::sync_with_stdio(false),cin.tie(0);
  cin>>s>>s2;
  x=strlen(s);
  if(check(0,x-1,0,x-1))cout<<"YES";
  else cout<<"NO";
}
