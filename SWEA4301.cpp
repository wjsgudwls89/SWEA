//
// Created by 전형진 on 2019-05-31.
//
#include <stdio.h>
#include <vector>
int map[1001][1001];
//int visit[1001][1001];
int n,m;

int main(){
    int t;
    scanf("%d",&t);
    for (int k = 0; k < t; ++k) {


        int cnt = 0;
        scanf("%d %d", &m, &n);

            for (int i = 0; i < n; ++i) {
                if (i % 4 == 0) {
                    for (int j = 0; j < m; ++j) {
                        if (j % 4 == 2 || j % 4 == 3)
                            continue;
                        else {
                            map[i][j] = 1;
                            cnt++;
                        }
                    }
                }
                if (i % 4 == 1) {
                    for (int j = 0; j < m; ++j) {
                        if (j % 4 == 2 || j % 4 == 3)
                            continue;
                        else {
                            map[i][j] = 1;
                            cnt++;
                        }
                    }
                }
                if (i % 4 == 2) {
                    for (int j = 0; j < m; ++j) {
                        if (j % 4 == 0 || j % 4 == 1)
                            continue;
                        else {
                            map[i][j] = 1;
                            cnt++;
                        }
                    }
                }
                if (i % 4 == 3) {
                    for (int j = 0; j < m; ++j) {
                        if (j % 4 == 0 || j % 4 == 1)
                            continue;
                        else {
                            map[i][j] = 1;
                            cnt++;
                        }
                    }
                }
        }
        printf("#%d %d",k+1, cnt);
        printf("\n");
    }
}