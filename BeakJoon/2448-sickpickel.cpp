#include <bits/stdc++.h>
#define Max 6145

using namespace std;

int saveStar[Max][Max];

void printStar(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n * 2; j++){
            if(saveStar[i][j]) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}

void checkStar(int size, int head_y, int head_x){
    if(size == 3){
        saveStar[head_y][head_x] = 1;
        saveStar[head_y + 1][head_x - 1] = 1;
        saveStar[head_y + 1][head_x + 1] = 1;
        for(int i = -2; i < 3; i++){
            saveStar[head_y + 2][head_x + i] = 1;
        }
        return;
    }
    size /= 2;
    checkStar(size, head_y, head_x);
    checkStar(size, head_y + size, head_x - size);
    checkStar(size, head_y + size, head_x + size);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    checkStar(N, 0, N - 1);
    printStar(N);
    return 0;
}