#include <iostream>
#include <ctime>
using namespace std;

// Функция для генерации случайных чисел в диапазоне [min, max]
int RandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Функция для заполнения массива случайными числами
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) { 
        arr[i] = RandomNumber(1, 1000); 
    }
}

// Функция для вывода массива на экран
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Пузырьковая сортировка
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
               int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Сортировка вставками
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Сортировка выбором
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Быстрая сортировка (Quick Sort)
void quickSort(int arr[], int first, int last) {
    if (first < last) {
        int left = first;
        int right = last;
            int middle = arr[(left + right) / 2]; 
           do{
                while (arr[left] < middle)
                    left++;
                while (arr[right] > middle)
                    right--;
                if (left <= right) {
                    int tmp = arr[left];
                    arr[left] = arr[right];
                    arr[right] = tmp;
                    left++;
                    right--;
                }
                } while (left < right);
                    quickSort(arr, first, right);
                    quickSort(arr,left, last);
    }
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    srand(time(0)); // Инициализация генератора случайных чисел

    int N;
    cout << "Введите количество элементов массива: ";
    cin >> N;

    int* A = new int[N]; 
    fillArray(A, N); 

    cout << "Исходный массив A: ";
    printArray(A, N);

    int* B = new int[N];
    int* C = new int[N];
    int* D = new int[N];
    int* E = new int[N];
    copy(A, A + N, B);
    copy(A, A + N, C);
    copy(A, A + N, D);
    copy(A, A + N, E);

    clock_t start, end;
    double time_used;

    // Пузырьковая сортировка
    start = clock();
    bubbleSort(B, N);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\nОтсортированный массив B (пузырьковая сортировка): ";
    printArray(B, N);
    cout << "Время выполнения: " << time_used << " секунд\n";

    // Сортировка вставками
    start = clock();
    insertionSort(C, N);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\nОтсортированный массив C (сортировка вставками): ";
    printArray(C, N);
    cout << "Время выполнения: " << time_used << " секунд\n";

    // Сортировка выбором
    start = clock();
    selectionSort(D, N);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\nОтсортированный массив D (сортировка выбором): ";
    printArray(D, N);
    cout << "Время выполнения: " << time_used << " секунд\n";

    // Быстрая сортировка
    start = clock();
    quickSort(E, 0, N - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\nОтсортированный массив E (быстрая сортировка): ";
    printArray(E, N);
    cout << "Время выполнения: " << time_used << " секунд\n";

    return 0;
}
