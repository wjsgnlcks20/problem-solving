#include <iostream>
#include <vector>

using namespace std;

class snore{
public:
    snore(const int duration, const int noiseLimit){
        getSnoreDataFromStream();
        setInterSnoreDuration(duration);
        setNoiseLimit(noiseLimit);
    }

    void getSnoreDataFromStream(){
        int n;
        cin >> n;
        snoreData.resize(n + 1);
        for(int i = 0; i < n; i++){
            cin >> snoreData[i];
        }
    }
 
    void setInterSnoreDuration(const int duration){
        this->duration = duration;
    }   
    void setNoiseLimit(const double noiseLimit){
        this->noiseLimit = noiseLimit;
    }

    int countSnores(){
        int snoreCnt = 0;
        int currentlySnoring = 0;
        int noiseDurationCnt = 0;
        for(int i = 0; i < snoreData.size(); i++){
            int currentSignal = abs(snoreData[i]);
            if(currentlySnoring != 0 && currentSignal > noiseLimit) {
                currentlySnoring = 1;
                snoreCnt++;
                noiseDurationCnt = 0; 
            }
            else if(currentSignal <= noiseLimit){
                noiseDurationCnt++;
            }
            if(noiseDurationCnt >= duration){
                noiseDurationCnt = 0;
                currentlySnoring = 0;
            }
        }
        return snoreCnt;
    }

private:
    vector<double> snoreData;
    int duration;
    double noiseLimit;
};
   

int main(void){
    /**
     * duration은 각 코골이를 구분하는 시간, 등의 단위(정수형) 
     * noiseLimit은 각 index당 값이 코골이 신호인지, 잡음인지를 결정하는 기준
     */
    const int duration = 10; // 1이 1개의 index를 의미
    const double noiseLimit = 10; // 신호 단위
    
    snore newSnore(duration, noiseLimit);
    cout << newSnore.countSnores() << "\n";

    return 0;
}