#include <bits/stdc++.h>
#define Max 200001

using namespace std;

typedef long long ll;

void solve(){
    int N, arr[Max], curSum = 0;
    ll ans = 0;
    cin >> N;
    int sqrLen = sqrt(2 * N) + 1;
    vector<int> sqr(sqrLen, 0);

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for(ll i = 0; i < sqrLen; i++){
        sqr[i] = i * i;
    }
    ans = (ll)N * (N + 1) / 2;

    /**
     * @brief 방법1 : prefix, Map을 사용
     * 
     * 
     */
    // tmp에는 이상적인 B의 값이 저장.
    // prefix가 tmp인 B의 갯수가 곧 정답의 갯수.
    // 따라서 prefix가 B인 경우의 횟수를 Map을 통해 확인해 그 갯수를 답에 누적한다.
    // B는 [0, i], C는 [0, j] 이고 i <= j 이므로 현재 xorArr prefix 보다 더 넓은 범위의 B는 없음.

    vector<int> HashTable(4 * N + 1, 0); // 최대를 2 * N으로 하면 왜 작은가.
    // HashMap[0] = 1; //1

    for(int i = 0; i < N; i++){
        curSum ^= arr[i];
        for(auto m : sqr) {
            ans -= (ll) HashTable[m ^ curSum];
            if(curSum == m) ans--;
            // 위의 코드 대신 1 주석 제거 가능 // 왜 그런지는 더 생각해봐야 함.
        }
        HashTable[curSum]++;
    }

    cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}