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

int n, m, ans = 0;
int arr[Max][Max];
int visited[Max][Max];
int add_y[4] = {1, 0, -1, 0};
int add_x[4] = {0, -1, 0, 1};
// vector<pair<int, int>> emptyPos;
vector<pair<int, int>> virusPos;

void dfs(parr arr, int start_y, int start_x){
	visited[start_y][start_x] = 1;	
	arr[start_y][start_x] = 2;
	for(int i = 0; i < 4; i++){
		int new_y = start_y + add_y[i];
		int new_x = start_x + add_x[i];
		if(!visited[new_y][new_x] && arr[new_y][new_x] == 0) dfs(arr, new_y, new_x);
	}
}

int countSafeArea(parr arr){
	int ret = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(arr[i][j] == 0) ret++;
		}
	}
	return ret;
}

int go(){
	int copy_arr[Max][Max];	
	for(int i = 0; i < n; i++)	{
		for(int j = 0; j < m; j++){
			copy_arr[i][j] = arr[i][j];
		}
	}
	
	for(int i = 0, lim = virusPos.size(); i < lim; i++){
		int start_y = virusPos[i].first, start_x = virusPos[i].second;
		if(!visited[start_y][start_x]) dfs(copy_arr, start_y, start_x);
	}
	return countSafeArea(copy_arr);	
}

void backtracking(int cnt, int now){
	if(cnt == 3){
		memset(visited, 0, sizeof(visited));
		ans = max(ans, go());
		return;
	}
	
	int now_i = now / m;
	int now_j = now % m;
	for(int i = now_i; i < n; i++){
		for(int j = now_j; j < m; j++){
			if(arr[i][j] != 0) continue;
			arr[i][j] = 1;
			backtracking(cnt + 1, now_i * m + now_j);
			arr[i][j] = 0;
		}
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
			// if(arr[i][j] == 0) emptyPos.push_back({i, j});
			if(arr[i][j] == 2) virusPos.push_back({i, j});
		}
	}
	
	backtracking(0, 0);
	cout << ans << "\n";	
	return 0;
}