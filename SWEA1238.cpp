////
//// Created by 전형진 on 2019-07-30.
////
//#include <stdio.h>
//#include <queue>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int arr[101][101];
//int visit[101];
//vector <int> v[101];
//int cnt;
//
//int main(){
//
//    int start;
//    int num;
//
//    for (int t = 0; t < 10; ++t) {
//        memset(arr, 0, sizeof(arr));
//        memset(visit, 0, sizeof(visit));
//        for (int i = 0; i < 101; ++i) {
//            v[i].clear();
//        }
//        scanf("%d %d", &num, &start);
//
//
//        for (int i = 0; i < num / 2; ++i) {
//            int a, b;
//            scanf("%d %d", &a, &b);
//            arr[a][b] = 1;
//        }
//        cnt = 0;
//        queue<int> q;
//        q.push(start);
//        visit[start] = 1;
//
//        while (!q.empty()) {
//            int qs = q.size();
//            while (qs--) {
//                int x = q.front();
//                q.pop();
//
//                for (int i = 0; i < 101; ++i) {
//                    if (arr[x][i] == 1) {
//                        if (visit[i] == 0) {
//                            visit[i] = 1;
//                            q.push(i);
//                        }
//                    }
//                }
//                //printf("\ndepth: %d %d\n",cnt,x);
//                v[cnt].push_back(x);
//            }
//            cnt++;
//        }
//
//        int ans = 0;
//        for (int i = 0; i < v[cnt - 1].size(); ++i) {
//
//            // printf("%d ",v[cnt-1][i]);
//            //printf("%d",cnt);
//            ans = max(ans, v[cnt - 1][i]);
//        }
//        printf("#%d %d\n",t+1 , ans);
//    }
//}