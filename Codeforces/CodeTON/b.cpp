#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "-1\n";
        return ;
    }
    vector<int> answer;
    while (n != 1){
        n /= 2;
        if (n % 2 == 0){
            answer.push_back(1);
            n++;
        }
        else {
            answer.push_back(2);
        }
    }
    reverse(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}