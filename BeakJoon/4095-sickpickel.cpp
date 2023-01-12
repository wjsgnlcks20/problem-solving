#include <bits/stdc++.h>

using namespace std;

int N, M;
void solve(){
    vector<vector<int>> arr(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        dp[i][0] = arr[i][0];
        ans = max(ans, arr[i][0]);
    }
    for(int i = 0; i < M; i++) {
        dp[0][i] = arr[0][i];
        ans = max(ans, arr[0][i]);       
    }
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < M; j++){
            if(arr[i][j]){
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(1) {
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        solve();
    }
    return 0;
}
