#ifndef calculator
#define calculator

class Calculator
{
private:
    int count[4];

public:
    void Init();
    float Add(float a, float b);
    float Div(float a, float b);
    float Min(float a, float b);
    float Mul(float a, float b);
    void ShowOpCount();
};

#endif