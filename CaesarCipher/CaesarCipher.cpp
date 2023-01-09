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
		cout << "Введите длину строки: ";
		cin >> strlen;

		char* str = new char[strlen + 1];
		cout << "Введите строку: ";
		cin >> str;

		int offset;
		cout << "Введите число - сдвиг шифра: ";
		cin >> offset;

		switch (cipherOperation)
		{
		case 'e':
			cout << "Зашифрованная строка: ";
			break;
		case 'd':
			cout << "Дешифрованная строка: ";
			offset = ~offset++;
		}

		int letterAcode = 97;
		int offset2 = 19;

		for (int i = 0; i < strlen; i++) {
			char a = str[i];
			if (str[i] >= 65 && str[i] <= 90) { letterAcode = 65; offset2 = 13; }
			if (str[i] >= 97 && str[i] <= 122) { letterAcode = 97; offset2 = 19; }

			/*
			* Перебирает прописные и строчные буквы по принципу: после Z идет A
			* Сдвиг работает в обе стороны:
			* +offset => XYZABC... || -offset => CBAZYX...
			* Для строчных букв offset2 = 19 & letterAcode = 65
			* Для ПРОПИСНЫХ букв offset2 = 13 & letterAcode = 97
			*/
			str[i] = ((a - offset2 + (offset % 26)) % 26) + letterAcode;
			//cout << str[i];
		}
		cout << str << endl << endl;
		delete[] str;
	} while (1);
	return 0;
}