#include <bits/stdc++.h>
#define Max 200001

using namespace std;

typedef long long ll;

void solve(){
    ll n, a[Max];
    cin >> n;
    ll sum = 0, flag = 0, answer = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > 0 && flag == 0) flag = 1;
        if(i == n - 1) continue;
        if(flag && a[i] == 0) answer++;
        sum += a[i];
    }
    cout << sum + answer << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}