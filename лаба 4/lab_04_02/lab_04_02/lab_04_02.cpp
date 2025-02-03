#include <iostream>
#include <vector>

using namespace std;
int RandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}
void printArray(vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void fillArray(vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size; ++i) {
        arr[i] = RandomNumber(1, 100);
    }
}
void manualSort(vector<int>& arr) {
    int n = arr.size();

    // Применяем сортировку пузырьком
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void findMaxThree(const vector<int>& arr) {
    int n = arr.size();
    int max1 = arr[n - 1]; // Максимальный элемент
    int max2 = -1; // Второй максимальный элемент
    int max3 = -1; // Третий максимальный элемент

    // Поиск второго максимального элемента
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] < max1) {
            max2 = arr[i];
            break;
        }
    }

    // Поиск третьего максимального элемента
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] < max2) {
            max3 = arr[i];
            break;
        }
    }

    // Вывод трех максимальных элементов
    cout << "Призеры – это участники, набравшие, " << max1 << " ," << max2 << " или " << max3 <<" баллов"<< endl;

    // Проверка наличия повторений максимальных элементов
    int countMax = 0;
    for (int num : arr) {
        if (num == max1) {
            countMax++;
        }
        if (num == max2) {
            countMax++;
        }
        if (num == max3) {
            countMax++;
        }
    }
    
    cout << "Количество призовых мест: " << countMax  << endl;
}

int main() {
    int n;
    setlocale(LC_CTYPE, "rus");
    cout << "Введите количество участников: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Введите баллы участников(числа от 1 до 100): ";
    fillArray(arr);
    printArray(arr);

    manualSort(arr);
    cout << "\n";
    cout << "\n";
    cout << "\n";
    printArray(arr);

    
    findMaxThree(arr);

    return 0;
}

