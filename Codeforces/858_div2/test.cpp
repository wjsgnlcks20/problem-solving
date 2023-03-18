#include <iostream>
#include <math.h>

using namespace std;

void dfs(int *arr, int *cur, int d, int sum){
    if (d == 8) {
        if (sum == 13) {
            int mult = 1, sum = 0;
            int mult2 = 1, sum2 = 0;
            for(int i = 0; i < 4; i++) {
                mult *= cur[i];
            }
            for(int i = 4; i < 8; i++) {
                sum += cur[i];
            }
            for(int i = 4; i < 8; i++) {
                mult2 *= cur[i];
            }
            for(int i = 0; i < 4; i++) {
                sum2 += cur[i];
            }
            if (mult == sum && mult2 == sum2){
                for(int i = 0; i < 8; i++) {
                    cout << cur[i] << " ";
                }
                cout << "\n";
            }
        }
        return ;
    }
    for (int i = -5; i < 5; i++){
        cur[d] = i;
        dfs(arr, cur, d + 1, sum + abs(cur[d] - arr[d]));
    }
}

int main(void){
    int arr[8] = { -3, -2, -1, 0, 1, 2, 3, 4 };
    int cur[8] = {};
    dfs(arr, cur, 0, 0);
    return 0;
}