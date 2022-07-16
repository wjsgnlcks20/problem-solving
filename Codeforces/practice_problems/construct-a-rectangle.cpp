#include <bits/stdc++.h>

using namespace std;

void solve(){
	int line[3];
	for(int i = 0; i < 3; i++) cin >> line[i];
	sort(line, line + 3);
	if(line[0] + line[1] == line[2]) cout << "YES\n";
	else if(line[0] == line[1] && line[2] % 2 == 0) cout << "YES\n";
	else if(line[1] == line[2] && line[0] % 2 == 0) cout << "YES\n";
	else cout << "NO\n";
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}