#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int inputs[3] = {}, temp[3] = {}, r = 0, g = 0, b = 0;
    for (int i = 0; i < n; i++){
        cin >> inputs[0] >> inputs[1] >> inputs[2];
        temp[0] = r;
        temp[1] = g;
        temp[2] = b;
        r = inputs[0] + min(temp[1], temp[2]);
        g = inputs[1] + min(temp[0], temp[2]);
        b = inputs[2] + min(temp[0], temp[1]);
    }
    cout << min(r, min(g, b)) << "\n";
    return 0;
}