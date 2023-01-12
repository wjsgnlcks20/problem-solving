#include <iostream>
#include <string>

using namespace std;

void solve(int test_case){
    string N, answer = "";
    int x, y;

    cin >> N >> x >> y;
    string sY = to_string(y), sX = to_string(x);

    int flag = 0, lastYidx = -1;
    for(int i = 0, len = N.length(); i < len; i++){
        if(flag) {
            answer += sY;
            continue;
        }
        if(N[i]-'0' >= y) {
            answer += sY;
            if(N[i]-'0' > y) flag = 1;
            else lastYidx = i;
        }
        else if(N[i]-'0' >= x){
            answer += sX;
            if(N[i]-'0' > x) flag = 1;
        }
        else {
            if(lastYidx < 0) {
                answer.clear();
                i = 0;
            }
            else{
                answer = answer.substr(0, lastYidx + 1);
                answer[lastYidx] = sX[0];
                i = lastYidx;
            }
            flag = 1;
        }
    }
    // cout << lastYidx << "\n";
    int deleteIdx = 0;
    for(; deleteIdx < answer.length(); deleteIdx++){
        if(answer[deleteIdx] != '0') break;
    }
    answer = answer.substr(deleteIdx, answer.length() - deleteIdx);

    // 가능하지 않은 경우
    if(answer.length() == 0){
        answer.clear();
        answer += "-1";
    }

    cout << "#" << test_case << " ";
    cout << answer << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, tIdx = 0;
    cin >> T;
    while(T--) solve(++tIdx);
    return 0;
}