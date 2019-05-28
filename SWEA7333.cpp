//
// Created by 전형진 on 2019-05-28.
//
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int arr[102];
vector<int> v;
bool cmp(int x, int y){
    if(x<=y){
        return false;
    }
    else
        return true;
}

int main(){
    int t;
    scanf("%d",&t);
    for (int j = 0; j < t; ++j) {
        int cnt = 0;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
            v.push_back(arr[i]);
        }
        sort(v.begin(), v.end(), cmp);
        int size = n;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] >= 50) {
                n--;
                cnt++;
            } else {
                if (50 / v[i] - (double) 50 / v[i] == 0) {
                    if(n<50/v[i])
                        break;
                    n = n - (50 / v[i]);
                    cnt++;
                    if (n <= 0) {
                        break;
                    }
                } else {
                    if(n<(double)50/v[i])
                        break;
                    n = n - (50 / v[i]) - 1;
                    cnt++;
                    if (n <= 0) {
                        break;
                    }
                }
            }
            if(n==0){
                break;
            }
        }
        printf("#%d %d",j+1, cnt);
        printf("\n");
        v.clear();
    }
}
