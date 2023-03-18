#include <bits/stdc++.h>

using namespace std;

long long lmin(long long a, long long b){
    return a < b ? a : b;
}

void solve(){
    int N;
    int min_diff = INT_MAX, min_diff_idx = 0;
    long long sum = 0, diff = 0, ans = LLONG_MAX;
    cin >> N;
    vector<int> p(N * 2);
    for (int i = 0; i < 2 * N; i++){
        cin >> p[i];
        sum += abs(p[i]);
    }
    ans = lmin(ans, sum);
    if (N == 1){
        ans = lmin(ans, abs(p[0] - p[1]));
        cout << ans << "\n";
        return ;
    }
    if (N == 2) {
        ans = lmin(ans, abs(p[0] - 2) + abs(p[1] - 2) + abs(p[2] - 2) + abs(p[3] - 2));
    }
    for (int i = 0; i < 2 * N; i++){
        diff += abs(p[i] - (-1));
        if (min_diff > abs(p[i] - N)){
            min_diff = abs(p[i] - N);
            min_diff_idx = i;
        }
    }
    diff -= abs(p[min_diff_idx] - (-1));
    diff += abs(p[min_diff_idx] - N);
    ans = lmin(ans, diff);
    cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}