//
// Created by 전형진 on 2020-04-02.
//
#include <math.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
int test;
long long n;

int sol(){
    int cnt = 0;

    while(n > 2) {
        long long k = sqrt(n);
        if(k * k == n){
            n = k;
            cnt ++;
        }
        else{
            cnt = cnt+pow(k+1,2) - n;
            n = pow(k+1,2);
        }
    }
    return cnt;
}
int main(){

    scanf("%d",&test);

    for (int t = 0; t < test; ++t) {
        cin>>n;
        printf("#%d %d\n",t+1, sol());
    }
}