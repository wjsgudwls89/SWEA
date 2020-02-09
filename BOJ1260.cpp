//
// Created by 전형진 on 2020-02-09.
//
#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
int visit[1001];
using namespace std;

vector<int> v[1001];
queue<int> q;
stack<int> s;
int n, m, start;
void DFS(int start){
    visit[start] = 1;
    s.push(start);
    printf("%d ",start);
    while(!s.empty()){
        int x = s.top();
        s.pop();
        sort(v[x].begin(),v[x].end());
        for (int i = 0; i < v[x].size(); ++i) {
           int nx = v[x][i];
           if(visit[nx] == 0){
               visit[nx] = 1;
               DFS(nx);
           }
           else{
               continue;
           }
        }
    }

}
void BFS(int start){

    visit[start] = 1;
    printf("%d ",start);
    q.push(start);

    while(!q.empty()){
        int x = q.front();
        sort(v[x].begin(),v[x].end());
        q.pop();


        for (int i = 0; i < v[x].size(); ++i) {
            int nx = v[x][i];
            if(visit[nx] == 0){
                visit[nx] = 1;
                q.push(nx);
                printf("%d ",nx);
            }
        }
    }


}
int main(){
    scanf("%d %d %d",&n,&m,&start);

    for (int i = 0; i < m; ++i) {
        int a1,a2;
        scanf("%d %d",&a1,&a2);
        v[a1].push_back(a2);
        v[a2].push_back(a1);
    }

    DFS(start);
    memset(visit,0, sizeof(visit));
    printf("\n");
    BFS(start);
}