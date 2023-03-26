// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;

typedef long long ll;

ll get_gcd(ll a, ll b){
    ll temp;
    while(b){
        temp = a % b;
        a = b;
        b = temp;
    }
    return (a);
}

ll get_lcm(ll a, ll b) {
    return (a * b / get_gcd(a, b));
}

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    ll lcm = 1, gcd = 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        lcm = get_lcm(b[i], lcm);
        gcd = get_gcd(a[i] * b[i], gcd);
        if (gcd % lcm != 0){
            answer++;
            lcm = b[i];
            gcd = a[i] * b[i];
        } 
    }
    cout << answer + 1 << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}