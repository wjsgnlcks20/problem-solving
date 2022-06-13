#include <string>
#include <iostream>
#include <vector>
#include <queue>

#define Max 5

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int bfs(vector<string> place, pair<int, int> start){
	
	queue<pair<pair<int, int>, int>> q;
	int visited[Max][Max] = {};
	
	q.push({{start.first, start.second}, 0});
	visited[start.first][start.second] = 1;
   
	while(!q.empty()){
		pair<int, int> now = q.front().first;
		int dist = q.front().second;
		q.pop();
		int newdist;
		for(int i = 0; i < 4; i++){
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if(ny<0 || ny>=5 || nx<0 || nx>=5) continue;
            
			if(visited[ny][nx] || place[ny][nx] == 'X') continue;
			if(place[ny][nx] == 'P' && dist <= 1) return 0;
            if(place[ny][nx] == 'P') newdist = 0;
            else newdist = dist + 1;
			visited[ny][nx] = 1;
			q.push({{ny, nx}, newdist});
		}
	}
	return 1;
}

int check_distance(vector<string> place){
	int ret = 0;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(place[i][j] == 'P'){
				if(bfs(place, {i, j}) == 0) return 0;
			}
		}
	}
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
	for(int i = 0; i < 5; i++){
		answer.push_back(check_distance(places[i]));
	}
    return answer;
}
