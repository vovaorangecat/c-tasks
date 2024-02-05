#include<iostream>
#include<cmath>
using namespace std;
int main()
{
#define M_PI       3.14159265358979323846
    double x, z, y;
    cout << "enter x ";
    cin >> x;
    cout << "enter z ";
    cin >> z;
    if (x > 0 && -M_PI / 2 <= z <= M_PI / 2)
    {
        cout << "true" << endl;
        y = exp(-(x + 3)) + atan(z);

    }
    else if (x<0 && z>M_PI / 2)
    {
        y = 2 * x / log(pow(x, 2) + 3);
    }
    else
    {
        y = sqrt(abs(x));
    }
    cout << y;
    return 0;
}