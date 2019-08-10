////
//// Created by 전형진 on 2019-08-08.
////
//#include <stdio.h>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int N,M,K;
//
//int p;
//vector<int> arr;
//
//int main(){
//    int time;
//    scanf("%d",&time);
//    for (int t = 0; t < time; ++t) {
//        bool ans = false;
//        scanf("%d %d %d", &N, &M, &K);
//
//        for (int i = 0; i < N; ++i) {
//            scanf("%d",&p);
//            arr.push_back(p);
//        }
//        sort(arr.begin(), arr.end());
//
//        for (int i = 0; i < N; ++i) {
//            if (arr[i] / M * K < i + 1) {
//                ans = true;
//            }
//        }
//        arr.clear();
//        if (ans) {
//            printf("#%d Impossible\n",t+1);
//        } else {
//            printf("#%d Possible\n",t+1);
//        }
//    }
//}