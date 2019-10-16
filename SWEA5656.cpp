
// Created by 전형진 on 2019-10-16.
//
#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int map[16][12];
int smap[16][12];
int visit[16][12];
int check[12];
int n,h,w;
int sol;
int count(){
    int cnt = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(map[i][j] != 0){
                cnt++;
            }
        }
    }
    return cnt;
}

void spread(int y,int x){
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    if(map[y][x] == 1){
        visit[y][x] = 1;
        map[y][x] = 0;
        return;
    }
    else {
        while (1) {
            for (int j = 0; j <map[y][x] - 1; ++j) {

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < w && ny < h && map[ny][nx] != 0 &&visit[ny][nx] == 0) {
                        visit[ny][nx] = 1;
                        spread(ny, nx);
                    }
                }
                for (int i = 0; i < 4; ++i) {
                    if(dx[i] > 0)
                        dx[i]++;
                    else if(dx[i] < 0)
                        dx[i]--;
                    else if(dy[i] > 0)
                        dy[i]++;
                    else if(dy[i]< 0)
                        dy[i]--;
                }
            }
            visit[y][x] = 1;
            map[y][x] = 0;
            if(map[y][x] == 0)
                return;
        }
    }
}
void down(int th){
    stack<int> s;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            if (map[j][i] != 0) {
                s.push(map[j][i]);
                map[j][i] = 0;
            }
        }
        while (!s.empty()) {
            map[th][i] = s.top();
            s.pop();
            th--;
        }
        th = h-1;

    }

//    for (int k = 0; k < h; ++k) {
//        for (int l = 0; l < w; ++l) {
//            printf("%d ",map[k][l]);
//        }
//        printf("\n");
//    }
//    printf("\n");
}
void del(int idx){

    for (int j = 0; j < h; ++j) {
        if (map[j][idx] != 0) {
            spread(j, idx);
            down(h-1);
            return;
        }
    }
}


void dfs(int depth){
    if(depth == n){
        int ans;
        memcpy(map,smap, sizeof(map));
        for (int i = 0; i < n; ++i) {
            memset(visit,0, sizeof(visit));
            del(check[i]);
        }
        ans = count();
        sol = min(sol,ans);
        return;
    }
    else{
        for (int i = 0; i < w; ++i) {
            check[depth] = i;
            dfs(depth+1);
        }
    }
}
int main(){
    int time;
    scanf("%d",&time);
    for (int k = 0; k < time; ++k) {


        scanf("%d %d %d", &n, &w, &h);

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                scanf("%d", &smap[i][j]);
            }
        }
        sol = 9999;
        dfs(0);


        printf("#%d %d\n",k+1,sol);
    }

}