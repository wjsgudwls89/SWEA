//
// Created by 전형진 on 2019-10-16.
//
#include <stdio.h>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int mag[4][8];
int temp[4][8];
int t;
int getnum;
int dir;
int sum;
int visit[4];

void ccw(int idx){
    int te;
    queue<int> q;
    for (int i = 0; i < 8; ++i) {
        q.push(mag[idx][i]);
    }
    te = q.front();
    q.pop();
    mag[idx][7] = te;
    for (int i = 0; i < 7; ++i) {
        mag[idx][i] = q.front();
        q.pop();
    }
//      int temp = mag[idx][0];
//    for (int i = 0; i < 7; ++i) {
//        mag[idx][i] = mag[idx][i+1];
//    }
//    mag[idx][7] = temp;

}
void cw(int idx){
    int te;
    stack<int> s;
    for (int i = 0; i < 8; ++i) {
        s.push(mag[idx][i]);
    }
    te = s.top();
    s.pop();
    mag[idx][0] = te;
    for (int i = 7; i > 0; i--) {
        mag[idx][i] = s.top();
        s.pop();
    }
//      int temp = mag[idx][7];
//    for (int i = 0; i < 7; ++i) {
//        mag[idx][7-i] = mag[idx][6-i];
//    }
//    mag[idx][0] = temp;
}
int main() {
    int tk;
    scanf("%d", &tk);
    for (int k = 0; k < tk; ++k) {


        scanf("%d", &t);

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 8; ++j) {
                scanf("%d", &mag[i][j]);
            }
        }

        for (int i = 0; i < t; ++i) {
            memset(visit,0, sizeof(visit));
            scanf("%d %d", &getnum, &dir);
            visit[getnum - 1] = dir;
            for (int s = 0; s < 3; ++s) {
                if (getnum - 1 + s + 1 < 4 && visit[getnum - 1 + s] != 0 &&
                    mag[getnum - 1 + s][2] != mag[getnum - 1 + s + 1][6]) {
                    if (visit[getnum - 1 + s] == 1)
                        visit[getnum - 1 + s + 1] = -1;
                    else {
                        visit[getnum - 1 + s + 1] = 1;
                    }
                }
                if (getnum - 1 - s - 1 >= 0 && visit[getnum - 1 - s] != 0 &&
                    mag[getnum - 1 - s][6] != mag[getnum - 1 - s - 1][2]) {
                    if (visit[getnum - 1 - s] == 1)
                        visit[getnum - 1 - s - 1] = -1;
                    else {
                        visit[getnum - 1 - s - 1] = 1;
                    }
                }
            }
            for (int i = 0; i < 4; ++i) {
                if (visit[i] == 1) {
                    cw(i);
                }
                else if (visit[i] == -1) {
                    ccw(i);
                }
            }
        }
        sum = 0;

        if (mag[0][0] == 1)sum += 1;
        if (mag[1][0] == 1)sum += 2;
        if (mag[2][0] == 1)sum += 4;
        if (mag[3][0] == 1)sum += 8;

        printf("#%d %d\n",k+1, sum);
    }
}