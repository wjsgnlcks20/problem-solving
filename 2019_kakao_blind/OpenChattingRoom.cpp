#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> mp;
	string cmd;
	string nick_name;
	string user_id;
	for(string input: record){
		stringstream ss(input);
		ss >> cmd;
		ss >> user_id;
		if(cmd == "Enter" || cmd == "Change"){
			ss >> nick_name;
			mp[user_id]	= nick_name;
		}
	}
	
	for(string input : record){
		stringstream ss(input);
		ss >> cmd;
		ss >> user_id;
		
		if(cmd == "Enter"){
			answer.push_back(mp[user_id] + "님이 들어왔습니다.");
		}
		else if(cmd == "Leave"){
			answer.push_back(mp[user_id] + "님이 나갔습니다.");
		}
	}
	return answer;	
}

int main(void){
	string input;
	getline(cin, input);
	vector<string> record;
	input = input.substr(2, input.size());
	cout << input << "\n";	
	while(1){
		
		int idx = input.find("\"");
		
		record.push_back(input.substr(0, idx));
		if(input[idx + 1] == ']') break;
		input = input.substr(input.find("\"", idx + 1) + 1, input.size());
		cout << input << "\n";	
	}
	
	solution(record);	
	return 0;
}