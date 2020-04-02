//
// Created by 전형진 on 2020-04-02.
//
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;
int n,m,k;
int arr[10001];
int test;
double ans;
int main(){

    scanf("%d",&test);

    for (int t = 0; t < test; ++t) {
        memset(arr,0, sizeof(arr));
        scanf("%d %d",&n,&k);
        for (int i = 0; i < n; ++i) {
            scanf("%d",&arr[i]);
        }

        sort(arr,arr+n);
        ans = 0;
        for (int i = n-k; i < n ; ++i) {
            ans = (ans + arr[i])/2;
        }
        printf("#%d %.6lf\n",t+1,ans);
    }
}