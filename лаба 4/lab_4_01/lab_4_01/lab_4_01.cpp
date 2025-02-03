#include <iostream>
#include <cstdlib> 
#include <ctime>  

using namespace std;
// Функция для генерации случайных чисел в диапазоне [min, max]
int RandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Функция для заполнения массива случайными числами
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = RandomNumber(1, 100);
    }
}

// Функция для вывода массива на экран
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void manual_sort(int arr[], int n) {
  
    for (int i = 0; i < n; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n ; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        swap(arr[i], arr[min_idx]);

        /*  for (int i = 0; i < n;i++) {
         cout << arr[i] << " ";
     }
          cout << '\n';
      }*/
    }

    
}



int main() {
    srand(time(nullptr)); // Установка seed для rand()
    setlocale(LC_CTYPE, "rus");
    int N;
    cout << "Введите количество товаров(N < 10000): ";
    cin >> N;
    int sum = 0;
    int* A = new int[N];
    fillArray(A, N);
    int* B = new int[N];
    copy(A, A + N, B);
    cout << "Цены товаров на кассе: ";
    printArray(A, N);
    manual_sort(B,N);
   /* cout << "Отсортированный массив цен по возрастанию:\n";
    printArray(B, N);*/

    int* C = new int[N];
    int* D = new int[N];
    
    for (int i = 0; i < N / 2; i++) {
        C[i] = B[i];
    }
    /*cout << "Вывод массива С:\n";
    printArray(C, N/2);*/
    if (N % 2 == 0) {
        for (int i = 0; i < N / 2; i++) {
            D[i] = B[i + N / 2];
        }
        /*cout << "Вывод массива D:\n";
        printArray(D, N / 2);*/
    }
    else {
        for (int i = 0; i < N / 2 +1; i++) {
            D[i] = B[i + N/2];
        }
        /*cout << "Вывод массива D:\n";
        printArray(D, N / 2+1);*/
    }
   
    int* ARRAY = new int[N];
    int j = 0;
    for (int i = 0; i < N/2; i++) {
        ARRAY[j] = D[i];
        ARRAY[j + 1] = C[i];
        j += 2;
    }
    if (N % 2 != 0) {
        ARRAY[N - 1] = D[N / 2 ];
    }
    cout << "Порядок пробивания на кассе :\n";
    printArray(ARRAY, N);
    for (int i = 0; i < N; i += 2) {
        sum += ARRAY[i];
    }
    cout << "Максимальная сумма чека: " <<sum << endl;
    return 0;
}
