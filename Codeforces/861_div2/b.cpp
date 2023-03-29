#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;

typedef long long ll;
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<ll>>arr(n, vector<ll>(m, 0)); 
    ll answer = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++){
        vector<ll> cur(n);
        ll sum = 0;
        for (int j = 0; j < n; j++){
            cur[j] = arr[j][i];
            sum += cur[j];
        }
        sort(cur.begin(), cur.end());
        ll save = sum;
        for (int j = 0; j < n; j++){
            save -= cur[j];
            answer += save - (n - (j + 1)) * cur[j];
        }
    }
    cout << answer << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}