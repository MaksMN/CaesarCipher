Домашнее задание модуля №3.

Шифр Цезаря.

Каждая буква исходного текста заменяется буквой, стоящей на n символов впереди неё. 
Алфавит зацикленный, т.е. после буквы Zz идет буква Aa.

Программа умеет в зависимости от выбора пользователя зашифровать или дешифровать текст, введённый с консоли, заменяя согласно шифру Цезаря строчные символы на строчные, заглавные на заглавные.

Входные данные:<br>
Символ выбора операции (e - шифрование, d - дешифрование, q - выход).<br>
Длина строки.<br>
Массив символов char[arr].<br>
Целое число — сдвиг шифра.<br>

Вводится строка без каких-либо неалфавитных символов. Символы в строке могут быть строчные и заглавные. 
Неалфавитные символы: знаки препинания, пробелы, цифры, — не вводятся и, соответственно, не меняются.
При вводе некоторых неалфавитных символов программа корректно завершит работу, игнорируя их шифрование.
Если длина строки не равна количеству введенных символов - произойдет ошибка программы.

Сдвиг шифра - целое число в диапазоне чисел integer. При шифровании и дешифровании нужно вводить одно и то же число с одним и тем же знаком.

Выходные данные: преобразованная согласно шифру строка.