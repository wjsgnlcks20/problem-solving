#include <iostream>
#define MAX 200001

using namespace std;


void solve(){
    int save[MAX] = {};
    int N, input;
    cin >> N;
    int sum = N;
    for (int i = 0; i < N; i++){
        cin >> input;
        save[input]++;
    }
    if (save[0] <= sum - save[0] + 1) {
        cout << "0\n";
        return ;
    }
    sum -= save[0];
    if (save[1] == 0 || sum - save[1] > 0){
        cout << 1 << "\n";
    }
    else {
        cout << 2 << "\n"; 
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}