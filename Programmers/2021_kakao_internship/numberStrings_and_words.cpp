#include <bits/stdc++.h>

using namespace std;

string numberStrings[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int isitNum(string s){
	for(int i = 0; i < 10; i++){
		if(s == numberStrings[i]) return i;
	}	
	return -1;
}

int main(void){
	string input;
	cin >> input;
	int answer = 0;
	string temp;
	for(int i = 0; i < input.length(); i++){
		if(isalpha(input[i]))	{
			temp += input[i];
			int add = isitNum(temp);
			if(add > 0){
				(answer *= 10) += add;
				temp = "";
			}
		}
		else{
			answer *= 10;
			answer += input[i] - '0';
		}
	}	
	
	cout << answer << "\n";
	
	return 0;
}