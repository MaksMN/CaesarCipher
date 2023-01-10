#include <iostream>;
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	char operation;
	int strlen, offset;
	char* str;
	do {
		cout << "Выберите операцию (e - шифрование, d - дешифрование, q - выход): ";
		cin >> operation;
		if ((operation != 'e') && (operation != 'd') && (operation != 'q')) { cout << "Неверный ввод!\n"; continue; }
		if (operation == 'q') { cout << "Goodbye"; return 0; }

		cout << "Введите длину строки: "; cin >> strlen;
		str = new char[strlen + 1];
		cout << "Введите строку: ";	cin >> str;
		cout << "Введите число - сдвиг шифра: "; cin >> offset;
		cin.clear(); while (cin.get() != '\n');

		switch (operation)
		{
		case 'e':
			cout << "Зашифрованная строка: ";
			break;
		case 'd':
			cout << "Дешифрованная строка: ";
			offset = ~offset++;
		}

		int codeA = 0;
		for (int i = 0; i < strlen; i++) {
			codeA = (str[i] >= 97 && str[i] <= 122) ? 97 : (str[i] >= 65 && str[i] <= 90) ? 65 : 0;
			if (!codeA) continue;
			str[i] = ((str[i] - codeA % 26 + (offset % 26)) % 26) + codeA;
			codeA = 0;
		}
		cout << str << endl << endl;
		delete[] str;
	} while (1);
	return 0;
}