#include <bits/stdc++.h>

using namespace std;

long long labs(long long a){
    if(a < 0) return -a;
    return a;
}

void solve(){
    int n;
    long long sum = 0, input;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> input;
        sum += input;
    }
    cout << labs(sum) << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}