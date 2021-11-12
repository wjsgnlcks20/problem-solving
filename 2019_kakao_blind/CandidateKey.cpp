#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<string>> globalRelation;
vector<int>done;

int isitPossible(vector<string> column){
	sort(column.begin(), column.end());
	for(int i = 1; i < column.size(); i++){
		if(column[i] == column[i - 1]) return 0;
	}
	return 1;
}

void backtracking(int Limit, int cnt, int * panswer, vector<int>& visited){
	
	if(cnt == Limit){
		vector<string>temp(globalRelation.size());
		
		for(int i = 0; i < visited.size(); i++){
			if(done[i] == 1 || visited[i] == 0) continue;
			
			for(int j = 0; j < globalRelation.size(); j++){
				temp[j] += globalRelation[j][i];
			}
		}	

		if(isitPossible(temp)){
			(*panswer)++;
			for(int i = 0; i < visited.size(); i++) done[i] |= visited[i];
		}
		return;
	}
	for(int i = 0; i < globalRelation[0].size(); i++){
		if(visited[i] || done[i]) continue;
		visited[i] = 1;
		backtracking(Limit, cnt + 1, panswer, visited);	
		visited[i] = 0;
	}	
}

void printGR(){
	for(int i = 0; i < globalRelation.size(); i++){
		for(int j = 0, lim = globalRelation[0].size(); j < lim; j++){
			cout << globalRelation[i][j] << " ";
		}
		cout << "\n";
	}	
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
	globalRelation.assign(relation.size(), vector<string>(relation[0].size()));
	copy(relation.begin(), relation.end(), globalRelation.begin());
	
	int colsize = relation[0].size();
	vector<int> visited(colsize, 0);
	done.assign(colsize, 0);
	
	for(int i = 0; i < colsize; i++){
		backtracking(i + 1, 0, &answer, visited);
	}
    return answer;
}

int main(void){
	string input;
	getline(cin, input);
	
	vector<vector<string>> relation;
	input = input.substr(3, input.size() - 3);	
	vector<string> temp;
	while(1){
		int fidx = input.find("\"");
		temp.push_back(input.substr(0, fidx));
		if(input.substr(fidx + 1, fidx + 3) == "]]") break;
		fidx = input.find("\"", fidx + 1);
		if(input[fidx - 1] == '['){
			relation.push_back(temp);
			temp.resize(0);
		}
		input = input.substr(fidx + 1, input.size() - fidx - 1);
	}
	relation.push_back(temp);

	cout << solution(relation) << "\n";
}