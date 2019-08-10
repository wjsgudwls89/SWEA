////
//// Created by 전형진 on 2019-07-30.
////
//#include <stdio.h>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//int arr[101][101];
//int visit[101];
//
//int ans;
//
//int main(){
//
//    int test;
//    int num;
//
//    for (int t = 0; t < 10; ++t) {
//        memset(arr,0, sizeof(arr));
//        memset(visit,0, sizeof(visit));
//        scanf("%d %d",&test,&num);
//        ans = 0;
//        for (int i = 0; i < num; ++i) {
//            int a, b;
//            scanf("%d %d", &a, &b);
//            arr[a][b] = 1;
//        }
//
//        queue<int> q;
//        q.push(0);
//        visit[0] = 1;
//
//        while(!q.empty()){
//            int x = q.front();
//            q.pop();
//
//            for (int i = 0; i < 101; ++i) {
//                if(arr[x][i] == 1){
//                    if(visit[i] == 0){
//                        if(i == 99)
//                            ans = 1;
//
//                        visit[i] = 1;
//                        q.push(i);
//                    }
//                }
//            }
//        }
//        printf("#%d %d\n",test, ans);
//    }
//}