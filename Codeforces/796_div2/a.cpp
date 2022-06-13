#include <bits/stdc++.h>

using namespace std;

void solve(){
	int x;
	cin >> x;
	
	if(x == 1 || x == 2){
		cout << 3 << "\n";
	}
	else if(x & 1){
		cout << 1 << "\n";
	}
	else {
		if(!(x&(x - 1))){
			cout << x + 1 << "\n";
		}
		else cout << (x&(~(x-1))) << "\n";
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}