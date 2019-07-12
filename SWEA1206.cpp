//
// Created by 전형진 on 2019-07-12.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[1001];
int n;
int sol = 0;
int main(){
    for (int k = 0; k < 10; ++k) {


        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }

        for (int i = 2; i < n - 2; ++i) {
            int sum = 99999;
            for (int j = i - 2; j <= i + 2; ++j) {
                int temp = 0;
                if (i==j)
                    continue;
                temp = arr[i] - arr[j];
                if (temp < 0) {
                    sum = 0;
                    break;
                }
                sum = min(temp, sum);

            }
            if (sum == 99999)
                continue;
            else {
               // printf("%d ", sum);
                sol += sum;
            }
        }

        printf("#%d %d\n",k+1, sol);
        sol=0;
    }
  //  sol=0;
}