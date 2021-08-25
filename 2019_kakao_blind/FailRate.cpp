#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
	vector<pair<double, int>> save;	
	
	double failRate, sum = 0;
	for(int i = N - 1; i >= 0; i--){
		sum += stages[i];	
		failRate = (double)stages[i] / sum;
		save.push_back({failRate, i + 1});
	}
	sort(save.begin(), save.end());
	for(auto elem : save){
		answer.push_back(elem.second);
		cout << elem.second << " ";
	}
	cout << "\n";
	
    return answer;
}

int main(void){
	int N;
	string input;	
	cin >> N;
	getchar();
	getline(cin, input);
	input = input.substr(1, input.size());
	vector<int> stages;
	while(1){
		stages.push_back(stoi(input));
		if(input.find(" ") == string::npos) break;
		input = input.substr(input.find(" ") + 1, input.size());
	}
	solution(N, stages);
	return 0;
}