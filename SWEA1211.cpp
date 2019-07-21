////
//// Created by 전형진 on 2019-07-21.
////
//#include <stdio.h>
//#include <vector>
//#include <queue>
//#include <memory.h>
//#include <algorithm>
//using namespace std;
//
//struct Point{
//    int dis;
//    int index;
//};
//bool cmp(const Point &p1,const Point &p2){
//    if(p1.dis< p2.dis){
//        return true;
//    }
//    else if(p1.dis == p2.dis){
//        return p1.index > p2.index;
//    }
//    else
//        return false;
//}
//
//int map[101][101];
//int visit[101][101];
//
//int cnt = 0;
//void bfs(int y,int x){
//
//    queue<int> xq;
//    queue<int> yq;
//
//    xq.push(x);
//    yq.push(y);
//
//    visit[y][x] = 1;
//    cnt = 0;
//
//    while(!xq.empty()){
//        int x = xq.front();
//        int y = yq.front();
//        xq.pop();yq.pop();
//
//        int ny = y;
//        int nx = x;
//        if(ny>=0 && ny < 100 && nx >=0 && nx< 100
//        && map[ny][nx + 1] == 1 && visit[ny][nx+1] == 0){
//            xq.push(nx + 1);
//            yq.push(ny);
//            visit[ny][nx+1] = 1;
//            cnt++;
//
//        }
//        else if(ny>=0 && ny < 100 && nx >=0 && nx< 100
//                && map[ny][nx - 1] == 1 && visit[ny][nx-1] == 0){
//            xq.push(nx - 1);
//            yq.push(ny);
//            visit[ny][nx-1] = 1;
//            cnt++;
//
//        }
//        else if(ny>=0 && ny < 100 && nx >=0 && nx< 100
//                && map[ny+1][nx] == 1 && visit[ny+1][nx] == 0){
//            xq.push(nx);
//            yq.push(ny+1);
//            visit[ny+1][nx] = 1;
//            cnt++;
//        }
//    }
//    //printf("%d ",cnt);
//}
//int main() {
//    int test;
//    for (int t = 0; t < 10; ++t) {
//        scanf("%d",&test);
//
//        for (int i = 0; i < 100; ++i) {
//            for (int j = 0; j < 100; ++j) {
//                scanf("%d", &map[i][j]);
//            }
//        }
//        Point point[100];
//        int idx = 0;
//        for (int i = 0; i < 100; ++i) {
//            if (map[0][i] == 1) {
//                bfs(0, i);
//                point[idx].dis = cnt;
//                point[idx].index = i;
//                idx++;
//                memset(visit, 0, sizeof(visit));
//            }
//        }
//        sort(point, point + idx, cmp);
//        printf("#%d %d\n",test, point[0].index);
//        //    printf("\n");
////    for (int i = 0; i < 100; ++i) {
////        for (int j = 0; j < 100; ++j) {
////            printf("%d",map[i][j]);
////        }
////        printf("\n");
////    }
////    printf("\n");
////    for (int i = 0; i < 100; ++i) {
////        for (int j = 0; j < 100; ++j) {
////            printf("%d",visit[i][j]);
////        }
////        printf("\n");
////    }
//    }
//}