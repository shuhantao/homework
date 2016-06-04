/*
 * =====================================================================================
 *
 *       Filename:  soj3385.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年06月04日 01时38分05秒
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
#include <string.h>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 9;
const int INF = 0x3f3f3f3f;
char num[maxn][maxn];
int  a[maxn][maxn];
int start[9][2]={0,0,0,3,0,6,3,0,3,3,3,6,6,0,6,3,6,6};
int pos[6][2];
bool h[9][10],l[9][10],g[9][10];
bool init(){
  memset(h,0,sizeof(h));
  memset(l,0,sizeof(l));
  memset(g,0,sizeof(g));
  for(int i=0;i<9;i++) {
    for(int j=0;j<9;j++) {
      if(a[i][j]==0) continue;
      if(h[i][a[i][j]]) return false;
      h[i][a[i][j]] = true;
    }
  }
  for(int i=0;i<9;i++) {
    for(int j=0;j<9;j++) {
      if(a[j][i]==0) continue;
      if(l[i][a[j][i]]) return false;
      l[i][a[j][i]] = true;
    }
  }
  for(int i=0;i<9;i++) {
    for(int j=0;j<3;j++) {
      for(int k=0;k<3;k++) {
        int x = start[i][0]+j;
        int y = start[i][1]+k;
        if(a[x][y]==0) continue;
        if(g[i][a[x][y]]) return false;
        g[i][a[x][y]] = true; 
      }
    }
  }
  return true;
}

bool check(int x,int y){
  if(h[x][a[x][y]]||l[y][a[x][y]]||g[x/3*3+y/3][a[x][y]]) return true;
  return false;
}
int totol;
bool ans;
void dfs(int x) {
  if(x==totol){
    ans = true;
    for(int i=0;i<9;i++) {
      for(int j=0;j<9;j++) {
        printf("%d",a[i][j]);
      }
      printf("\n");
    }
    return ;
  }
  int fx = pos[x][0];
  int fy = pos[x][1];
  for(int i=1;i<10;i++) {
      a[fx][fy] = i;
      if(!check(fx,fy)) {
        h[fx][a[fx][fy]] = true;
        l[fy][a[fx][fy]] = true;
        g[fx/3*3+fy/3][a[fx][fy]] = true;
        dfs(x+1);
        h[fx][a[fx][fy]] = false;
        l[fy][a[fx][fy]] = false;
        g[fx/3*3+fy/3][a[fx][fy]] = false;
      }
      a[fx][fy] = 0;
  }
}
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
#endif
  int T;
  cin>>T;
  while(T--) {
    memset(pos,0,sizeof(pos));
    totol = 0;
    ans = false;
    for(int i=0;i<9;i++) scanf(" %s",num[i]);
    for(int i=0;i<9;i++) {
      for(int j=0;j<9;j++) {
        a[i][j] = num[i][j]-'0';
        if(a[i][j]==0) {
          pos[totol][0] = i;
          pos[totol++][1] = j;
        }
      }
    }
    if(!init()){
      printf("Could not complete this grid.\n");
      if(T) printf("\n");
      continue;
    }
    dfs(0);
    if(!ans) {
      printf("Could not complete this grid.\n");
    }
    if(T) printf("\n");
  }
  return 0;
}

