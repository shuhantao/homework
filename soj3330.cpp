/*
 * =====================================================================================
 *
 *       Filename:  soj3330.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年06月04日 00时36分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
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
int dir[4][2] = {1,0,0,-1,0,1,-1,0};
struct node {
  int x,y,t;
  node (int xx,int yy,int tt) {
    t = tt;
    y = yy;
    x = xx;
  }
};
int N,M;
const int maxn = 1000+5;
int a[maxn][maxn];
const int INF = 0x3f3f3f3f;
int solve() {
  queue<node> q;
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      if(a[i][j]) q.push(node(i,j,0));
    }
  }
  int ans = 0;
  while (!q.empty()) {
    struct node n = q.front();
    q.pop();
    for(int i=0;i<4;i++) {
      int fx = n.x + dir[i][0];
      int fy = n.y + dir[i][1];
      if(fx<0||fy<0||fx>=N||fy>=M||a[fx][fy]) continue;
      if(a[fx][fy] == 0) ans+=n.t+1;
      a[fx][fy] = 1;
      q.push(node(fx,fy,n.t+1));
    }
  }
  return ans;

}
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
#endif
  int T;
  cin>>T;
  while(T--){
    cin>>N>>M;
    for(int i=0;i<N;i++) {
      for(int j=0;j<M;j++) 
        scanf("%d",&a[i][j]);
    }
    cout<<solve()<<endl;

  }
  return 0;
}
