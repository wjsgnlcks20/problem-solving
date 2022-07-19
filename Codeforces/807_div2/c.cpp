#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    ll end_idx = n;
    vector<pair<ll, ll>> len(c), query(c);
    for(int i = 0; i < c; i++){
        cin >> query[i].first >> query[i].second; 
        ll qlen = query[i].second - query[i].first;
        len[i].first = end_idx + 1;
        end_idx += qlen + 1;
        len[i].second = end_idx;
    }
  
    ll k;
    for(int i = 0; i < q; i++){
        cin >> k;
        for(int j = c - 1; j >= 0; j--){
            if(k >= len[j].first && k <= len[j].second) {
                k += query[j].first - len[j].first;
            }
        }
        cout << s[k - 1] << "\n";
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}