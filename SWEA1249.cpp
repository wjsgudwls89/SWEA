////
//// Created by 전형진 on 2019-08-07.
////
//#include <stdio.h>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int map[101][101];
//int dx[] = {1,0,-1,0};
//int dy[] = {0,1,0,-1};
//int visit[101][101];
//int n;
//void bfs(int y,int x){
//    queue<int> xq;
//    queue<int> yq;
//
//    xq.push(x);
//    yq.push(y);
//
//    visit[y][x] = 0;
//
//    while(!xq.empty()){
//        int x = xq.front();
//        int y = yq.front();
//        xq.pop();yq.pop();
//
//        for (int i = 0; i < 4; ++i) {
//            int nx = x+dx[i];
//            int ny = y+dy[i];
//
//            if(nx>=0 && ny>=0 && nx<n && ny<n){
//                if(visit[ny][nx] > (visit[y][x]+map[ny][nx])){
//                    visit[ny][nx] = visit[y][x]+map[ny][nx];
//                    xq.push(nx);
//                    yq.push(ny);
//                    //printf("%d ",visit[ny][nx]);
//                }
//            }
//        }
//    }
//
//}
//
//int main(){
//    int time;
//    scanf("%d",&time);
//    for (int k = 0; k < time; ++k) {
//
//
//        scanf("%d", &n);
//
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                scanf("%1d", &map[i][j]);
//            }
//        }
//        for (int j = 0; j < n; ++j) {
//            for (int a = 0; a < n; ++a) {
//               visit[j][a] = 9999;
//            }
//        }
//        visit[0][0] = 0;
//        bfs(0, 0);
//        printf("#%d %d\n",k+1, visit[n-1][n-1]);
//
//    }
//}