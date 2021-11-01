#include <Windows.h>
#include <iostream>
#include <sstream>
#include <bitset>
#include <fstream>
#include <limits>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int choice = 0;
	while (true)
	{
		cout << "1. Прочитать файл и закодировать" << endl;
		cout << "2. Прочитать файл и декодировать" << endl;
		cout << "3. Завершить работу" << endl;
		cout << "Выбор: "; cin >> choice;

		switch (choice)
		{
		case 1: // Прочитать файл и закодировать
		{
			system("cls");
			string filename = "";
			cout << "Введите имя файла для чтения (например, file.txt): ";
			cin >> filename;
			if (filename != "")
			{
				system("cls");
				cout << "Считанный файл (" + filename + "):" << endl << endl;

				// Читаем файл
				string result = "";
				std::string line;
				try
				{
					std::ifstream in(filename);
					if (in.is_open())
						while (getline(in, line))
							result += line;
					in.close();
				}
				catch (...)
				{

				}
				cout << result;

				// Кодируем и записываем в файл
				try
				{
					ofstream out;
					out.open("file.binary");
					if (out.is_open())
					{
						string output = "";
						try
						{
							for (char& _char : result)
								// Передаем символ, представляя его в бинарной записи
								// и конвертируем в string
								output += bitset<8>(_char).to_string();
						}
						catch (...)
						{

						}
						out << output;
					}
					out.close();
				}
				catch (...)
				{

				}

				cout << endl << endl << "Закодировано (file.binary):" << endl;
				cout << endl;

				// Читаем закодированный файл
				result = "", line = "";
				try
				{
					std::ifstream in("file.binary");
					if (in.is_open())
						while (getline(in, line))
							result += line;
					in.close();
				}
				catch (...)
				{

				}
				cout << result;
				
				cout << endl << endl;
				system("pause");
				system("cls");
			}
			break;
		}
		case 2: // Прочитать файл и декодировать
		{
			system("cls");
			string filename = "";
			cout << "Введите имя файла для чтения (например, file.binary): ";
			cin >> filename;
			if (filename != "")
			{
				system("cls");
				cout << "Считанный файл (" + filename + "):" << endl << endl;

				string result = "";
				std::string line;
				try
				{
					std::ifstream in(filename);
					if (in.is_open())
						while (getline(in, line))
							result += line;
					in.close();
				}
				catch (...)
				{

				}
				cout << result;

				cout << endl << endl << "Декодировано (" + filename + "):" << endl;
				cout << endl;

				// Читаем
				result = "", line = "";
				try
				{
					std::ifstream in(filename);
					if (in.is_open())
						while (getline(in, line))
							result += line;
					in.close();
				}
				catch (...)
				{

				}

				// Декодируем
				std::stringstream sstream(result);
				std::string output;
				try
				{
					// Проверка потока на ошибку/конец
					while (sstream.good())
					{
						std::bitset<8> bits; // Создали контейнер на 8 битов
						sstream >> bits; // Заполнили контейнер
						// Получили код символа и преобразовали в символ
						output += char(bits.to_ulong());
					}
				}
				catch (...)
				{

				}
				cout << output;

				cout << endl << endl;
				
				// Записываем в файл результат декодирования
				try
				{
					ofstream out;
					out.open("SaveDecode.txt");
					if (out.is_open())
						out << output;
					out.close();
				}
				catch (...)
				{

				}
				system("pause");
				system("cls");
			}
			break;
		}
		case 3: // Завершить работу
		{
			return 0;
		}
		default:
		{
			system("cls");
			cout << "Выбор неверный. Повторите ввод." << endl;
			system("pause");
			system("cls");
			choice = 0;
			if (char(cin.peek()) == '\n')
				cin.ignore(); 

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
			}
			break;
		}
		}
	}
	system("pause");
	return 0;
}