#include "Header.h"

String::String() {
	arr = new char[1];
	arr[0] = '\0';
	bitsize = 0;
}

char* String::Getarr()
{
	return arr;
}

String::String(char* str) {
	arr = new char[bitsize];
	strcpy(arr, str);
}

String::String(char sim) {
	arr = new char;
	int i = 0;
	arr[i] = sim;
	i++;
	arr[i] = '\0';
	bitsize = i;
}

String::String(const String& str) {
	if (str.arr) {
		arr = new char[strlen(str.arr) + 1];
		strcpy(arr, str.arr);
	}
	else arr[0] = '\0';
	bitsize = str.bitsize;
}


char* String:: clear (char* str)
{
	str[0] = '\0';
	strcpy(arr, str);
	return arr;
}

int String::dlina(char* str)
{
	int bitsize;
	int i = 0;
	while (str[i] != '\0')
		i++;
	bitsize = i;
	return bitsize;
}

//~String::String() { delete arr; bitsize=0;}

Bit_String::Bit_String() : String() {};

Bit_String::Bit_String(char* str) : String(str) {
	proverka();
}

Bit_String::Bit_String(const Bit_String& str) : String(str) {
	proverka();
};

const Bit_String& Bit_String::operator = (const Bit_String& str) {
		delete[] arr;
		arr = new char[strlen(str.arr) + 1];
		strcpy(arr, str.arr);
		return *this;
	};

int String::operator== ( String& str) {
	int temp = 0;
	
	if (str.arr == this->arr) 
		temp = 1;	 
	return temp;
};

Bit_String operator+(Bit_String& str1, Bit_String& str2)
{
	int i, i1, i2, k, p, nn;
	Bit_String str;

	if (str1.bitsize < str2.bitsize)
		nn = str2.bitsize;

	else nn = str1.bitsize;
	
	str = new char[];
	for (i = 0; i < nn + 1; i++) str.arr[i] = 0;

	p = 0;
	i1 = str1.bitsize - 1;
	i2 = str2.bitsize - 1;

	for (i = nn - 1; i >= 0; i--)
	{
		k = 0;
		if (i1 >= 0) k += str1.arr[i1];
		if (i2 >= 0) k += str2.arr[i2];
		k += p;
		str.arr[i + 1] = k % 2;
		p = k / 2;
		i1--;
		i2--;
	}
	if (p > 0) str.arr[0] = p;
	
	return str;
}

	void Bit_String::proverka() {
		int i = 0;
		
		while (arr[i] != '\0') {
			if ((arr[i] != '0') && (arr[i] != '1')) {
				arr[0] = '\0';
				bitsize = 0;
				break;
			}
			i++;
		}

	};

//~Bit_String() : String { };

	String** arr = new String * [6];
	bool flag = false;
	int n;

	int main()
	{
		setlocale(LC_ALL, "Rus");

		while (true)
		{
			system("cls");
			cout << "1. Создание строк\n";
			cout << "2. Сумма строк\n";
			cout << "3. Сравнение строк\n";
			cout << "4. Операция присваивания\n";
			cout << "5. Показать строки\n";
			cout << "6. Показать длину строки\n";
			cout << "7. Очистить строку.\n";
			cout << "8. Выход\n";
			cout << "\n\n";
			int t;
			cout << "->\n";
			cin >> t;
			switch (t)
			{
			case 1:
				if (flag == false)
				{
					cout << "Введите количество строк(от 4 до 6):\n";
					cin >> n;
					while (n < 0 || n>6)
					{
						cout << "Введите количество строк(от 4 до 6):\n";
						cin >> n;
					}
					char str[100];
					for (int i = 0; i < n; i++) {
						cout << "Введите строку:\n";
						cin >> str;
						arr[i] = new Bit_String(str);
					}
					flag = true;
					system("pause");
					break;
				}
				else
				{
					cout << "Строки уже были созданы";
					system("pause");
					break;
				}
			case 2:
				if (flag)
				{
					cout << endl << "Строки:\n";
					for (int i = 0; i < n; i++)
						cout << i + 1 << ". " << arr[i]->Getarr() << endl;
					cout << "Выберите номера строк для сложения:\n";
					int num1, num2;
					cout << "Первый номер:\n";
					cin >> num1;
					while (num1 < 1 || num1 > n)
					{
						cout << "Введите правильный первый номер:\n";
						cin >> num1;
					}
					cout << "Второй номер:\n";
					cin >> num2;
					while (num1 < 1 || num2 > n)
					{
						cout << "Введите правильный второй номер:\n";
						cin >> num2;
					}
					cout << "\nПервая строка:\n" << arr[num1 - 1]->Getarr() << "\nВторая строка:\n" << arr[num2 - 1]->Getarr() << endl;
					cout << "Сумма строк:\n";
					Bit_String a = Bit_String(arr[num1 - 1]->Getarr());
					Bit_String b = Bit_String(arr[num2 - 1]->Getarr());
					Bit_String c = a + b;
					cout << c.Getarr() << endl;
					system("pause");
					break;
				}
				else
				{
					cout << "Строки не были созданы.";
					system("pause");
					break;
				}
			case 3:
				if (flag)
				{
					cout << endl << "Строки:\n";
					for (int i = 0; i < n; i++)
						cout << i + 1 << ". " << arr[i]->Getarr() << endl;
					cout << "Выберите номера строк для проверки на равенство:\n";
					int num1, num2;
					cout << "Первый номер:\n";
					cin >> num1;
					while (num1 < 1 || num1 > n)
					{
						cout << "Введите правильный первый номер:\n";
						cin >> num1;
					}
					cout << "Второй номер:\n";
					cin >> num2;
					while (num1 < 1 || num2 > n)
					{
						cout << "Введите правильный второй номер:\n";
						cin >> num2;
					}
					cout << "\nПервая строка:\n" << arr[num1 - 1]->Getarr() << "\nВторая строка:\n" << arr[num2 - 1]->Getarr() << endl;
					cout << "Ответ:\n";
					int k = *arr[num1 - 1] == *arr[num2 - 1];
					if ( k == 1) cout << "Строки совпадают\n";
					else cout << "Строки не совпадают\n";
					system("pause");
					break;
				}
				else
				{
					cout << "Строки не были созданы.";
					system("pause");
					break;;
				}
			case 4:
				if (flag)
				{
					cout << endl << "Строки:\n";
					for (int i = 0; i < n; i++)
						cout << i + 1 << ". " << arr[i]->Getarr() << endl;
					cout << "Выберите номера строк для присваивания:\n";
					int num1, num2;
					cout << "Первый номер:\n";
					cin >> num1;
					while (num1 < 1 || num1 > n)
					{
						cout << "Введите правильный первый номер:\n";
						cin >> num1;
					}
					cout << "Второй номер(присваиваемая строка):\n";
					cin >> num2;
					while (num1 < 1 || num2 > n)
					{
						cout << "Введите правильный второй номер:\n";
						cin >> num2;
					}
					cout << "\nПервая строка:\n" << arr[num1 - 1]->Getarr() << "\nВторая строка:\n" << arr[num2 - 1]->Getarr() << endl;
					*arr[num1 - 1] = *arr[num2 - 1];
					cout << endl << "Строки:\n";
					for (int i = 0; i < n; i++)
						cout << i + 1 << ". " << arr[i]->Getarr() << endl;
					system("pause");
					break;
				}
				else
				{
					cout << "Строки не были созданы.";
					system("pause");
					break;
				}
			case 5:
				if (flag)
				{
					cout << endl << "Строки:\n";
					for (int i = 0; i < n; i++)
						cout << i + 1 << ". " << arr[i]->Getarr() << endl;
					cout << "Выберите номер строки для получения её длины:\n";
					int num1;
					cin >> num1;
					cout << "\nВыбранная строка:\n" << arr[num1 - 1]->Getarr() << endl;
					int k = arr[num1 - 1]->dlina(arr[num1 - 1]->Getarr());
					cout << k << "\n" << endl;
					system("pause");
					break;
				}
				else
				{
					cout << "Строки не были созданы.";
					system("pause");
					break;
				}
			case 6:
				if (flag)
				{
					cout << endl << "Строки:\n";
					for (int i = 0; i < n; i++)
						cout << i + 1 << ". " << arr[i]->Getarr() << endl;
					cout << "Выберите номер строки для её очистки:\n";
					int num1;
					cin >> num1;
					cout << "\nВыбранная строка:\n" << arr[num1 - 1]->Getarr() << endl;
					arr[num1 - 1]->clear(arr[num1 - 1]->Getarr());
					cout << "Строка очищена.\n" << endl;
					system("pause");
					break;
				}
				else
				{
					cout << "Строки не были созданы.";
					system("pause");
					break;
				}
			case 7:
				if (flag)
				{
					cout << endl << "Строки:\n";
					for (int i = 0; i < n; i++)
						cout << i + 1 << ". " << arr[i]->Getarr() << endl;
					system("pause");
					break;
				}
				else
				{
					cout << "Строки не были созданы.";
					system("pause");
					break;
				}
			case 8:
				exit(0);
			}
		}
	}