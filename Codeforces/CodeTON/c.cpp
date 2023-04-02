#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;

typedef long long ll;

ll lmin(ll a, ll b){
    if (a < b) {
        return (a);
    }
    return (b);
}

ll lmax(ll a, ll b){
    if (a > b){
        return (a);
    }
    return (b);
}
 
void solve(){
    int n;
    ll c, d, add = 0;
    cin >> n >> c >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 1; i++){
        if (a[i] == a[i + 1]){
            a[i] = LLONG_MAX;
            add += c;
        }
    }
    a.push_back(0);
    sort(a.begin(), a.end());
    vector<ll> live(n, 0), die(n, 0);
    for (int i = 0; i < n; i++){
        live[i] = die[i] = 0;
    }
    int dpIdx = 1, start = 0;
    ll last;
    for (int i = 1; i < a.size(); i++){
        if (a[i] == LLONG_MAX)
            break;
        last = a[i];
        if (a[i] != a[i - 1] + 1 && start){
            live[dpIdx] = live[dpIdx - 1] + d * (a[start] - a[start - 1] - 1);
            die[dpIdx] = min(live[dpIdx - 1], die[dpIdx - 1]) + c * (a[i] - a[start] - 1);
            dpIdx++;
            start = 0;
        }
        else if (a[i] != a[i - 1] + 1){
            start = i;
        }
    }
    // 마지막에 2번째 끊어진 구간이 없는 경우
    // 식 전체에서 단 한번도 끊어진 구간이 없어 start = 0인 경우 -> add == answer (고려 x)
    if (start){
        live[dpIdx] = live[dpIdx - 1] + d * (a[start] - a[start - 1] - 1);
        die[dpIdx] = min(die[dpIdx - 1], live[dpIdx - 1]) + c * (last - a[start] - 1);
        dpIdx++;
    }
    cout << "live : ";
    for (int i = 0; i < dpIdx; i++){
        cout << live[i] << " ";
    }
    cout << "\n dead : ";
    for (int i = 0; i < dpIdx; i++){
        cout << die[i] << " ";
    }
    cout << "\n";
    cout << add + lmin(live[dpIdx - 1], die[dpIdx - 1]) << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}