//
// Created by 전형진 on 2019-07-12.
//
#include <stdio.h>
#include <queue>

using namespace std;
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
int map[17][17];
int visit[17][17];
void bfs(int y, int x){
    queue<int> xq;
    queue<int> yq;

    xq.push(x);
    yq.push(y);
    visit[y][x] = 1;

    while(!xq.empty()){
        int y = yq.front();
        int x = xq.front();
        yq.pop();xq.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny >=0 && nx<16 && ny < 16 && visit[ny][nx] != 1){
                if(map[ny][nx] == 0) {
                    xq.push(nx);
                    yq.push(ny);
                    visit[ny][nx] = 1;
                }
                if(map[ny][nx] == 3){
                    xq.push(nx);
                    yq.push(ny);
                    visit[ny][nx] = 1;
                }
            }
        }
    }
}
int main(){
    for (int k = 0; k <10 ; ++k) {
        int num;
        scanf("%d",&num);

        int sx = 0, sy = 0;
        int ex = 0, ey = 0;
        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 16; ++j) {
                scanf("%1d", &map[i][j]);
                if (map[i][j] == 2) {
                    sx = j;
                    sy = i;
                }
                if (map[i][j] == 3) {
                    ex = j;
                    ey = i;
                }
            }
        }
        bfs(sy, sx);

        if (visit[ey][ex] == 1) {
            printf("#%d %d\n",num,1);
        } else
            printf("#%d %d\n",num,0);

        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 16; ++j) {
                visit[i][j] = 0;
            }
        }
    }
}