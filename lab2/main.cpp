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
		cout << "1. ��������� ���� � ������������" << endl;
		cout << "2. ��������� ���� � ������������" << endl;
		cout << "3. ��������� ������" << endl;
		cout << "�����: "; cin >> choice;

		switch (choice)
		{
		case 1: // ��������� ���� � ������������
		{
			system("cls");
			string filename = "";
			cout << "������� ��� ����� ��� ������ (��������, file.txt): ";
			cin >> filename;
			if (filename != "")
			{
				system("cls");
				cout << "��������� ���� (" + filename + "):" << endl << endl;

				// ������ ����
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

				// �������� � ���������� � ����
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
								// �������� ������, ����������� ��� � �������� ������
								// � ������������ � string
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

				cout << endl << endl << "������������ (file.binary):" << endl;
				cout << endl;

				// ������ �������������� ����
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
		case 2: // ��������� ���� � ������������
		{
			system("cls");
			string filename = "";
			cout << "������� ��� ����� ��� ������ (��������, file.binary): ";
			cin >> filename;
			if (filename != "")
			{
				system("cls");
				cout << "��������� ���� (" + filename + "):" << endl << endl;

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

				cout << endl << endl << "������������ (" + filename + "):" << endl;
				cout << endl;

				// ������
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

				// ����������
				std::stringstream sstream(result);
				std::string output;
				try
				{
					// �������� ������ �� ������/�����
					while (sstream.good())
					{
						std::bitset<8> bits; // ������� ��������� �� 8 �����
						sstream >> bits; // ��������� ���������
						// �������� ��� ������� � ������������� � ������
						output += char(bits.to_ulong());
					}
				}
				catch (...)
				{

				}
				cout << output;

				cout << endl << endl;
				
				// ���������� � ���� ��������� �������������
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
		case 3: // ��������� ������
		{
			return 0;
		}
		default:
		{
			system("cls");
			cout << "����� ��������. ��������� ����." << endl;
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