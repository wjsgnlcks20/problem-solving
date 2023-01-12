#include <bits/stdc++.h>

using namespace std;

int getPrefix(int n){
    int ret[4] = { n, 1, n + 1, 0 };
    return ret[n % 4];
}

void solve(){
    int S, F;
    cin >> S >> F;
    // xor[S, F] == xor[0, S - 1] ^ xor[0, F]
    cout << (getPrefix(S - 1) ^ getPrefix(F)) << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}