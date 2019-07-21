////
//// Created by 전형진 on 2019-07-21.
////
//#include <stdio.h>
//#include <memory.h>
//int cow[100001];
//
//struct Qs{
//    int s;
//    int e;
//};
//Qs qs[100001];
//int cnum[3]={0};
//int count[3][100001];
//int main() {
//    int n;
//    int q;
//    int test;
//    int start,end;
//    scanf("%d", &test);
//    for (int t = 0; t < test; ++t) {
//
//
//        scanf("%d %d", &n, &q);
//
//        for (int i = 0; i < n; ++i) {
//            scanf("%d", &cow[i]);
//        }
//        for (int i = 0; i < n; ++i) {
//            if(cow[i] == 1){
//                cnum[0]++;
//            }
//            if(cow[i] == 2){
//                cnum[1]++;
//            }
//            if(cow[i] == 3){
//                cnum[2]++;
//            }
//            count[0][i+1] = cnum[0];
//            count[1][i+1] = cnum[1];
//            count[2][i+1] = cnum[2];
//        }
//        printf("#%d\n",t+1);
//        for (int i = 0; i < q; ++i) {
//            scanf("%d %d", &start, &end);
//            printf("%d %d %d\n",count[0][end] - count[0][start-1]
//            ,count[1][end] - count[1][start-1],count[2][end] - count[2][start-1]);
//        }
//        memset(cnum,0, sizeof(cnum));
//    }
//}