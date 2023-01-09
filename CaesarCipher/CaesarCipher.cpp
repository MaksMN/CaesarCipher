#include <iostream>;
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	do {
		char cipherOperation;
		cout << "Выберите операцию (e - шифрование, d - дешифрование, q - выход): ";
		cin >> cipherOperation;
		if ((cipherOperation != 'e') && (cipherOperation != 'd') && (cipherOperation != 'q')) { cout << "Неверный ввод!\n"; continue; }
		if (cipherOperation == 'q') { cout << "Goodbye"; return 0; }

		int strlen;
		cout << "Введите длину строки: "; cin >> strlen;
		char* str = new char[strlen + 1];
		cout << "Введите строку: ";	cin >> str;
		int offset;
		cout << "Введите число - сдвиг шифра: "; cin >> offset;
		cin.clear(); while (cin.get() != '\n');

		switch (cipherOperation)
		{
		case 'e':
			cout << "Зашифрованная строка: ";
			break;
		case 'd':
			cout << "Дешифрованная строка: ";
			offset = ~offset++;
		}

		int letterAcode = 0;
		bool makeOffset = false;
		for (int i = 0; i < strlen; i++) {
			if (str[i] >= 65 && str[i] <= 90) { letterAcode = 65; }
			if (str[i] >= 97 && str[i] <= 122) { letterAcode = 97; }
			if (!((letterAcode & 65) | (letterAcode & 97))) continue;
			str[i] = ((str[i] - letterAcode % 26 + (offset % 26)) % 26) + letterAcode;
			letterAcode = 0;
		}
		cout << str << endl << endl;
		delete[] str;
	} while (1);
	return 0;
}