#include <bits/stdc++.h>
#define Max 101

using namespace std;

void solve(){
    int n, a_i, first, answer = 1;
    cin >> n;
    cin >> first;
    for(int i = 1; i < n; i++){
        cin >> a_i;
        if(a_i % first) answer = 0;
    }
    if(answer) cout << "YES\n";
    else cout << "NO\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}