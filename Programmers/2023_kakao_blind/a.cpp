#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int time_diff(string start, string now){
    cout << start << " " << now << "\n";
    int year = now[3] - start[3];
    int months =  (10*(now[5]-'0')+(now[6]-'0')) - (10*(start[5]-'0')+(start[6]-'0'));
    int days = (10*(now[8]-'0')+(now[9]-'0')) - (10*(start[8]-'0')+(start[9]-'0'));

    return year * 12 * 28 + months * 28 + days;
}

int term_valid(string term){
    int months =  10*(term[2]-'0')+(term[3]-'0');
    return months;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    vector<int> mp(26);
    for(int i = 0; i < terms.size(); i++){
        mp[terms[0] - 'A'] = stoi(terms[0].substr(2, 2));
    }

    for(int i = 0; i < privacies.size(); i++){
        string now_time = privacies.substr(0, 10);
        if(term_valid(mp[privacies[0] - 'A'].second) < time_diff(now_time, today)){
            answer.push_back({mp[privacies[0] - 'A'].first});
            cout << answer.back() << " ";
        }
    }

    return answer;
}

int main(void){
    return 0;
}