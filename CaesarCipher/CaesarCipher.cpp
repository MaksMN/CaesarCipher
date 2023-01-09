#include <iostream>;
using namespace std;

int main() {
	setlocale(LC_ALL, "");


	// Данный алгоритм позволяет при любом сдвиге не выходить за пределы алфавита.
	// Если a == 97
	// 97 + 26 + 26 ... + 26 всегда будут выдавать a

	// Входные данные: 
	// символ выбора операции (шифрование или дешифрование) 
	// длина строки
	// массив символов char arr[]
	// целое число  — сдвиг шифра
	// Вводится строка без каких-либо неалфавитных символов.
	// Символы в строке:  (строчные и заглавные).
	// Неалфавитные символы: знаки препинания, пробелы, цифры, — не вводятся и, соответственно, не меняются.
	// Выходные данные: преобразованная согласно шифру строка.


	char cipherOperation;
	cout << "Выберите операцию (e - шифрование, d - дешифрование): ";
	cin >> cipherOperation;

	int strlen;
	cout << "Введите длину строки: ";
	cin >> strlen;

	char* str = new char[strlen];
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
		offset = ~offset;
	default:
		break;
	}

	int range = 1;
	for (int i = 0; i < strlen; ++i) {
		char a = str[i];
		if (str[i] >= 97 && str[i] <= 122) { range = 123 - a; }
		if (str[i] >= 65 && str[i] <= 90) { range = 91 - a; }
		str[i] = a + offset + (256 - (range * (offset / range)));
	}

	cout << str;
	return 0;

}
