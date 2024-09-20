#include <bits/stdc++.h>

using namespace std;

class Temperature {
private:
    int currentTemperature;
    int incrementStep;

public:
    Temperature() : currentTemperature(0), incrementStep(1) {}

    void setIncrementStep(int step) {
        incrementStep = step;
    }

    int getTemperature() const {
        return currentTemperature;
    }

    void increment() {
        currentTemperature += incrementStep;
    }

    void resetTemperature() {
        currentTemperature = 0;
    }
};

int main() {
    Temperature temp;

    temp.setIncrementStep(5);
    cout << "Initial Temperature: " << temp.getTemperature() << endl;

    temp.increment();
    cout << "Temperature after increment: " << temp.getTemperature() <<endl;

    temp.resetTemperature();
    cout << "Temperature after reset: " << temp.getTemperature() << endl;

    return 0;
}
