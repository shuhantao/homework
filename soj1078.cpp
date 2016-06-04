/*
 * =====================================================================================
 *
 *       Filename:  soj1078.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年05月16日 10时28分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;
const int maxn = 10000;
struct node {
  int s,t;
  bool operator < (const node &n)const {
    return t!=n.t?t<n.t:s<n.s;
  }
}nn[maxn];
int main()
{
  while(scanf("%d",&N)!=EOF&&N){
    for(int i=0;i<N;i++) scanf("%d%d",&nn[i].s,&nn[i].t);
    sort(nn,nn+N);
    int ans = 0,en = 0;
    // for(int i=0;i<N;i++) cout<<nn[i].s<<nn[i].t<<endl;
    for(int i=0;i<N;i++) {
      if(nn[i].s>=en) {
        ans++;
        en = nn[i].t;
      }
    }
    printf("%d\n",ans);
  }
}


