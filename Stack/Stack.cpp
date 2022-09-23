#include <iostream>
#include <time.h>
using namespace std;

class Stack
{
	// Нижняя и верхняя границы стека
	enum { EMPTY = -1, FULL = 20 };
	// Массив для хранения данных
	char st[FULL + 1];
	// Указатель на вершину стека
	int top;

public:
	
	Stack();  // Конструктор
	void Push(char c);  // Добавление элемента
	char Pop();      // Извлечение элемента
	void Clear();  // Очистка стека
	bool IsEmpty();   // Проверка существования элементов в стеке
	bool IsFull();   // Проверка на переполнение стека
	int GetCount();  // Количество элементов в стеке
	void Output() {
		for (int i = 0; i < top + 1; i++) {
			cout << st[i] << " ";
		}
		cout << endl;
	}
	void Print();
	char Check();
};


Stack::Stack()
{
	top = EMPTY;  // Изначально стек пуст
}

void Stack::Clear()
{
	// Эффективная "очистка" стека 
	// (данные в массиве все еще существуют, 
	// но функции класса, ориентированные на работу с вершиной стека,
	// будут их игнорировать)
	top = EMPTY;
}

bool Stack::IsEmpty()   // Пуст?
{
	return top == EMPTY;
}

bool Stack::IsFull()  // Полон?
{
	return top == FULL;
}

int Stack::GetCount()
{
	// Количество присутствующих в стеке элементов
	return top + 1;
}

void Stack::Push(char c)
{
	// Если в стеке есть место, то увеличиваем указатель
	// на вершину стека и вставляем новый элемент
	if (!IsFull())
		st[++top] = c;
}

char Stack::Pop()
{
	// Если в стеке есть элементы, то возвращаем верхний и
	// уменьшаем указатель на вершину стека
	if (!IsEmpty())
		return st[top--];
	else // Если в стеке элементов нет
		return 0;
}

void Stack::Print() {
	for (int i = 0; i <= top; i++) {
		cout << st[i];
	}
	cout << endl << endl;
}

//проверяем на правильность ввода скобок
//находим первую скобку }, ) или ]
// 1. сверяем с предыдущим элементом, если совпадаем, ищем следующую скобку }, ) или ]
// 2. сверяем с элементом [i - count], если не совпадает возвращаем эту скобку как ошибку
// count - количество уже найденных скобок }, ) и ]

char Stack::Check() {
	int count = 1;
	for (int i = 0; i <= top; i++) {
		if (st[i] == ')') {
			if (st[i - 1] == '(') {
				for (int l = i - 1; l < top; l++) {
					st[l] = st[l + 1];
				}
				Pop();
				i--;
				count++;
			}
			else if(st[i - count] == '(') {
				for (int l = i - count; l < top; l++) {
					st[l] = st[l + 1];
				}
				Pop();
				i--;
				count++;
			}
			else return st[i];
		}
		else if (st[i] == '}') {
			if (st[i - 1] == '{') {
				for (int l = i - 1; l < top; l++) {
					st[l] = st[l + 1];
				}
				Pop();
				i--;
				count++;
			}
			else if (st[i - count] == '{') {
				for (int l = i - count; l < top; l++) {
					st[l] = st[l + 1];
				}
				Pop();
				i--;
				count++;
			}
			else return st[i];
		}
		else if (st[i] == ']') {
			if (st[i - 1] == '[') {
				for (int l = i - 1; l < top; l++) {
					st[l] = st[l + 1];
				}
				Pop();
				i--;
				count++;
			}
			else if (st[i - count] == '[') {
				for (int l = i - count; l < top; l++) {
					st[l] = st[l + 1];
				}
				Pop();
				i--;
				count++;
			}
			else return st[i];
		}
	}
	return 'a';
}

void main()
{
	Stack st;
	char buff[50];
	cout << "Enter expression: ";
	int i = 0;
	while(true) {
		char c = getchar();
		if (c == ';') {
			break;
		}
		buff[i] = c;
		i++;
	}
	buff[i] = '\0';
	cout << "buffer: " << buff << endl << endl;

	for (int k = 0, n = 0; k < i; k++) {
		if (buff[k] == '}' || buff[k] == '{' || buff[k] == '[' || buff[k] == ']' || buff[k] == '(' || buff[k] == ')') {
			st.Push(buff[k]);
		}
	}
	cout << "st: ";
	st.Print();

	int k = 0;
	if (st.Check() == 'a') {
		cout << "buffer: " << buff << endl << endl;
	}
	else {
		while (buff[k] != st.Check()) {
			cout << buff[k];
			k++;
		}
	}
	cout << endl << endl;
}

