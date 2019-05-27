////
//// Created by 전형진 on 2019-05-27.
////
//
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//
//bool cmp(int x, int y){
//    if( x< y){
//        return false;
//    }
//    else
//        return true;
//}
//int map[101];
//using namespace std;
//
//vector<int> high;
//vector<int> low;
//
//int main(){
//    int t;
//    scanf("%d",&t);
//    for (int j = 0; j <t ; ++j) {
//        int n;
//        scanf("%d", &n);
//
//        for (int i = 0; i < n; ++i) {
//            scanf("%d", &map[i]);
//        }
//        for (int i = 0; i < n - 1; ++i) {
//            if (map[i] <= map[i + 1]) {
//                high.push_back(map[i + 1] - map[i]);
//            } else if (map[i] > map[i + 1]) {
//                low.push_back(map[i] - map[i + 1]);
//            }
//        }
//        if (low.empty())
//            low.push_back(0);
//        if (high.empty())
//            high.push_back(0);
//        sort(high.begin(), high.end(), cmp);
//        sort(low.begin(), low.end(), cmp);
//        printf("#%d %d %d", j+1,high[0], low[0]);
//        printf("\n");
//        low.clear();
//        high.clear();
//    }
//
//}