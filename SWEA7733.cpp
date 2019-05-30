//
// Created by 전형진 on 2019-05-30.
//
#include <stdio.h>
#include <vector>
#include <queue>
#include <memory>
#include <algorithm>

using namespace std;

int n;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int map[101][101];
int visit[101][101];


void bfs(int y,int x){
    queue<int> xq;
    queue<int> yq;
    visit[y][x] = 1;
    xq.push(x);
    yq.push(y);

    while(!xq.empty()){
        int x = xq.front();
        int y = yq.front();
        xq.pop();yq.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx<n && ny >= 0 && ny < n
            && visit[ny][nx] ==0 && map[ny][nx] != 0){
                visit[ny][nx] = 1;
                xq.push(nx);
                yq.push(ny);
            }
        }
    }
}
int main() {
    vector<int> ve;
    int k = 0;
    int t;
    scanf("%d", &t);
    for (int l = 0; l < t; ++l) {


        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &map[i][j]);
            }
        }
        for (int d = 1; d <= 100; d++) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (map[i][j] == d) {
                        map[i][j] = 0;
                        visit[i][j] = 1;
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (map[i][j] != 0 && visit[i][j] == 0) {
                        bfs(i, j);
                        cnt++;
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    visit[i][j] = 0;
                }
            }
            if(cnt == 0)
                cnt = 1;
            ve.push_back(cnt);
            if (cnt == 0)
                break;
        }
        sort(ve.begin(), ve.end());
        printf("#%d %d",l+1,ve.back());
        printf("\n");
        ve.clear();
    }
}
