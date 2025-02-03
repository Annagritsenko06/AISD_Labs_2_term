#include "Hash_Chain.h"
#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = nullptr;
	}
};
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
int main()
{
    setlocale(LC_ALL, "rus");
    int current_size = 7;
    cout << "Введите размер хеш-таблицы" << endl;
    cin >> current_size;
    hashTC::Object H = hashTC::create(current_size, hf);
    int choice;
    long k;
    for (;;)
    {
        cout << "1 - вывод хеш-таблицы" << endl;
        cout << "2 - добавление элемента" << endl;
        cout << "3 - удаление элемента" << endl;
        cout << "4 - поиск элемента" << endl;
        cout << "0 - выход" << endl;
        cout << "сделайте выбор" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0: exit(0);
        case 2: {
            AAA* a = new AAA;
            char* str = new char[1000];
            cout << "введите номер телефона " << endl;
            cin >> k;
            a->key = k;
            cout << "введите имя " << endl;
            cin >> str;
            a->mas = str;
            H.insert(a);
        }
              break;
        case 1: H.Scan();
            break;
        case 3: {
            AAA* b = new AAA;
            cout << "введите номер телефона" << endl;
            cin >> k;
            b->key = k;
            H.deleteByData(b);
        }
              break;
        case 4: {
            AAA* c = new AAA;
            cout << "введите номер телефона" << endl;
            cin >> k;
            c->key = k;

            // Измерение времени начинается перед вызовом функции поиска
            auto start = high_resolution_clock::now();

            listx::Element* result = H.search(c);

            // Измерение времени завершается после выполнения функции поиска
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Время выполнения поиска: " << duration.count() << endl;

            if (result == NULL)
                cout << "Элемент не найден" << endl;
            else
            {
                cout << "Первый элемент с данным номер телефона" << endl;
                AAA_print(result);
                cout << endl;
            }
        }
              break;
        }
    }
    return 0;
}