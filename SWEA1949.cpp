//
// Created by 전형진 on 2020-05-01.
//
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;
int n,k;
int map[8][8];
int visit[8][8];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
struct POS{
    int y;
    int x;
};
int ans;
POS pos[5];
int DFS(int y,int x,int depth){
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(nx>=0 && ny>=0 && nx<n && ny < n &&(map[y][x] > map[ny][nx])){
            DFS(ny,nx,depth+1);
        }
    }
    ans = max(ans,depth);
    return ans;
}
int main(){
    int test;
    scanf("%d",&test);
    for (int t = 0; t < test; ++t) {
        scanf("%d %d",&n,&k);
        int mnum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d",&map[i][j]);
                mnum = max(mnum,map[i][j]);

            }
        }
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(map[i][j] == mnum){
                    pos[idx].y = i;
                    pos[idx].x = j;
                    idx++;
                }
            }
        }
        ans = 1;
        int temp = 0;
        int sol = 1;
        for (int l = 0; l < idx; ++l) {
            for (int m = 1; m <= k; ++m) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (i == pos[l].y && j == pos[l].x) continue;
                        map[i][j] -= m;
                        temp = DFS(pos[l].y, pos[l].x, 1);
                        map[i][j] += m;
                    }
                }
            }
            sol = max(sol,temp);
        }
        printf("#%d %d\n",t+1,sol);
    }
}