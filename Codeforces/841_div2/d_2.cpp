#include <bits/stdc++.h>

using namespace std;

int N, M;

int isPossible(int mid, vector<vector<int>> &arr){
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    int saveMax = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(arr[i][j] >= mid){
                dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
            }
            if(i >= mid - 1 && j >= mid - 1){
                saveMax = max(saveMax, dp[i][j]);
            }
        }
    }
    return saveMax >= mid;
}

void solve(){
    cin >> N >> M;
    vector<vector<int>> arr(N + 1, vector<int>(M + 1, 0));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> arr[i][j];
        }
    }
    int left = 0, right = min(N, M), ans = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        if(isPossible(mid, arr)){
            ans = mid; 
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
} 