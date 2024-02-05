#include<iostream>
#include<math.h>
using namespace std;

class Number {
private:
    float number;
public:
    Number(float number)
    {
        this->number = number;
    }
    float Division(float numToDivide)
    {
        this->number = this->number / numToDivide;
        return number;
    }
    float Addition(float numToAdd)
    {
        this->number = this->number + numToAdd;
        return number;
    }
    void Information()
    {
        cout << number << endl;

    }
    float Getnumber()
    {
        return number;
    }

};
class Real : public Number
{
private:

    float secondNumber = 0;


public:
    Real(float secondNumber, float number) : Number(number)
    {

        this->secondNumber = secondNumber;

    }
    float Power(int n)
    {
        this->secondNumber = pow(secondNumber, n);
        return secondNumber;
    }
    void SecondInformation()
    {
        cout << Getnumber() << endl;
        cout << secondNumber << endl;
    }
};
int main()
{
    Number num = Number(24);
    num.Division(3);
    num.Information();
    num.Addition(5);
    num.Information();

    Real sec = Real(16, 2);
    sec.Power(2);
    sec.Addition(15);
    sec.SecondInformation();
}