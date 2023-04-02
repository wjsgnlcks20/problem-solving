#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;
 
void solve(){
    int n;
    string s;
    cin >> n >> s;
    char start = s[0];
    char cmin = CHAR_MAX;
    int idx = 0;
    for (int i = 1; i < s.length(); i++){
        if (cmin >= s[i]){
            cmin = s[i];
            idx = i;
        }
    }
    if (cmin <= start) {
        s = s[idx] + s;
        s.erase(s.begin() + idx + 1);
    }
    cout << s << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}