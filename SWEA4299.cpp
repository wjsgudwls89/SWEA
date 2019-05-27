////
//// Created by 전형진 on 2019-05-24.
////
//#include <stdio.h>
//void sol(int i,int d, int h, int m){
//    int sum = 0;
//    int td = d - 11;
//    int th = h - 11;
//    int tm = m - 11;
//
//    sum = tm + (th * 60) + (td * 1440);
//    if(sum < 0)
//        printf("#%d -1\n",i+1);
//    else
//        printf("#%d %d\n",i+1,sum);
//}
//int main(){
//    int test;
//    int d,h,m;
//
//    scanf("%d",&test);
//
//    for (int i = 0; i < test; ++i) {
//        scanf("%d %d %d",&d,&h,&m);
//        sol(i,d,h,m);
//    }
//}