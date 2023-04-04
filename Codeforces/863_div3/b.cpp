#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;

typedef long long ll;

ll lmin(ll a, ll b){
    if (a < b)
        return (a);
    return (b);
}
 
ll lmax(ll a, ll b){
    if (a > b)
        return (a);
    return (b);
}
 
void solve(){
    ll n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    ll first = (x1 + y1);
    if (first > n + 1) {
        first = n + 1 - lmax(x1, y1);
    }
    else
        first = lmin(x1, y1);
    ll second = x2 + y2;
    if (second > n + 1) {
        second = n + 1 - lmax(x2, y2);
    }
    else
        second = lmin(x2, y2);
    cout << abs(second - first) << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}