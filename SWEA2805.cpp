////
//// Created by 전형진 on 2019-08-10.
////
//#include <stdio.h>
//#include <cstring>
//int arr[50][50];
//
//int main(){
//    int test;
//    scanf("%d",&test);
//    for (int k = 0; k < test; ++k) {
//        int n;
//        int sum = 0;
//        memset(arr,0, sizeof(arr));
//        scanf("%d", &n);
//
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                scanf("%1d", &arr[i][j]);
//            }
//        }
//        int idx = n / 2;
//        int eidx = n / 2;
//
//        for (int i = 0; i < n; ++i) {
//            if (i < n / 2) {
//                if (idx == eidx) {
//                    sum += arr[i][idx];
//                    idx -= 1;
//                    eidx += 1;
//                    continue;
//                }
//                for (int j = idx; j <= eidx; ++j) {
//                    sum += arr[i][j];
//                }
//                idx -= 1;
//                eidx += 1;
//            } else {
//                if (idx == eidx) {
//                    sum += arr[i][idx];
//                    continue;
//                }
//                for (int j = idx; j <= eidx; ++j) {
//                    sum += arr[i][j];
//                    //printf("%d",sum);
//                }
//                idx += 1;
//                eidx -= 1;
//            }
//        }
//        printf("#%d %d\n",k+1, sum);
//    }
//}