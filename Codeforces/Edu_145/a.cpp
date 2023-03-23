#include <bits/stdc++.h>

using namespace std;

void solve(){
    string a;
    int mn = 0;
    int digitcnt[10] = {};
    cin >> a;
    for (int i = 0; i < a.size(); i++){
        digitcnt[a[i] - '0']++;
    }
    for (int i = 0; i < 10; i++){
        mn = max(mn, digitcnt[i]);
    }
    if (mn == 4){
        cout << "-1\n";
        return ;
    }
    int ans = 4;
    if (mn > 4 - mn + 1){
        ans += (mn - (4 - mn + 1)) * 2;
    }
    cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}