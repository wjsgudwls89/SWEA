//
// Created by 전형진 on 2020-01-28.
//
#include <stdio.h>
#include <vector>
#include <cstring>


using namespace std;
int map[8][8];
int r, c, num,n;
int bw;
int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};
vector<pair<int,int>> v;

void fill(int bw){
    for (int i = 0; i < v.size(); ++i) {
        map[v[i].first][v[i].second] = bw;
    }
}

void dfs(int y,int x,int bw,int dir){
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(nx<0 || ny <0 || nx>=n || ny >=n) {
        v.clear();
        return;
    }
    if(map[ny][nx] == 0) {
        v.clear();
        return;
    }
    else if(map[ny][nx] == bw){
        fill(bw);

        v.clear();
        return;
    }
        v.push_back({ny,nx});
        dfs(ny,nx,bw,dir);
}

int main(){
    int tc;
    scanf("%d",&tc);
    for (int k = 1; k <= tc ; ++k) {
        memset(map,0, sizeof(map));
        scanf("%d %d", &n, &num);
        if (n == 4) {
            map[1][1] = 2;
            map[1][2] = 1;
            map[2][1] = 1;
            map[2][2] = 2;
        } else if (n == 6) {
            map[2][2] = 2;
            map[2][3] = 1;
            map[3][2] = 1;
            map[3][3] = 2;
        } else if (n == 8) {
            map[3][3] = 2;
            map[3][4] = 1;
            map[4][3] = 1;
            map[4][4] = 2;
        }
        for (int i = 0; i < num; ++i) {
            scanf("%d %d %d", &c, &r, &bw);
            map[r - 1][c - 1] = bw;
            for (int j = 0; j < 8; ++j) {
                dfs(r - 1, c - 1, bw, j);
            }
        }
        v.clear();
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <n; ++j) {
                    if(map[i][j] == 1) cnt1++;
                    else if(map[i][j] == 2) cnt2++;
            }
        }
        printf("#%d %d %d",k,cnt1,cnt2);
    }


}


