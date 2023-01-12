#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long modInv(long long a, int M) {
	if (M == 1)
		return a;
	if (M == 0)
		return 1;

	long long  tmp = modInv(a, M / 2);
	if (M % 2)
		return (long long)((long long)((tmp*tmp) % MOD)*a) % MOD;
	else
		return (long long)(tmp*tmp) % MOD;
}

void solve(){
    long long mod = 1000000007L;
    long long N, ans = 0;
    cin >> N;

    ans = ((N * (N + 1)) % mod * (4 * N - 1) % mod * modInv(6, mod - 2)) % mod;
    (ans *= 2022) %= mod;

    cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}