#include <bits/stdc++.h>
#define Max 1002

using namespace std;

int dp[Max][Max] = {};

int main(void){
    string a, b;
    cin >> a >> b;
    a = "_" + a;
    b = "_" + b;

    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < b.size(); j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    cout << dp[a.size() - 1][b.size() - 1] << "\n";
    return 0;
}
