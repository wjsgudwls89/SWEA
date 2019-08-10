////
//// Created by 전형진 on 2019-08-08.
////
//#include <stdio.h>
//#include <string>
//int arr[101];
//int dp[10000];
//int sum;
//int main(){
//    int time;
//    scanf("%d",&time);
//    for (int k = 0; k < time; ++k) {
//        memset(arr,0, sizeof(arr));
//        memset(dp,0,sizeof(dp));
//        int n;
//        scanf("%d", &n);
//        sum=0;
//        for (int i = 0; i < n; ++i) {
//            scanf("%d", &arr[i]);
//            sum += arr[i];
//        }
//        dp[0] = 1;
//        for (int i = 0; i < n; ++i) {
//            for (int j = sum; j >= 0; j--) {
//                if (dp[j]) {
//                    dp[j + arr[i]] = 1;
//                }
//            }
//        }
//        int cnt = 0;
//
//        for (int i = 0; i <= sum; ++i) {
//            if (dp[i])
//                cnt++;
//        }
//        printf("#%d %d\n",k+1,cnt);
//    }
//}