#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, bitCnt[21] = {};
    long long ans = 0L;

    cin >> N;
    int * arr = new int[N + 1];
    // vector<int> arr(N + 1);
    // 비트연산을 거쳐 모든 이름을 2진수로 생각했을 때 각 자리수의 1의 갯수를 배열에 순차적으로 저장한다.
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        for(int j = 0; j < 21; j++){
            bitCnt[j] += (arr[i] & (1 << j)) >> j;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 21; j++){
            // mult는 수의 현재 비트와 다른 비트를 가지고 있는 수들의 수
            int mult, currentBit = arr[i] & (1 << j);
            if(currentBit) mult = N - bitCnt[j];
            else mult = bitCnt[j];
            // 현재 비트와 다른 수 * 2 ^ 현재 자리수의 누적 합들이 행성 친밀도의 합
            ans += (long long)mult * currentBit;
        }
    }
    cout << ans << " ";
    return 0;
}