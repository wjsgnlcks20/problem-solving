#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

int main(void){
    const int mod = 1000000000;
    const int lim = 100;
    srand((unsigned)time(NULL));
    ofstream fout;
    fout.open("testcase.txt");
    fout << lim << "\n";
    for(int i = 0; i < lim; i++){
        int num = rand() % mod;
        int x = rand() % 10, y = rand() % 10;
        if(x > y) swap(x, y);
        else if(x == y) (y += 1) %= 10;
        string out = "";
        out += to_string(num) + " " + to_string(x) + " " + to_string(y);
        fout << out << "\n";
    }
    return 0;
}
