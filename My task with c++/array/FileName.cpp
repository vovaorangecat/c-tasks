#include<iostream>
using namespace std;
void main()
{
    int a = 0;
    const int wex = 10;
    int w[wex];
    int secondArrIndex = 0;

    const int array = 15;
    int mas[array];
    for (int i = 0; i < array; i++)
    {
        mas[i] = rand() % 100;
        cout << mas[i] << endl;
    }
    for (int i = 0; i < array; i++)
    {
        if (mas[i] % 8 == 0)
        {
            w[secondArrIndex] = mas[i];
            cout << mas[i] << "\t";

            secondArrIndex++;
        }

    }

}