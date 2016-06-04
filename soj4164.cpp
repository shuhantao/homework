/*
 * =====================================================================================
 *
 *       Filename:  soj4164.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年05月16日 10时49分28秒
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

using namespace std;
const int maxn = 1000+6;
struct node {
  int x,y,num,cp;
  bool operator < (const node & n)const {
    return cp<n.cp;
  }
}nn[maxn];
int main(int argc, char *argv[])
{
  int N,A,B;
  while(scanf("%d%d%d",&N,&A,&B)!=EOF) {
    if(N==0&&A==0&&B==0) break; 
    for(int i=0;i<N;i++) scanf("%d%d%d",&nn[i].num,&nn[i].x,&nn[i].y);
    for(int i=0;i<N;i++) nn[i].cp = nn[i].x-nn[i].y;
    sort(nn,nn+N);
    int f=N;
    for(int i=0;i<N;i++) {
      if(nn[i].cp>0) {
        f=i;break;
      }
    }
    int ans = 0;
    for(int i=0;i<f;i++) {
      if(A>nn[i].num) {
        ans+=nn[i].x*nn[i].num;
        A-=nn[i].num;
      }
      else {
        ans+=nn[i].x*A+nn[i].y*(nn[i].num-A);
        B-=nn[i].num-A;
        A = 0;
      }
    }
    for(int i=N-1;i>=f;i--){
      if(B>nn[i].num) {
        ans+=nn[i].y*nn[i].num;
        B-=nn[i].num;
      }
      else {
        ans+=nn[i].y*B+nn[i].x*(nn[i].num-B);
        A-=nn[i].num-B;
        B=0;
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}

