//
// Created by 전형진 on 2019-07-15.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
using namespace std;
int map[5][5];
int arr[7];
char check[10000000];


vector<string> v;

string s;
void dfs(int y,int x,int cnt){
    arr[cnt] = map[y][x];
    if(cnt == 6){
        for (int i = 0; i <= cnt; ++i) {
            string c;
            c=to_string(arr[i]);
            s+=c;
        }
        int k = atoi(s.c_str());
        //v.push_back(s);
        check[k] = 1;
        //printf("%s\n",&s);
        s="";
        return;
    }
    else{
        for (int i = 0; i < 4; ++i) {
            int nx = x+ dx[i];
            int ny = y+ dy[i];

            if(nx >=0 && nx < 4 && ny>=0 && ny<4){
                dfs(ny,nx,cnt+1);
            }
        }

    }
}

int main(){
    int test;

    scanf("%d",&test);

    for (int i = 0; i < test ; ++i) {


        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                scanf("%d", &map[i][j]);
            }
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                dfs(i, j, 0);
            }
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < 10000000; ++i) {
            if(check[i] != 0)
                ans++;
        }
        printf("#%d %d\n",i+1,ans);
        for (int i = 0; i < 10000000; ++i) {
            check[i] = 0;
        }
    }

    }
