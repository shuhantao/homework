/*=====================================================================================
 *
 *       Filename:  soj1106.cpp
 *
 *    Description:  <F2>
 *
 *        Version:  1.0
 *        Created:  2016年06月03日 22时13分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 * */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>

using namespace std;
int N,M;
const int maxn = 20+5;
char a[maxn][maxn];
struct node {
  int x,y,t;
  bool has;
}be,en;
int has[maxn][maxn];
const int INF = 0x3f3f3f3f;
int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
struct sv{
  int x,y;
  char c;
}svv[20*20+5];
void solve();
int main(){
//  freopen("out.txt","w",stdout);
//  freopen("in.txt","r",stdin);
  while(cin>>N>>M){
    cin>>be.x>>be.y;
    cin>>en.x>>en.y;
    int T;
    cin>>T;
    memset(a,0,sizeof(a));
    memset(svv,0,sizeof(svv));
    for(int i=0;i<T;i++) {
      cin>>svv[i].x>>svv[i].y>>svv[i].c;
      a[svv[i].x][svv[i].y] = '*';
    } 
    for(int i=0;i<T;i++) {
      if(svv[i].c == 'u') {
        for(int j=svv[i].x-1;j>0&& a[j][svv[i].y]!='*';j--) a[j][svv[i].y] = '#';
      }
      else if (svv[i].c == 'd'){
        for(int j=svv[i].x+1;j<=N&& a[j][svv[i].y]!='*';j++) a[j][svv[i].y] = '#';
      }
      else if (svv[i].c == 'l') {
        for(int j=svv[i].y-1;j>0&& a[svv[i].x][j] != '*';j--) a[svv[i].x][j] = '#';
      }
      else if (svv[i].c == 'r') {
        for(int j=svv[i].y+1;j<=M&& a[svv[i].x][j] != '*';j++) a[svv[i].x][j] = '#';
      }
    }
   /*    for(int i=1;i<=N;i++) {
      for(int j=1;j<=M;j++) {
        printf("%c",(a[i][j]==0?'1':a[i][j]));
      }
      puts("");
    }*/
    if(a[be.x][be.y]=='#'||a[be.x][be.y]=='*') {
      printf("-1\n");
    }else {
      solve();
    }
  }

  return 0;
}
void solve() {
  for(int i=0;i<=N ;i++ ) {
    for(int j=0;j<=M;j++) has[i][j] = INF;
  }
  int ans = INF;
  be.has = be.t = 0;
  queue<node> q;
  while(!q.empty()) q.pop();
  q.push(be);
  while(!q.empty()){
    struct node n = q.front();q.pop();
 //   cout<<n.x<<" "<<n.y<<endl;
    if(n.x==en.x&& n.y== en.y) ans= min(ans,n.t);
    for(int i=0;i<8;i++) {
      int fx = n.x + dir[i][0];
      int fy = n.y + dir[i][1];
 //     cout<<fx<<" "<<fy<<"**"<<endl;
      if(fx<=0 ||fx > N || fy <=0 ||fy > M) continue;
      if(a[fx][fy] == '*') continue;
      if(a[fx][fy] == '#' && n.has) continue;
      if(a[fx][fy] == '#') {
        if(has[fx][fy] <= n.t+1) continue;
        has[fx][fy] = n.t+1;
        struct node tmp = {fx,fy,n.t+1,true};
        q.push(tmp);
      }   
      else {
        if(has[fx][fy] <= n.t) continue;
        has[fx][fy] = n.t;        
        struct node tmp = {fx,fy,n.t,false};
        q.push(tmp);
      }
    }
  }
  if(ans != INF) {
    cout<<ans<<endl;
  }
  else cout<<-1<<endl;
}
