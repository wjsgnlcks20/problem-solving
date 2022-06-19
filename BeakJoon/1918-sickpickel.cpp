#include <bits/stdc++.h>

using namespace std;

int evalOperator(char oper){
	if(oper == '(')	return 1;
	if(oper == '+' || oper == '-') return 3;
	if(oper == '*' || oper == '/') return 5;
	return -1;
}

string InfixToPostfix(string exp){
	string ret = "";
	stack<char> st;	
	for(int i = 0; i < exp.length(); i++){
		char tok = exp[i];
		if(isalpha(tok)) ret.push_back(tok);
		else if(tok == '(') st.push(tok);
		else if(tok == ')'){
			while(st.top() != '('){
				ret.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
		else {
			while(!st.empty() && (evalOperator(st.top()) >= evalOperator(tok))){
				ret.push_back(st.top());	
				st.pop();
			}
			st.push(tok);
		}
	}
	while(!st.empty()) {
		ret.push_back(st.top());
		st.pop();	
	}
	return ret;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	string exp;
	cin >> exp;
	
	cout << InfixToPostfix(exp) << "\n";	
	return 0;
}