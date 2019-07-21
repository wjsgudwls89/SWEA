//
// Created by 전형진 on 2019-07-21.
//
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int maxs = 0;
int dx[]=  {0,1,0,-1};
int dy[] = {1,0,-1,0};

char map[21][21];
int visit[21][21];
int wcount[100];
int r,c;

void dfs(int y,int x,int depth) {
    visit[y][x] = 1;
    if(wcount[map[y][x] - '@'] == 1) {
        return;
    }
    else{
        wcount[map[y][x]-'@']++;
        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 && ny >=0 && nx < c && ny < r && visit[ny][nx] == 0
            &&wcount[map[ny][nx] - '@'] == 0){
                dfs(ny,nx,depth+1);
                wcount[map[ny][nx] - '@'] = 0;
                visit[ny][nx] = 0;
            }
        }
    }
    maxs = max(depth,maxs);
}
int main(){
    int test;

    scanf("%d",&test);

    for (int t = 0; t < test; ++t) {


        scanf("%d %d", &r, &c);

        for (int i = 0; i < r; ++i) {
            scanf("%s", map[i]);
        }
        dfs(0, 0, 1);

        printf("#%d %d\n",t+1, maxs);
        maxs=0;
        memset(visit,0, sizeof(visit));
        //memset(map,0, sizeof(map));
        memset(wcount,0, sizeof(wcount));
    }
}