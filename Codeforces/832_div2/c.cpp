#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n, min_val = 9876543210;
    ll input, first_val;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> input;
        if(i == 0) first_val = input;
        min_val = min(min_val, input);
    } 
    if(first_val > min_val) cout << "Alice\n";
    else cout << "Bob\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}