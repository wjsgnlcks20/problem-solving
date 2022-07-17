#include <bits/stdc++.h>
#define Max 101

using namespace std;

string memoi[Max][Max];

string bigNumAdd(string a, string b){
    string ret = "";
    int a_idx = a.size() - 1, b_idx = b.size() - 1;
    int sum = 0;
    while(a_idx >= 0 || b_idx >= 0 || sum > 0){
        if(a_idx >= 0) sum += a[a_idx--] - '0';
        if(b_idx >= 0) sum += b[b_idx--] - '0';
        ret.push_back(sum % 10 + '0');
        sum /= 10;
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

string getCombination(int n, int m){
    if(m == 1) return to_string(n);
    if(n == m) return "1";

    string &ref = memoi[n][m];
    if(ref != "") return ref;

    return ref = bigNumAdd(getCombination(n - 1, m), getCombination(n - 1, m - 1));
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    cout << getCombination(n, m);
    return 0;
}