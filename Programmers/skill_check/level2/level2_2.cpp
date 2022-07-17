#include <bits/stdc++.h>

using namespace std;

vector<int> getnum(string s){
    vector<int> ret;
    int isitminus = 0;
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '-'){
            isitminus = 1;
        }
        else if(s[i] == ' '){
            if(isitminus) sum *= -1;
            ret.push_back(sum);
            sum = 0;
            isitminus = 0;
        }
        else {
            sum *= 10;
            sum += s[i] - '0';
        }

    } 
    if(isitminus) sum *= -1;
    ret.push_back(sum);
    return ret;
}

string solution(string s) {
    string answer = "";
    vector<int>numbers = getnum(s);
    sort(numbers.begin(), numbers.end());
    string a, b;
    a = to_string(numbers[0]);
    b = to_string(numbers[numbers.size() - 1]);

    answer = a + " " + b;
    return answer;
}