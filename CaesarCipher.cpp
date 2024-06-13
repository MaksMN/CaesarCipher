#include <iostream>
#include <string>
void cinClear()
{
	std::cin.clear();
	while (std::cin.get() != '\n')
		;
}
int main()
{
	char operation;
	int strlen, offset;
	std::string userInput;

	do
	{
		std::cout << "Выберите операцию (e - шифрование, d - дешифрование, q - выход): ";
		std::cin >> operation;
		cinClear();
		if ((operation != 'e') && (operation != 'd') && (operation != 'q'))
		{
			std::cout << "Неверный ввод!\n";
			continue;
		}
		if (operation == 'q')
		{
			std::cout << "Goodbye";
			return 0;
		}

		std::cout << "Введите строку: ";
		std::getline(std::cin, userInput);
		auto str = userInput.data();
		strlen = userInput.size();

		std::cout << "Введите число - сдвиг шифра: ";
		std::cin >> offset;
		cinClear();

		switch (operation)
		{
		case 'e':
			std::cout << "Зашифрованная строка: ";
			break;
		case 'd':
			std::cout << "Дешифрованная строка: ";
			offset = ~offset++; // отрицательный сдвиг
		}

		int codeA = 0;
		for (int i = 0; i < strlen; i++)
		{
			// проверка вхождения символа в диапазоны A-Z a-z
			// codeA присваивается значение первой буквы алфавита в зависимости от регистра символа.
			codeA = (str[i] >= 97 && str[i] <= 122) ? 97 : (str[i] >= 65 && str[i] <= 90) ? 65 : 0;
			// если символ не в диапазоне - игнорируется
			if (!codeA)
				continue;

			// это основная формула сдвига.
			// Рассчитывает сдвиг с учетом зацикливания алфавита, т.е. после буквы Zz идет буква Aa.
			str[i] = ((str[i] - codeA % 26 + (offset % 26)) % 26) + codeA;
			codeA = 0;
		}
		std::cout << str << std::endl
			<< std::endl;

	} while (1);
	return 0;
}