#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 100001l;

void solve(){
	ll n;
	cin >> n;
	string a[2 * N + 1];
	map<char, ll> mp;
	
	for(ll i = 0; i < 2 * n + 1; i++){
		cin >> a[i];
		for(ll j = 0; j < a[i].size(); j++){
			mp[a[i][j]]++;
		}
	}	
	
	for(auto elem : mp){
		if(elem.second % 2){
			cout << elem.first << "\n";
			break;
		}
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}