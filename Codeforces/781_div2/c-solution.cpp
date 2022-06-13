#include <bits/stdc++.h>
#define Max 200001

using namespace std;

typedef long long ll;

void solve(){
	
	int n, arr[Max], input;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		cin >> input;
		arr[input]++;
	}
	
	int timer = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>> pq;
	vector<pair<ll, ll>> save;
	
	for(int i = 1; i <= n; i++){
		if(arr[i] > 0) save.push_back({arr[i], i});
	}
	sort(save.begin(), save.end(), greater<pair<ll, ll>>());
	
	for(auto elem : save){
		pq.push({timer + elem.first, elem.second});
		timer++;
	}
	timer++;
	
	while(!pq.empty()){
		auto now = pq.top(); pq.pop();
		
		if(now.first <= timer) continue;
		
		pq.push({now.first-1,now.second});
		timer++;
	}
	
	cout << timer << "\n";
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}