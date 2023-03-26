#include <bits/stdc++.h>
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
    ll past = 1;
    ll pgcd = a[0];
    int cut = 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        ll lcm = get_lcm(b[i], past);
        ll gcd = get_gcd(a[i], pgcd);
        if (gcd % (lcm / past) != 0){
            cout << "i : " << i << "\n";
            answer++;
            past = 1;
            if (i != n - 1)
                pgcd = a[i + 1];
        }
        else {
            past = lcm;
            pgcd = gcd;
        }
    }
    cout << "answer : " << answer + 1 << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}