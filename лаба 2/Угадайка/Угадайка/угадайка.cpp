#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
void main()
{
    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int start = 1;
    int N;
    int X;
    int Xbefore;
    int max_try;
    int real_try = 0;
    string user_answer = "";
    cout << "Введите число: " << '\n';
    cin >> N;
    real_try++;
    X = N / 2;
    start = 1;
    Xbefore = N;
    do {
        cout << "Попытка номер " << real_try << '\n';
        cout << X << '\n';
        cin >> user_answer;
        if (user_answer == "много") {
            Xbefore = X;
            X = (Xbefore - start) / 2 + start;
            
        }
        if (user_answer == "мало") {
            start = X;
            if (Xbefore - start == 1) {
                X = Xbefore;
            }
            else  X = (Xbefore - X) / 2 + start;
            
        } 
        real_try++;

    } while (user_answer != "угадал");


    Xbefore = N;
    start = 1;
    real_try = 0;
    do {
        X = (Xbefore - start) / 2 + 1;
        real_try++;
        Xbefore = X;
        cout << X << '\n';
    } while (X != 1);
    cout << "Максимальное количество шагов: " << real_try;
}

/*#include <iostream>
#include <Windows.h>
using namespace std;

int binarySearch(int low, int high, int steps) {
    if (low > high) {
        return -1; 
    }

    int mid = low + (high - low) / 2;
    cout << mid << endl;

    string response;
    cin >> response;

    if (response == "угадал") {
        return steps;
    }
    else if (response == "мало") {
        return binarySearch(mid + 1, high, steps + 1);
    }
    else if (response == "много") {
        return binarySearch(low, mid - 1, steps + 1);
    }
    else {
        cout << "Ошибка, некорректный ввод" << endl;
        return -1; 
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "rus");
    int N;
    cout << "Введите число N: ";
    cin >> N;

    int maxSteps = 1;
    while ((1 << maxSteps) - 1 < N) {
        maxSteps++;
    }

    int steps = binarySearch(1, N, 1);

    if (N < 1) {
        cout << "Ошибка" << endl;
    }
    else {
        cout << "Максимальное количество шагов = " << maxSteps << endl;
    }
    bool flag = false;

    for (int i = 0; i < maxSteps; i++) {

        cout << N << endl;
        N = (N + 1) / 2;
        if (N == 1 && !flag) {
            cout << 1 << endl;
            flag = true;
        }

    }

    return 0;
}*/

