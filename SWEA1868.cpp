//
//// Created by 전형진 on 2019-07-13.
////
#include <stdio.h>
#include <queue>
#include <stdlib.h>


using namespace std;
int n;
char map[301][301];
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int sol[300][300];
int visit[300][300];
int temp[300][300];

void bfs(int y,int x){
    queue<int> xq;
    queue<int> yq;

    xq.push(x);
    yq.push(y);

    temp[y][x] = 1;

    while(!xq.empty()){
        int y = yq.front();
        int x = xq.front();
        yq.pop();xq.pop();

        for (int i = 0; i < 8; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx >= 0 && nx<n && ny>=0 && ny < n && sol[ny][nx] ==0
            &&temp[ny][nx] == 0){
                xq.push(nx);
                yq.push(ny);
                temp[ny][nx] = 1;
            }
        }
    }
}
int main(){
    int time;
    scanf("%d",&time);

    for (int test = 0; test <time; ++test) {


        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            scanf("%s", map[i]);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (map[i][j] == '*') {
                    sol[i][j] = 9;
                    continue;
                }
                for (int k = 0; k < 8; ++k) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                        map[ny][nx] == '*') {
                        cnt++;
                    }
                }
                sol[i][j] = cnt;

                if (sol[i][j] == 0) {
                    for (int c = 0; c < 8; ++c) {
                        int nx = j + dx[c];
                        int ny = i + dy[c];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && visit[ny][nx] == 0) {
                            visit[ny][nx] = 1;
                            visit[i][j] = 1;
                        }
                    }
                }
                cnt = 0;
            }
        }

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            printf("%d",sol[i][j]);
//        }
//        printf("\n");
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            printf("%d",sol[i][j]);
//        }
//        printf("\n");
//    }
        int tans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (sol[i][j] == 0 && temp[i][j] == 0) {
                    bfs(i, j);
                    tans++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visit[i][j] == 0 && sol[i][j] != 9)
                    ans++;
            }
        }
        printf("#%d %d\n",test+1, ans + tans);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                visit[i][j] =0;
                sol[i][j] = 0;
                temp[i][j] = 0;
            }
        }
    }
}
//#include <iostream>
//#include <cstring>
//#include <vector>
//using namespace std;
//
//// 8방향
//int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
//int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//
//char c[301][301];
//int map[301][301];
//int visit[301][301];
//vector<pair<int,int>> v;
//int n;
//int line = 1;
//
//void dfs(int x, int y)
//{
//    visit[x][y] = 1;
//
//    // 좌표가 0인 것들을 8방향으로 탐색하면서 영역을 넓혀감
//    for(int dir=0; dir<8; dir++)
//    {
//        int nx = x + dx[dir];
//        int ny = y + dy[dir];
//
//        if(nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny] == 1)
//            continue;
//
//        if(map[nx][ny] == 0) // 주위에 0이 있을 경우
//        {
//            dfs(nx, ny);
//        }
//        else
//        {
//            visit[nx][ny] = 1;
//        }
//    }
//}
//int main()
//{
//    int t;
//    scanf("%d", &t);
//
//    while(t--)
//    {
//        scanf("%d", &n);
//
//        memset(map, 0, sizeof(map));
//        memset(visit, 0, sizeof(visit));
//        v.clear();
//
//        for(int i=0; i<n; i++)
//            for(int j=0; j<n; j++)
//                scanf(" %c", &c[i][j]);
//
//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<n; j++)
//            {
//                for(int k=0; k<8; k++)
//                {
//                    // 지뢰 표시
//                    if(c[i][j] == '*')
//                    {
//                        map[i][j] = -1;
//                        visit[i][j] = 1;
//                    }
//
//                    // 8방향으로 탐색
//                    int nx = i + dx[k];
//                    int ny = j + dy[k];
//
//                    // 8방향에 존재하는 지뢰 개수 저장
//                    if(c[nx][ny] == '*' && c[i][j] != '*')
//                        map[i][j] = map[i][j] + 1;
//                }
//
//                // 해당 좌표가 0일 경우, 벡터에 추가
//                if(map[i][j] == 0)
//                    v.push_back(make_pair(i,j));
//            }
//        }
//
//        int click = 0;
//        //int click = v.size(); // 클릭 횟수 초기 값 = 0의 개수
//        for(int i=0; i<v.size(); i++)
//        {
//            int state = 0; // 8방향에 0이 존재했는지
//            int x = v[i].first;
//            int y = v[i].second;
//
//            if(visit[x][y] == 0)
//            {
//                dfs(x,y);
//                click = click+1;
//            }
//            /*
//            map[x][y] = -1;
//
//            // 좌표가 0인 것들을 8방향으로 탐색하면서 영역을 넓혀감
//            for(int dir=0; dir<8; dir++)
//            {
//                int nx = x + dx[dir];
//                int ny = y + dy[dir];
//
//                if(nx < 0 || ny < 0 || nx >= n || ny >= n || map[nx][ny] == -2)
//                    continue;
//
//                if(map[nx][ny] == 0) // 주위에 0이 있을 경우
//                {
//                    state = 1;
//                }
//                else
//                {
//                    // 주변에 지뢰가 존재하는 좌표에 닿았을 경우
//                    // 방문 표시
//                    if(map[nx][ny] != -1)
//                        map[nx][ny] = -2;
//                }
//            }
//
//            if(state == 1)
//                click = click - 1;*/
//        }
//        for (int i = 0; i <n ; ++i) {
//            for (int j = 0; j < n; ++j) {
//                printf("%d",visit[i][j]);
//            }
//            printf("\n");
//        }
//        // 0 주변 범위가 아니라서 탐색되지 않은 것들은
//        // 각각 클릭의 개수를 증가시켜줌
//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<n; j++)
//            {
//                if(visit[i][j] == 0)
//                    click = click + 1;
//            }
//        }
//
//        printf("#%d %d\n", line++, click);
//    }
//}