#include <bits/stdc++.h>

using namespace std;

typedef struct _relation{
	char sideName;
	string adj_corner;	
}Relation; 

typedef Relation Data;

char cube[6][3][3];
char sideColors[6] = { 'w', 'r', 'y', 'o', 'b', 'g'};
Relation connect[7][4];

int getSideNum(char sideName){
	switch(sideName){
		case 'U':
			return 0;	
		case 'F':
			return 1;
		case 'D':
			return 2;
		case 'B':
			return 3;
		case 'R':
			return 4;
		case 'L':
			return 5;
		default :
			return 6;
	}
	return -1;
}

void simpleCopy(Data * arr_to, Data * arr_from, int size){
	
	for(int i = 0; i < size; i++)	{
		arr_to[i] = arr_from[i];
	}
}

void setting(Data * a, int * Jump, int * startIdx){
	if(a->adj_corner == "R1") {*Jump = 1; *startIdx = 0;}
	else if(a->adj_corner == "R3") {*Jump = 1; *startIdx = 6;}
	else if(a->adj_corner == "C1") {*Jump = 3; *startIdx = 0;}
	else {*Jump = 3; *startIdx = 2;}
}

void complicatedCopy(Data to, Data from){
	int fromJump, toJump, fromIdx, toIdx;
	
	setting(&from, &fromJump, &fromIdx);
	setting(&to, &toJump, &toIdx);
		
	for(int i = 0; i < 3; i++){
		 cube[getSideNum(to.sideName)][toIdx / 3][toIdx % 3] = cube[getSideNum(from.sideName)][fromIdx / 3][fromIdx % 3];
		fromIdx += fromJump;
		toIdx += toJump;
	}
}
void InitCube(){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				cube[i][j][k] = sideColors[i];	
			}
		}
	}
	Relation temp1[4] = {{'D', "R3"}, {'R', "R3"}, {'U', "R3"}, {'L', "R3"}};
	simpleCopy(connect[getSideNum('F')], temp1, 4);
	
	Relation temp2[4] = {{'U', "R1"}, {'R', "R1"}, {'D', "R1"}, {'L', "R1"}};
	simpleCopy(connect[getSideNum('B')], temp2, 4);
	
	Relation temp3[4] ={{'R', "C1"}, {'B', "R1"}, {'L', "C3"}, {'F', "R1"}};
	simpleCopy(connect[getSideNum('U')], temp3, 4);
	
	Relation temp4[4] = {{'R', "C3"}, {'F', "R3"}, {'L', "C1"}, {'B', "R3"}};
	simpleCopy(connect[getSideNum('D')], temp4, 4);
	
	Relation temp5[4] = {{'F', "C3"}, {'D', "C1"}, {'B', "C1"}, {'U', "C3"}};
	simpleCopy(connect[getSideNum('R')], temp5, 4);
	
	Relation temp6[4] ={{'F', "C1"}, {'U', "C1"}, {'B', "C3"}, {'D', "C3"}};
	simpleCopy(connect[getSideNum('L')], temp6, 4);
}

int move(int now, int distance){
	now += distance;
	if(now < 0) now += 4;
	return now % 4;
}

void rotateCurSide(char sideName){
	
	int sideNum = getSideNum(sideName);
	char tempcube[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			tempcube[i][j] = cube[sideNum][2 - j][i];
		}
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cube[sideNum][i][j] = tempcube[i][j];	
		}
	}
}

void rotateCube(char sideName, char direc){
	int sideNum	= getSideNum(sideName);
	int distance = (direc == '+') ? 1 : -1;
	int next, now = 0;
	int lim = 1;	
	if(direc == '-') lim = 3;
	for(int i = 0; i < lim; i++){
		rotateCurSide(sideName);
	}
	
	Data temp = { 'Z', "R1" };
	complicatedCopy(temp, connect[sideNum][now]);
	for(int i = 0; i < 3; i++){
		next = move(now, distance);
		complicatedCopy(connect[sideNum][now], connect[sideNum][next]);
		now = next;
	}
	complicatedCopy(connect[sideNum][now], temp);
}

void printCube(){
	for(int p = 0; p < 6; p++){
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++)	{
				cout << cube[p][i][j];
				}
			cout << "\n";
		}
		cout << "\n";
	}
	cout << "\n";
}

void printCubeSide(char sideName){
	int sideNum = getSideNum(sideName);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)	{
			cout << cube[sideNum][i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

void solve(){
	
	InitCube();
	
	int n;
	cin >> n;
	
	vector<string> vec;
	vec.resize(n);
	
	for(int i = 0; i < n; i++){
		cin >> vec[i];
	}
	for(int i = 0; i < n; i++){
		rotateCube(vec[i][0], vec[i][1]);
	}
	
	// printCubeSide('U');
	printCube();
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}