#include <bits/stdc++.h>
#define Max 200000

using namespace std;

bool compareSecond(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

void solve(){
	
	int N, permu[Max];
	string feedback;
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> permu[i];	
		permu[i]--;
	}
	cin >> feedback;	
	
	vector<pair<int, int>> disliked, liked, all;	
	for(int i = 0; i < N; i++){
		if(feedback[i] == '0') disliked.push_back({i, permu[i]});
		else liked.push_back({i, permu[i]});
	}
	
	sort(disliked.begin(), disliked.end(), compareSecond);
	sort(liked.begin(), liked.end(), compareSecond);

	int limit = disliked.size();
	for(int i = 0; i < N; i++){
		if(i < limit){
			all.push_back({disliked[i].first, i});
		}
		else all.push_back({liked[i - limit].first, i});
	}
	sort(all.begin(), all.end());
	for(auto elem: all){
		cout << elem.second + 1 << " ";
	}	
	cout << "\n";
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}