#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF 987654321

using namespace std;

int N, M;
int min_city_dist = INF;
vector<pii> chicken, house, not_to_close;

int getDistance(pii a, pii b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void chooseNotClosingChicken(int idx){
		
	if(not_to_close.size() == M){
		int city_dist = 0;
		for(pii& housePos : house){
			int min_distance = INF;
			for(pii& notClosingPos : not_to_close){
				min_distance = min(min_distance, getDistance(housePos, notClosingPos));
			}
			city_dist += min_distance;		
		}	
		min_city_dist = min(min_city_dist, city_dist);
		return;
	}	
	else if(idx == chicken.size()) return;
	
	not_to_close.push_back(chicken[idx]);
	chooseNotClosingChicken(idx + 1);
	
	not_to_close.pop_back();
	chooseNotClosingChicken(idx + 1);
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);	
	cin >> N >> M;
	int input;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> input;
			if(input == 2) chicken.push_back({i, j});
			else if(input == 1) house.push_back({i, j});
		}
	}
	chooseNotClosingChicken(0);	
	cout << min_city_dist << "\n";	
	return 0;
}