#include <iostream>
#include <ctime>
using namespace std;
unsigned int finabochy1(unsigned int n) {
    if (n <= 1) {
        return n;
    }

    int prev = 0, current = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = current;
        current = prev + current;
        prev = temp;
    }
        return current;
}

unsigned int finabochy2(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return finabochy2(n - 1) + finabochy2(n - 2);
}

int main()
{
    clock_t start, end;
    double time;
    setlocale(LC_CTYPE, "RUS");
    unsigned int N;
    int k = 0;
    int f = 0;
    cout << "Введите число N:" <<endl;
    cin >> N;
    cout  << "Число последовательности, вычисленное с помощью цикла: " << endl;
   
    start = clock();
    k = finabochy1(N);
    end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
    cout << k << endl;
    
    cout << "Расчетное время циклом: " << int(time / 60) << " минут " << int(time) % 60 << " секунд" << endl;
   
   cout << '\n';
   cout << "Число последовательности, вычисленное с помощью рекурсии: "  << endl;
   start = clock();
   f = finabochy2(N);
   end = clock();
   time = double(end - start) / CLOCKS_PER_SEC;
   cout << f << endl;
   cout << "Расчетное время рекурсией: " << int(time / 60) << " минут " << int(time) % 60 << " секунд" << endl;
   cout << '\n';
  
   return 0;
}

 