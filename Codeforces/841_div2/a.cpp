#include <bits/stdc++.h>

using namespace std;

void solve(){
    int N;
    cin >> N;
    long long ans = 1, input;
    for(int i = 0; i < N; i++){
        cin >> input; 
        ans *= input;
    }
    ans += N - 1;
    cout << 2022 * ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}