#include<iostream>
using namespace std;

int main()
{
    int wex = 0;
    int b[20];
    int a[5][5];
    int maxElement = INT_MIN;
    int minElement = INT_MAX;
    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = rand() % 25+1;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (a[i][j] % 3 == 0 && j % 2 == 1)
            {
                b[wex] = a[i][j];
                cout << b[wex] << endl;
                wex++;
                if (a[i][j] > maxElement)
                    maxElement = a[i][j];
                if (a[i][j] < minElement)
                    minElement = a[i][j];
            }
        }
    }
    cout << "Max Element: " << maxElement << endl;
    cout << "Min Element: " << minElement << endl;

    return 0;
}
