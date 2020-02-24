//
// Created by 전형진 on 2020-02-24.
//
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int visit[7];

struct CARD{
    int num;
    char c;
};
bool flag = true;
CARD rtemp[5];

CARD card[7];
bool cmp(const CARD &p1,const CARD &p2){
    return p1.num<p2.num;
}
int ans;
int rans = 0;

void TOP(CARD temp[]){
    ans = 0;
    flag = false;
    return;
}
void PA(CARD temp[]){
    for (int i = 0; i < 5; ++i) {
        int cnt = 0;
        for (int j = 0; j < 5; ++j) {
            if(temp[i].num == temp[j].num){
                cnt++;
                if(cnt == 2){
                        ans = 1;
                        flag = false;
                        return;
                    }
                }
            }
        }
    }
void TPA(CARD temp[]){
    int ch = 0;
    int k = 0 ;
    bool fin = true;
    for (int i = 0; i < 5; ++i) {
        int cnt = 0;
        if(!fin) break;
        for (int j = 0; j < 5; ++j) {
            if(temp[i].num == temp[j].num){
                cnt++;
                if(cnt == 2){
                    k = temp[i].num;
                    ch++;
                    fin = false;
                }
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        int cnt = 0;
        for (int j = 0; j < 5; ++j) {
            if(temp[i].num != k && temp[i].num == temp[j].num){
                cnt++;
                if(cnt == 2){
                    ch++;
                    if(ch == 2) {
                        ans = 2;
                        flag = false;
                        return;
                    }
                }
            }
        }
    }

}
void TR(CARD temp[]){

    for (int i = 0; i < 5; ++i) {
        int cnt = 0;
        for (int j = 0; j < 5; ++j) {
            if(temp[i].num == temp[j].num){
                cnt++;
                if(cnt == 3){
                   ans = 3;
                   flag = false;
                   return;
                }
            }
        }
    }
}
void ST(CARD temp[]){
    int cnt = 0;
    sort(temp,temp+5,cmp);
    for (int i = 0; i < 4; ++i) {
        if(temp[i].num == temp[i+1].num-1){
            cnt++;
        }
    }
    if(cnt == 4){
        ans = 4;
        flag = false;
        temp[4].num = 1;
        return;
    }
    cnt = 0;

    if(temp[0].num == 1) {
        temp[0].num = 14;
        sort(temp, temp + 5, cmp);
        for (int i = 0; i < 4; ++i) {
            if (temp[i].num == temp[i + 1].num - 1) {
                cnt++;
            }
        }
        if (cnt == 4) {
            ans = 4;
            flag = false;
            temp[4].num = 1;
            return;
        }
        temp[4].num = 1;
    }


}
void FL(CARD temp[]){
    char ch = temp[0].c;
    for (int i = 0; i < 5; ++i) {
        if(ch != temp[i].c){
            return;
        }
    }
    ans = 5;
    flag = false;
}
void FH(CARD temp[]){
    int ch = 0;
    int k = 0 ;
    bool fin = true;
    for (int i = 0; i < 5; ++i) {
        int cnt = 0;
        if(!fin) break;
        for (int j = 0; j < 5; ++j) {
            if(temp[i].num == temp[j].num){
                cnt++;
                if(cnt == 3){
                    k = temp[i].num;
                    ch++;
                    fin = false;
                }
            }
        }
    }
    if(ch == 0) return;
    for (int i = 0; i < 5; ++i) {
        int cnt = 0;
        for (int j = 0; j < 5; ++j) {
            if(temp[i].num != k && temp[i].num == temp[j].num){
                cnt++;
                if(cnt == 2){
                    ch++;
                    if(ch == 2) {
                        ans = 6;
                        flag = false;
                        return;
                    }
                }
            }
        }
    }

}
void FC(CARD temp[]){
    for (int i = 0; i < 5; ++i) {
        int cnt = 0;
        for (int j = 0; j < 5; ++j) {
            if(temp[i].num == temp[j].num){
                cnt++;
                if(cnt == 4){
                    ans = 7;
                    flag = false;
                    return;
                }
            }
        }
    }
}
void SF(CARD temp[]){

    char ch = temp[0].c;
    sort(temp,temp+5,cmp);
    for (int i = 0; i < 5; ++i) {
        if(ch != temp[i].c){
            return;
        }
    }

    if(temp[4].num - temp[0].num == 4){
        ans = 8;
        flag = false;
        return;
    }
    if(temp[0].num == 1) temp[0].num = 14;
    sort(temp,temp+5,cmp);

    if(temp[4].num - temp[0].num == 4){
        ans = 8;
        flag = false;

        return;
    }

}
void DFS(int depth,int start){
    if(depth == 5){
        flag = true;
        CARD temp[5];
        for (int i = 0; i < 5; ++i) {
            temp[i] = rtemp[i];
        }
        while(flag){
            SF(temp);
            if(!flag) break;
            FC(temp);
            if(!flag) break;
            FH(temp);
            if(!flag) break;
            FL(temp);
            if(!flag) break;
            ST(temp);
            if(!flag) break;
            TR(temp);
            if(!flag) break;
            TPA(temp);
            if(!flag) break;
            PA(temp);
            if(!flag) break;
            TOP(temp);
        }
        rans = max(ans,rans);
        //printf("%d",rans);
        return;
    }
    for (int i = start; i < 7; ++i) {
        if(!visit[i]){
            visit[i] = 1;
            rtemp[depth] = card[i];
            DFS(depth+1,i+1);
            visit[i] = 0;
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for (int time = 0; time < t; ++time) {
        rans = 0;
        ans = 0;
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < 7; ++i) {
            cin >> card[i].c >> card[i].num;
        }

        DFS(0, 0);
        switch (rans) {
            case 0: {
                cout <<"#"<<time+1<< " Top"<<endl;
                break;
            }
            case 1: {
                cout <<"#"<<time+1<< " 1 Pair"<<endl;
                break;
            }
            case 2: {
                cout <<"#"<<time+1<< " 2 Pair"<<endl;
                break;
            }
            case 3: {
                cout <<"#"<<time+1<< " Triple"<<endl;
                break;
            }
            case 4: {
                cout <<"#"<<time+1<< " Straight"<<endl;
                break;
            }
            case 5: {
                cout <<"#"<<time+1<< " Flush"<<endl;
                break;
            }
            case 6: {
                cout <<"#"<<time+1<< " Full House"<<endl;
                break;
            }
            case 7: {
                cout <<"#"<<time+1<< " 4 Card"<<endl;
                break;
            }
            case 8: {
                cout <<"#"<<time+1<< " Straight Flush"<<endl;
                break;
            }

        }
    }
}