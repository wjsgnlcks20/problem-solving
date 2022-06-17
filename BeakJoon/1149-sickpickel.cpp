#include <bits/stdc++.h>
#define INF 1000000

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, dp[3] = {}, tmp[3] = {};
    int red, green, blue;
    cin >> N;
    for(int i = 0; i < 3; i++) cin >> dp[i];

    for(int i = 1; i < N; i++){
        for(int j = 0; j < 3; j++) cin >> tmp[j];
        tmp[0] += min(dp[1], dp[2]);
        tmp[1] += min(dp[0], dp[2]);
        tmp[2] += min(dp[0], dp[1]);
        for(int j = 0; j < 3; j++) dp[j] = tmp[j];
    }

    int answer = INF;
    for(int j = 0; j < 3; j++) answer = min(answer, dp[j]);
    cout << answer << "\n";
    return 0;
}