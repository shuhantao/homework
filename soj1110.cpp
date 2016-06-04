/*
 * =====================================================================================
 *
 *       Filename:  soj1110.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  2016年06月04日 12时36分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
struct node {
  int x,y;
  int mp[4][4];
}beg,en;
int dir[4][2] = {0,1,1,0,0,-1,-1,0};
int fdir[4] = {2,3,0,1};
int maxDepth;
int count(node n) {
  int ans = 0;
  for(int i=0;i<4;i++) {
    for(int j=0;j<4;j++) {
      int t = n.mp[i][j]-1;
      if(t==-1) continue;
      ans += abs(i-t/4)+abs(j-t%4);
    }
  }
  return ans;
}
bool dfs(node &n,int depth,int h,int predir) {
  bool is = false;
  for(int i=0;i<4;i++) {
    for(int j=0;j<4;j++) {
      if(n.mp[i][j] != en.mp[i][j]) is = true;  
    }
  }
  if(!is)  return true;
  if(depth+h>maxDepth) return false;
  struct node Next;
  for(int i=0;i<4;i++) {
    if(i==predir) continue;
    Next = n;
    int fx = Next.x = n.x+dir[i][0];
    int fy = Next.y = n.y+dir[i][1];
    if(fx<0||fy<0||fx>=4||fy>=4) continue;
    swap(Next.mp[n.x][n.y],Next.mp[fx][fy]);
    int nexh = count(Next);
    if(dfs(Next,depth+1,nexh,fdir[i])) return true; 
  }
  return false;
}
int IDA() {
  int nh = count(beg);
  maxDepth = nh;
  while(!dfs(beg,0,nh,-1)) {
    maxDepth++;
  }
  return maxDepth;
}
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
#endif
  int nb = 1;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++) {
      en.mp[i][j] = nb++;
    }
  }
  en.mp[3][3]  = 0 ;
  en.x = en.y = 3;
  int T;
  cin>>T;
  while(T--) {
    for(int i=0;i<4;i++) {
      for(int j=0;j<4;j++) {
        scanf("%d",&beg.mp[i][j]);
        if(beg.mp[i][j]==0) {
          beg.x = i;
          beg.y = j;
        }
      }
    }
    printf("%d\n",IDA());
  }

  return 0;
}
