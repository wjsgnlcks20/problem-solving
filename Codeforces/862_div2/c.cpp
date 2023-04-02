#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;

typedef long long ll;
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> k(n);
    vector<pair<pair<ll, ll>, ll>> line(m);
    for (int i = 0; i < n; i++){
        cin >> k[i];
    }
    sort(k.begin(), k.end());
    for (int i = 0; i < m; i++){
        cin >> line[i].first.first >> line[i].first.second >> line[i].second;
    }
    for (int i = 0; i < m; i++){
        int left = 0, right = n - 1;
        ll a = line[i].first.first;
        ll b = line[i].first.second;
        ll c = line[i].second;
        int flag = 0;
        while (left <= right){
            int mid = (left + right) / 2;
            ll check = pow((b - k[mid]), 2);
            if (check < 4LL * a * c) {
                cout << "YES\n";
                cout << k[mid] << "\n";
                flag = 1;
                break ;
            }
            else if (b > k[mid]){
                left = mid + 1;
            }
            else if (b <= k[mid]){
                right = mid - 1;
            }
        }
        if (!flag) {
            cout << "NO\n";
        }
    }
    cout << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}