#include <iostream>
#include <string>
using namespace std;
struct Node {
    char data;
    Node* next;
};
class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {};  
    
    void push(char data); 
    char pop(); 
    bool isEmpty(); 
    void clear(); 
    char readtop();
    
};
void Stack::push(char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

char Stack::pop() {
    if (isEmpty()) {
        return 0;
    }
    char data = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return data;
}
bool Stack::isEmpty() {
    return top == nullptr;
}
char Stack::readtop() {  
    if (!isEmpty()) {
        return top->data;
    }
    else return 0;
}
void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}
int Balance(char* array, int size) {
    Stack t;

    for (int i = 0; i < size; i++)
    {
        switch (array[i])
        {
            
        case '(': t.push(array[i]);
            break;

        case '[': t.push(array[i]);
            break;
        case '{': t.push(array[i]);
            break;

            
        case ')':
            if (t.readtop() == '(')
            {
                cout << " () РАССТАВЛЕНЫ ПРАВИЛЬНО\n";
                t.pop();
            }
            
            else
            {
                cout << " СКОБКИ РАССТАВЛЕНЫ НЕПРАВИЛЬНО\n";
                return -1;
            }
            break;
        case ']':
            if (t.readtop() == '[')
            {
                cout << "[] РАССТАВЛЕНЫ ПРАВИЛЬНО\n";
                t.pop();
            }
            else {
                cout << "СКОБКИ РАССТАВЛЕНЫ НЕПРАВИЛЬНО\n";
                return -1;
            }
            break;
        case '}':
            if (t.readtop() == '{')
            {
                cout << " {} РАССТАВЛЕНЫ ПРАВИЛЬНО\n";
                t.pop();
            }
            else
            {
                cout << " СКОБКИ РАССТАВЛЕНЫ НЕПРАВИЛЬНО\n";
                return -1;
            }
            break;

        }
    }
}
int main()
{
    setlocale(LC_CTYPE,"RUS");
    char array1[1000];
    char array[1000];
    cout << "Введите строку, которая может содержать цифры, буквы, знаки математических операций (+, -, *, /) и три вида скобок: (), [] и {}:\n";
    gets_s(array, sizeof(array));
    int j = 0;
    for (int i = 0; i < sizeof(array); i++) {
        if (array[i] == '[' || array[i] == ']' || array[i] == '{' || array[i] == '}' || array[i] == '(' || array[i] == ')')
        {
            array1[j] = array[i];
            j++;
        }
    }
    if (j == 0) {
        cout << "скобок в строке нет\n";
    }
    else  Balance(array1, j);
   
   
    return 0;
}


