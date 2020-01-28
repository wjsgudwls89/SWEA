//
// Created by 전형진 on 2020-01-28.
//
#include <algorithm>
#include <stdio.h>
#include <cstring>

using namespace std;
int arr[50];
int n,k;
int main(){
    scanf("%d",&k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d",&arr[j]);
        }
        sort(arr,arr+n);
        printf("#%d ",i+1);
        for (int j = 0; j < n; ++j) {
            printf("%d ",arr[j]);
        }
        printf("\n");
        memset(arr,0, sizeof(arr));
    }
}