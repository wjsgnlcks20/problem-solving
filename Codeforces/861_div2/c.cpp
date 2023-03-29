#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;

typedef long long ll; 

ll getmax(ll a, ll b){
    if (a > b)
        return (a);
    return (b);
}

ll getmin(ll a, ll b){
    if (a < b)
        return (a);
    return (b);
}

int getlucky(ll i){
    int mx = 0, mn = 10;
    while (i){
        mx = getmax(mx , i % 10);
        mn = getmin(mn , i % 10);
        i /= 10;
    }
    return (mx - mn);
}
 
void solve(){
    ll l, r;
    int savemax = 10, answer = 0;
    int limit = 11;
    cin >> l >> r;
    for (ll i = l; i <= r && limit--; i++){
        int current = getlucky(i);
        if (savemax > current){
            savemax = current;
            answer = i;
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