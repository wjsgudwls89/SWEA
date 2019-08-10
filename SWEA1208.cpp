//
//// Created by 전형진 on 2019-08-07.
////
//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//
//int arr[101];
//int main() {
//
//
//    int time;
//
//    for (int k = 0; k < 10; ++k) {
//
//
//        scanf("%d", &time);
//        for (int i = 0; i < 100; ++i) {
//            scanf("%d", &arr[i]);
//        }
//        sort(arr, arr + 100);
//        for (int j = 0; j < time; ++j) {
//            arr[99] -= 1;
//            arr[0] += 1;
//            sort(arr, arr + 100);
//        }
//        printf("#%d %d\n",k+1, arr[99] - arr[0]);
//    }
//}