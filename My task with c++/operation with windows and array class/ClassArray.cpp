#include <iostream>
#include <conio.h>
#include <ctime>
#include <string> 
#include <windows.h>

using namespace std;

enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

void gotoxy(short x, short y);
void clear();

class Window {
    int h, w, x, y;
    int xWrite, yWrite;

    int textColor, bgColor, borderColor;

    bool useBorder;

    void SetColor(short textcolor, short bgcolor) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((bgcolor << 4) | textcolor));
    }

    void ValidWriteCords(int& xWrite, int& yWrite) {
        if (xWrite < 0 || yWrite < 0 || xWrite <= x || xWrite >= w - 2 || yWrite <= y || yWrite >= y - 2) {
            xWrite = this->xWrite;
            yWrite = this->yWrite;
        }
    }
public:
    Window(int x, int y, int h, int w, int textColor = LightBlue, int bgColor = LightGray, int borderColor = Red, bool useBorder = true) {
        this->x = x;
        this->y = y;

        xWrite = x + 2;
        yWrite = y + 2;

        this->h = h;
        this->w = w;

        this->textColor = textColor;
        this->bgColor = bgColor;
        this->borderColor = borderColor;

        this->useBorder = useBorder;
    }

    void Write(const char* str, int xWrite = -1, int yWrite = -1) {
        ValidWriteCords(xWrite, yWrite);

        if (yWrite >= y + w) return;

        gotoxy(xWrite, yWrite);

        for (unsigned int i = 0; str[i] && i + xWrite < x + w - 2; i++)
        {
            std::cout << str[i];
        }

        xWrite += strlen(str);
        if (xWrite >= x + w - 2) {
            xWrite = x + 2;
            yWrite += 1;
        }

        this->xWrite = xWrite;
        this->yWrite = yWrite;
    }

    void WriteLine(const char* str, int xWrite = -1, int yWrite = -1) {
        ValidWriteCords(xWrite, yWrite);

        if (yWrite >= y + w) return;

        gotoxy(xWrite, yWrite);

        for (unsigned int i = 0; str[i] && i + xWrite < x + w - 2; i++)
        {
            cout << str[i];
        }

        xWrite = x + 2;
        yWrite += 1;

        this->xWrite = xWrite;
        this->yWrite = yWrite;
    }
    void WriteSkip(int xWrite = -1, int yWrite = -1)
    {
        ValidWriteCords(xWrite, yWrite);

        if (yWrite >= y + w) return;

        xWrite = x + 2;
        yWrite += 1;
        this->xWrite = xWrite;
        this->yWrite = yWrite;
        gotoxy(xWrite, yWrite);

    }

    void Show() {
        if (useBorder) {
            SetColor(borderColor, bgColor);
            gotoxy(x, y);

            cout << "|";
            for (unsigned int j = 1; j < w - 1; j++) {
                cout << "^";
            }
            cout << "|";
        }

        for (unsigned int i = 1; i < h - 1; i++) {
            gotoxy(x, y + i);

            if (useBorder) {
                SetColor(borderColor, bgColor);
                cout << "|";
            }

            SetColor(textColor, bgColor);
            for (unsigned int j = 1; j < w - 1; j++) {
                cout << " ";
            }

            if (useBorder) {
                SetColor(borderColor, bgColor);
                cout << "|";
            }
        }

        if (useBorder) {
            SetColor(borderColor, bgColor);
            gotoxy(x, y + h - 1);

            cout << "|";
            for (unsigned int j = 1; j < w - 1; j++) {
                cout << "^";
            }
            cout << "|";
        }

        SetColor(textColor, bgColor);
        gotoxy(xWrite, yWrite);
    }

    void Clear() {
        for (unsigned int i = 1; i < h - 1; i++) {
            gotoxy(x + 2, y + i);
            SetColor(textColor, bgColor);
            for (unsigned int j = 1; j < w - 3; j++) {
                cout << " ";
            }
        }

        xWrite = x + 2;
        yWrite = y + 2;

        gotoxy(xWrite, yWrite);
    }

    ~Window() {}
};

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(short x, short y) {
    SetConsoleCursorPosition(hStdOut, { x, y });
}

void ConsoleCursorVisible(bool show, short size)
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

void clear()
{
    system("cls");
}

class Array {
    int* ar;
    unsigned int count, size;
    int min, sameMin;


public:
    Array(unsigned int s = 0) {

        ar = 0;
        count = size = 0;
        if (s > 0) SetSize(s);
    }

    ~Array() {
        delete[]ar;
    }

    Array(Array& a) {
        ar = 0;
        count = size = 0;
        if (a.count > 0) {
            count = size = a.count;
            ar = new int[count];
            for (unsigned int i = 0; i < count; i++) {
                ar[i] = a.ar[i];
            }
        }
    }

    unsigned int GetCount() { return count; }
    unsigned int GetSize() { return size; }

    Array& SetSize(unsigned int s) {
        if (s == 0) {
            delete[]ar;
            ar = 0;
            count = size = 0;
            return *this;
        }
        int* a = new int[s];
        for (int i = 0; i < count && i < s; i++) {
            a[i] = ar[i];
        }
        if (ar) {
            delete[] ar;
        }
        ar = a;
        size = s;
        if (size < count) count = size;
        return *this;
    }


    Array& Add(int e) {
        if (count + 1 > size) {
            SetSize(size + 1);
        }

        ar[count++] = e;
        return *this;
    }

    int& operator [] (unsigned int i) {
        return ar[i];
    }



    int minNumber() {

        min = ar[0];
        for (int i = 1; i < GetCount(); i++) {
            if (ar[i] < min) {
                min = ar[i];
            }

        }

        return min;
    }
    int sameMinNumber() {

        min = ar[0];
        for (int i = 1; i < GetCount(); i++)
        {
            if (ar[i] < min)
            {
                min = ar[i];
            }
        }
        for (int i = 0; i < GetCount(); i++)
        {
            if (ar[i] == min)
            {
                sameMin++;
            }
        }

        return sameMin;
    }
};
int realInput(int x1, int y1)
{
    int num = 0;
    while (1) {
        char key = _getch();
        if (key >= '0' && key <= '9')
        {
            gotoxy(x1, y1);
            int num1 = key - '0';
            num += num1;
            cout << key;
            x1++;
            num *= 10;

        }
        if (key == 13) {
            num /= 10;
            break;
        }
    }
    return num;
}

void input(int n, Array& A, int x1, int y1)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        num = realInput(x1, y1);
        x1 += (to_string(num).length() + 1);
        A.Add(num);
    }
}

int main()
{

    Window window(32, 10, 10, 60);
    Array ar;
    int n, r;

    window.Clear();

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    window.Write("Enter the array size ");


    n = realInput(55, 12);
    window.Write(to_string(n).c_str());
    srand(time(0));
    window.Show();
    for (int i = 0; i < n; i++) {
        r = rand() % 5 + 2;
        ar.Add(r);
    }
    window.Clear();
    window.Write("Array numbers: ");
    window.Write("[");
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            window.Write(",");
        }
        window.Write(to_string(ar[i]).c_str());
    }
    window.Write("]");


    window.Write("minimum number = ");
    window.WriteLine(to_string(ar.minNumber()).c_str());
    window.WriteSkip();
    window.Write("number of elements equal to the minimum element = ");
    window.WriteLine(to_string(ar.sameMinNumber()).c_str());

    _getch();
    clear();


}
