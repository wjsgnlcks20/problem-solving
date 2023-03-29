#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long lmin(long long a, long long b){
    return a < b ? a : b;
}

void solve(){
    int N;
    ll min_diff = LLONG_MAX, min_diff_idx = 0, sum = 0, diff = 0, ans = LLONG_MAX;
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
        ll save = 0;
        for (int i = 0; i < 4; i++){
            save += abs(p[i] - 2);
        }
        ans = lmin(ans, save);
    }
    if (N % 2 == 0){
        for (int i = 0; i < 2 * N; i++){
            diff += abs(p[i] - (-1));
            if (min_diff > abs(p[i] - N) - abs(p[i] + 1)){
                min_diff = abs(p[i] - N) - abs(p[i] + 1);
            }
        }
        diff += min_diff;
        ans = lmin(ans, diff);
    }
    cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}