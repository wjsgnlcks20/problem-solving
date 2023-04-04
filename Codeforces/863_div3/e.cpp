#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;

typedef long long ll;

int digit(ll divider){
    int ret = 0;
    while (divider) {
        ret++;
        divider /= 10;
    }
    return (ret);
}

ll getValue(int digit){
    ll ret = powl(10, digit) - powl(9, digit);
    return (ret);
}

ll recursive(ll cur, ll divider) {
    if (cur < 10){
        if (cur < 4)
            return (0);
        else
            return (1);
    }
    ll mok = cur / divider;
    ll ret = (mok) * getValue(digit(divider) - 1);
    if (mok >= 4)
        ret += powl(9, digit(divider) - 1);
    return (ret + recursive(cur % divider, divider / 10));
}

ll setDivider(ll val){
    ll divider = 1;
    while (divider <= val) {
        divider *= 10;
    }
    divider /= 10;
    return (divider);
}

void solve(){
    ll minus = 0, k, divider = 1;
    cin >> k;
    divider = setDivider(k);
    minus = recursive(k, divider);
    // cout << "m : " << minus << "\n";
    k = k + minus;
    ll nextm = recursive(k, setDivider(k));
    while (nextm > minus){
        // cout << "k : " << k << "\n";
        // cout << "m : " << nextm << "\n";
        k += nextm - minus;
        minus = nextm;
        nextm = recursive(k, setDivider(k));
    }
    cout << k << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}