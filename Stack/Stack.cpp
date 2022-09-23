#include <iostream>
#include <time.h>
using namespace std;

class Stack
{
	// ������ � ������� ������� �����
	enum { EMPTY = -1, FULL = 20 };
	// ������ ��� �������� ������
	char st[FULL + 1];
	// ��������� �� ������� �����
	int top;

public:
	
	Stack();  // �����������
	void Push(char c);  // ���������� ��������
	char Pop();      // ���������� ��������
	void Clear();  // ������� �����
	bool IsEmpty();   // �������� ������������� ��������� � �����
	bool IsFull();   // �������� �� ������������ �����
	int GetCount();  // ���������� ��������� � �����
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
	top = EMPTY;  // ���������� ���� ����
}

void Stack::Clear()
{
	// ����������� "�������" ����� 
	// (������ � ������� ��� ��� ����������, 
	// �� ������� ������, ��������������� �� ������ � �������� �����,
	// ����� �� ������������)
	top = EMPTY;
}

bool Stack::IsEmpty()   // ����?
{
	return top == EMPTY;
}

bool Stack::IsFull()  // �����?
{
	return top == FULL;
}

int Stack::GetCount()
{
	// ���������� �������������� � ����� ���������
	return top + 1;
}

void Stack::Push(char c)
{
	// ���� � ����� ���� �����, �� ����������� ���������
	// �� ������� ����� � ��������� ����� �������
	if (!IsFull())
		st[++top] = c;
}

char Stack::Pop()
{
	// ���� � ����� ���� ��������, �� ���������� ������� �
	// ��������� ��������� �� ������� �����
	if (!IsEmpty())
		return st[top--];
	else // ���� � ����� ��������� ���
		return 0;
}

void Stack::Print() {
	for (int i = 0; i <= top; i++) {
		cout << st[i];
	}
	cout << endl << endl;
}

//��������� �� ������������ ����� ������
//������� ������ ������ }, ) ��� ]
// 1. ������� � ���������� ���������, ���� ���������, ���� ��������� ������ }, ) ��� ]
// 2. ������� � ��������� [i - count], ���� �� ��������� ���������� ��� ������ ��� ������
// count - ���������� ��� ��������� ������ }, ) � ]

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

