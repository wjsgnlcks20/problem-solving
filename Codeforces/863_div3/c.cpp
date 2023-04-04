#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;
 
void solve(){
    int n, input;
    cin >> n;
    vector<int> a(n, 0);
    vector<pair<int, int>> b;
    for (int i = 0; i < n - 1; i++){
        cin >> input;
        b.push_back({-input, i});
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n - 1; i++){
        a[b[i].second] = a[b[i].second + 1] = -b[i].first;
    }
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}