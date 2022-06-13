#include <bits/stdc++.h>
#define Max 200001

using namespace std;

long long getmax(long long a, long long b){
	return a < b ? b : a;
}

void solve(){
	vector<int> brotherLen, extra;
	
	int n, input, rootCnt[Max] = {};
	cin >> n;
	rootCnt[0] = 1;
	
	for(int i = 0; i < n - 1; i++){
		cin >> input;
		rootCnt[input]++;
	}
	for(int i = 0; i <= n; i++){
		if(rootCnt[i] > 0) brotherLen.push_back(rootCnt[i]);
	}
	sort(brotherLen.begin(), brotherLen.end(), greater<int>());
	int size = brotherLen.size();
	long long answer = size;
	for(auto bCnt : brotherLen) {
		if(bCnt > size)	extra.push_back(bCnt - size--);
	}
	long long addedTime = 0l;
	for(int i = 0; i < extra.size(); i++){
		int bCnt = extra[i];
		long long diff = getmax((long long)bCnt - addedTime, 0l);
		addedTime += diff / 2;
		if(diff % 2) {
			if(i == extra.size() - 1) addedTime++;
			else extra[i + 1] -= 1;
		}
	}
	answer += addedTime;
	cout << answer << "\n";
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}