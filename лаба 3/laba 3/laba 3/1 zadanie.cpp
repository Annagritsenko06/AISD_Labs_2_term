#include <iostream>
#include <ctime>
using namespace std;

// ������� ��� ��������� ��������� ����� � ��������� [min, max]
int RandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// ������� ��� ���������� ������� ���������� �������
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) { 
        arr[i] = RandomNumber(1, 1000); 
    }
}

// ������� ��� ������ ������� �� �����
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ����������� ����������
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

// ���������� ���������
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

// ���������� �������
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

// ������� ���������� (Quick Sort)
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
    srand(time(0)); // ������������� ���������� ��������� �����

    int N;
    cout << "������� ���������� ��������� �������: ";
    cin >> N;

    int* A = new int[N]; 
    fillArray(A, N); 

    cout << "�������� ������ A: ";
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

    // ����������� ����������
    start = clock();
    bubbleSort(B, N);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n��������������� ������ B (����������� ����������): ";
    printArray(B, N);
    cout << "����� ����������: " << time_used << " ������\n";

    // ���������� ���������
    start = clock();
    insertionSort(C, N);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n��������������� ������ C (���������� ���������): ";
    printArray(C, N);
    cout << "����� ����������: " << time_used << " ������\n";

    // ���������� �������
    start = clock();
    selectionSort(D, N);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n��������������� ������ D (���������� �������): ";
    printArray(D, N);
    cout << "����� ����������: " << time_used << " ������\n";

    // ������� ����������
    start = clock();
    quickSort(E, 0, N - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n��������������� ������ E (������� ����������): ";
    printArray(E, N);
    cout << "����� ����������: " << time_used << " ������\n";

    return 0;
}
