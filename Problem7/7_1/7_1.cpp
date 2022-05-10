#include <iostream>
using namespace std;

class Car
{
private:
    int gasolineGauge;
public:
    Car() : gasolineGauge(0)
    {}
    Car(int gas) : gasolineGauge(gas)
    {}
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;
public:
    HybridCar() : electricGauge(0)
    {}
    HybridCar(int elec) : electricGauge(elec)
    {}
    HybridCar(int gas, int elec) : Car(gas), electricGauge(elec)
    {}
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar() : waterGauge(0)
    {}
    HybridWaterCar(int water) : waterGauge(water)
    {}
    HybridWaterCar(int gas, int elec, int water) : HybridCar(gas, elec), waterGauge(water)
    {}
    void ShowCurrentGauge()
    {
        cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
        cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
        cout<<"잔여 워터량: "<<waterGauge<<endl;
    }
};

int main(void)
{
    HybridWaterCar car1(20,30,40);
    car1.ShowCurrentGauge();
    return 0;
}