// TODO
// n m 소문자 대문자로 바꿀 것.
// 전역 배열, 변수 모두 지역으로 바꾸고 함수 전달로 바꿀것.
// 변수 함수 이름 신경써서 다시 바꿀것.
// 비어있는 위치 저장해서 더 빠르게 풀것
// c로도 구현해볼것

#include <bits/stdc++.h>
#define Max 10

using namespace std;

typedef int (*parr)[Max];

int N, M, answer = 0;
const int add_y[4] = {1, 0, -1, 0};
const int add_x[4] = {0, -1, 0, 1};
vector<pair<int, int>> emptyPos;
vector<pair<int, int>> virusPos;

void dfs(parr arr, parr visited, int start_y, int start_x){
	visited[start_y][start_x] = 1;	
	arr[start_y][start_x] = 2;
	for(int i = 0; i < 4; i++){
		int new_y = start_y + add_y[i];
		int new_x = start_x + add_x[i];
		if(!visited[new_y][new_x] && arr[new_y][new_x] == 0) dfs(arr, visited, new_y, new_x);
	}
}

int countSafeArea(parr arr){
	int ret = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(arr[i][j] == 0) ret++;
		}
	}
	return ret;
}

int spreadVirus(parr arr, parr visited){
	int copy_arr[Max][Max];	
	for(int i = 0; i < N; i++)	{
		for(int j = 0; j < M; j++){
			copy_arr[i][j] = arr[i][j];
		}
	}
	
	for(int i = 0, lim = virusPos.size(); i < lim; i++){
		int start_y = virusPos[i].first, start_x = virusPos[i].second;
		if(!visited[start_y][start_x]) dfs(copy_arr, visited, start_y, start_x);
	}
	return countSafeArea(copy_arr);	
}

void backtracking(parr arr, int cnt, int now){
	int visited[Max][Max];
	if(cnt == 3){
		memset(visited, 0, sizeof(visited));
		answer = max(answer, spreadVirus(arr, visited));
		return;
	}
	
	for(int i = now, lim = emptyPos.size(); i < lim; i++){
		int y = emptyPos[i].first, x = emptyPos[i].second;	
		if(arr[y][x] != 0) continue;
		arr[y][x] = 1;
		backtracking(arr, cnt + 1, i);
		arr[y][x] = 0;
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int arr[Max][Max];
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 0) emptyPos.push_back({i, j});
			if(arr[i][j] == 2) virusPos.push_back({i, j});
		}
	}
	
	backtracking(arr, 0, 0);
	cout << answer << "\n";	
	return 0;
}