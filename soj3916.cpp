/*
 * =====================================================================================
 *
 *       Filename:  soj3916.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年05月16日 11时17分04秒
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
typedef long long ll;
const int maxn = 1e6+10;
ll a[maxn];
int main(){
  int N,M;
  while(scanf("%d%d",&N,&M)!=EOF) {
    ll sum = 0;
    for(int i=0;i<M;i++) {
      scanf("%lld",&a[i]);
      sum+=a[i];
    }
    sort(a,a+M);
    ll ans = 0;
    ll les = sum-N;
    if(les<0) les = 0;
    ll per = les/M;
    ll tmp = les%M;
    int i;
    for(i=0;i<M;i++) {
      if(a[i] < per) {
        ans+=a[i]*a[i];
        les-=a[i];
        per = les/(M-i-1);
        tmp = les%(M-i-1);
      }
      else break;
    }
    cout<<ans<<" "<<tmp<<" "<<per<<endl;
    ans+=per*per*(M-i-tmp) +(per+1)*(per+1)*tmp;
    cout<<ans<<endl;
  }
}
