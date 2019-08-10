////
//// Created by 전형진 on 2019-08-08.
////
//#include <stdio.h>
//#include <vector>
//#include <stdlib.h>
//#include <string>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//string arr;
//int nmax;
//int n;
//int t;
//
//void swap(int y,int x){
//    int temp = arr[x];
//    arr[x] = arr[y];
//    arr[y] = temp;
//}
//void dfs(int cnt,int depth){
//    if(cnt == t){
//        nmax = max(nmax,stoi(arr));
//        return;
//    }
//    else{
//        for (int i = depth; i < arr.length(); ++i) {
//            for (int j = i; j < arr.length() ; ++j) {
//                if( i != j && arr[i] <= arr[j]){
//                    swap(i,j);
//                    dfs(cnt+1,i);
//                    swap(i,j);
//                }
//            }
//
//        }
//    }
//}
//int main(){
//    int i = 0;
//    scanf("%d",&i);
//    for (int time = 0; time < i; ++time) {
//        cin>>arr>>t;
//        nmax = stoi(arr);
//        dfs(0, 0);
//        printf("#%d %d",time+1, nmax);
//    }
//
//}
