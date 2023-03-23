#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long input;
    cin >> input;
    long long ans = sqrt(input);
    if (ans * ans == input) {
        ans -= 1;
    }
    cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}