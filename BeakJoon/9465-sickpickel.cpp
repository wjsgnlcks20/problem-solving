#include <bits/stdc++.h>
#define Max 100001 

using namespace std;

int dp[Max][2];

void solve(){
    int n;
    cin >> n;
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < n; i++){
            cin >> dp[i][j];
        }
    }
    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + dp[i][0]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + dp[i][1]);
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc; 
    while(tc--) solve();
    return 0;
}