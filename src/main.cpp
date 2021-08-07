#include <bits/stdc++.h>
#define Max 1001

using namespace std;

/*
		 0  1  2
		 3  4  5
l		 6  7  8 
9 10 11  18 19 20 27 28 29  36 37 38
12 13 14 21 22 23 30 31 32 	39 40 41
15 16 17 24 25 26 33 34 35 	42 43 44
		 45 46 47 
		 48 49 50 
		 51 52 53
*/
// 어찌 되었던 돌아가는 순서에 관한 것은 따로 저장해주어야 했던 것이고,
// 다만 좌표말고 인덱스로 표현하니 매우 간편해졌다.

char colors[7] = "wgrboy";
char arr[55];
int cube[6][3][3];

int getSideNum(char sideName){
	switch(sideName){
		case'U': return 0;
		case'L': return 1;
		case'F': return 2;
		case'R': return 3;
		case'B': return 4;
		case'D': return 5;
	}
	return -1;
}

int relation[6][12] = {
	{9, 10, 11, 18, 19, 20, 27, 28, 29, 36, 37, 38},
	{51, 48, 45, 24, 21, 18, 6, 3, 0, 38, 41, 44},
	{11, 14, 17, 45, 46, 47, 33, 30, 27, 8, 7, 6},
	{20, 23, 26, 47, 50, 53, 42, 39, 36, 2, 5, 8},
	{29, 32, 35, 53, 52, 51, 15, 12, 9, 0, 1, 2},
	{17, 16, 15, 44, 43, 42, 35, 34, 33, 26, 25, 24}
};

void InitArr(){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 9; j++){
			arr[i * 9 + j] = colors[i];
		}
	}
}

void rotateCube(char sideName){
	int sideNum = getSideNum(sideName);
	// arr 이 해당 인덱스에 대해 가르키는 색깔 값 바꿔주기
	int que[12];
	char temp[3][3];
	
	for(int i = 0; i < 12; i++){
		que[i] = arr[relation[sideNum][i]];	
	}
	for(int i = 0; i < 12; i++){
		arr[relation[sideNum][i]] = que[(i + 3) % 12];
	}
	
	// 회전하는 화면 배열 회전

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			temp[i][j] = arr[cube[sideNum][2 - j][i]];
		}
	}	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			arr[cube[sideNum][i][j]] = temp[i][j];
		}
	}	
}

void printUpSide(){
	int sideNum = getSideNum('U');
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			// cout << cube[sideNum][i][j] << " ";
			cout << arr[cube[sideNum][i][j]];
		}
		cout << "\n";
	}
}

void solve(){
	
	int n, lim; cin >> n;
	char input[Max][3];
	
	InitArr();
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	for(int i = 0; i < n; i++){
		if(input[i][1] == '+') lim = 1;
		else lim = 3;
		for(int k = 0; k < lim; k++)
			rotateCube(input[i][0]);
	}
	printUpSide();	
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	for(int i = 0; i < 6; i++){
		for(int j = 0; j <3; j++){
			for(int k = 0; k < 3; k++){
				cube[i][j][k] = i * 9 + j * 3 + k;
			}
		}
	}
	int t; cin >> t;
	while(t--) solve();
	return 0;
}