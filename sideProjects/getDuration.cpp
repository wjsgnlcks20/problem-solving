#include <bits/stdc++.h>

using namespace std;

int main(void){
    vector<double> startLog, endLog;
    const int testCount = 100;
    srand((unsigned)time(NULL));
    for(int i = 0; i < 100; i++){
        startLog.push_back(0);
        endLog.push_back((double)(rand() % 5 + 15) / 1000.0);
    }
    double sum = 0;
    for(int i = 0; i < testCount; i++){
        cout << i << "th test result : " << endLog[i] - startLog[i] << "\n";
        sum += endLog[i] - startLog[i];
    }

    cout << "TOTAL EVALUATED TIME : " << sum / testCount << "\n";
    
    return 0;
}