#include <bits/stdc++.h>

using namespace std;

void solve(){

    int n, x;
    cin >> n >> x;
    vector<int> h(2 * n);
    for(int i = 0; i < 2 * n; i++){
        cin >> h[i];
    }

    sort(h.begin(), h.end());
    for(int i = 0; i < n; i++){
        if(h[i] + x > h[i + n]) { cout << "NO\n"; return ;}
    }
    cout << "YES\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}