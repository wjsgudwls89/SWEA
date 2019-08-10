////
//// Created by 전형진 on 2019-07-31.
////
//#include <stdio.h>
//#include <algorithm>
//
//
//using namespace std;
//int n;
//
//
//struct TIME{
//    int a;
//    int b;
//    int c;
//};
//int test;
//
//TIME Time[400];
//
//bool cmp(const TIME &p1, const TIME &p2){
//    if(p1.c < p2.c){
//        return false;
//    }
//    else if (p1.c == p2.c){
//        return p1.a < p2.a;
//    }
//    else{
//        return true;
//    }
//}
//
//int main(){
//    scanf("%d",&test);
//
//    for (int l = 0; l < test; ++l) {
//
//        scanf("%d", &n);
//        int i;
//        for (i = 0; i < n; ++i) {
//            scanf("%d %d", &Time[i].a, &Time[i].b);
//            Time[i].c =Time[i].b - Time[i].a;
//        }
//        int k = 1;
//        printf("%d", i);
//
//        sort(Time,Time+i,cmp);
//        for (int m = 0; m < i; ++m) {
//            printf("%d ",Time[m].c);
//        }
//
//        for (int j = 0; j < i; ++j) {
//            if ((Time[j].a < Time[j + 1].a) &&
//                    (Time[j].b > Time[j + 1].a)) {
//                k++;
//                continue;
//            }
//
//        }
//        printf("#%d %d\n",l+1, k);
//
//        for (int m = 0; m < i; ++m) {
//            Time[m].a = 0;
//            Time[m].b = 0;
//            Time[m].c = 0;
//        }
//    }
//}