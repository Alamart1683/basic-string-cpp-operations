#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <regex>
using namespace std;

#define MaxLength 512

char Text[MaxLength];
string Sentence;

//ПРОТОТИПЫ ФУНКЦИЙ:
void Interface_Main();
void Interface_Task1();
void Interface_Task2();

int InputController(int Max_Variants, int Min_Variants);
void Task1_InputString(int Length, char* String);
void Task1_FindNumberOfOccurences(char* String, char symbol);
string Task2_InputString(string Sentence);
void Task2_Dictionary(string Sentence);
int main()
{
	system("cls");
	setlocale(LC_CTYPE, "RUS");
	int step;
	int Controller1 = 0;
	int Controller2 = 0;
	while (true)
	{
		Interface_Main();
		int Step_MaxVariants = 3;
		int Step_MinVariants = 1;
		char Symbol;
		step = InputController(Step_MaxVariants, Step_MinVariants);

		//ЗАДАНИЕ 1
		if (step == 1)
		{
			while (true)
			{
				system("cls");
				Interface_Task1();
				Step_MaxVariants = 4;
				step = InputController(Step_MaxVariants, Step_MinVariants);
				//ВВОД СТРОКИ
				if (step == 1)
				{
					system("cls");					
					Task1_InputString(MaxLength, Text);
					Controller1 = 1;
					step = 0;

				}
				//ВВОД СИМВОЛА ДЛЯ ПОДСЧЕТА
				else if (step == 2)
				{
					system("cls");
					cout << "Введите символ для подсчета количества вхождений: " << endl;
					cin >> Symbol;
					Controller2 = 1;
					step = 0;
				}
				//ПОИСК И ПОДСЧЕТ
				else if (step == 3)
				{
					if (Controller1 != 1 && Controller2 !=1)
					{
						system("cls");
						cout << "Для начала введите строку! " << endl;
						system("pause");
					}
					else
					{
					    Task1_FindNumberOfOccurences(Text,Symbol);
						system("cls");
					}
				}
				//ВОЗВРАТ
				else if (step == 4)
				{
					step = 0;
					Controller1 = 0;
					Controller2 = 0;
					break;
				}
			}
		}

		//ЗАДАНИЕ 2
		else if (step == 2)
		{
			while (true)
			{
				system("cls");
				Interface_Task2();
				Step_MaxVariants = 4;
				step = InputController(Step_MaxVariants, Step_MinVariants);

				//ВВОД СТРОКИ
				if (step == 1)
				{
					system("cls");
					Sentence = Task2_InputString(Sentence);
					Controller1 = 1;
					step = 0;

				}
				//СЛОВАРЬ
				else if (step == 2)
				{
					if (Controller1 != 1)
					{
						system("cls");
						cout << "Для начала введите строку! " << endl;
						system("pause");
					}
					else
					{
						Task2_Dictionary(Sentence);
						system("cls");
						step = 0;
					}
				}
				//ВОЗВРАТ
				else if (step == 3)
				{
					step = 0;
					Controller1 = 0;
					break;
				}
			}
		}

		//ВЫХОД
		else if (step == 3)
		{
			system("cls");
			cout << "Выход из программы осуществлен!" << endl;
			system("pause");
			break;
		}
	}
}

//ФУНКЦИИ ИНТЕРФЕЙСА:
void Interface_Main()
{
	system("cls");
	cout << "Лабораторная работа №3: Вариант 14" << endl;
	cout << "Выберите действие:" << endl;
	cout << "1. Задание 1;" << endl;
	cout << "2. Задание 2;" << endl;
	cout << "3. Выход из программы." << endl;
}
void Interface_Task1()
{
	system("cls");
	cout << "Выбрано Задание 1." << endl;
	cout << "Выберите действие:" << endl;
	cout << "1. Ввод текста." << endl;
	cout << "2. Ввод символа для поиска." << endl;
	cout << "3. Определить количество вхождений." << endl;
	cout << "4. Вернуться к выбору задания." << endl;
}

void Interface_Task2()
{
	cout << "Выбрано Задание 2." << endl;
	cout << "Выберите действие:" << endl;
	cout << "1. Ввод предложения." << endl;
	cout << "2. Составить частотный словарь слов." << endl;
	cout << "3. Вернуться к выбору задания." << endl;
}

//ОПИСАНИЕ ФУНКЦИЙ:
int InputController(int Max_Variants, int Min_Variants)
{
	int Input_Value;
	while (!(cin >> Input_Value) || Input_Value < Min_Variants || Input_Value > Max_Variants)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Вы ввели некорректное значение!" << endl;
		cout << "Повторите ввод." << endl;
	}
	return Input_Value;
}

void Task1_InputString(int Length, char* String)
{
	system("cls");
	cout << "Введите текст до 512 символов длиной: " << endl;
	cin.ignore();
	cin.getline(String, MaxLength);
}

void Task1_FindNumberOfOccurences(char* String, char symbol)
{
	int Count = 0;
	for (int i = 0; i < MaxLength; i++)
	{
		if (String[i] == symbol)
			Count++;
	}
	system("cls");
	cout << "В введенном вами тексте: " << endl;
	for (int i = 0; i < MaxLength; i++)
	{
		if (String[i] != '\0')
			cout << String[i];
	}
	cout << endl;
	cout <<  Count << " вхождений символа '" << symbol << "'" << endl;
	system("pause");
}

string Task2_InputString(string Sentence)
{
	system("cls");
	cout << "Введите предложение до 512 символов длиной: " << endl;
	cin.ignore();
	getline(cin, Sentence);
	return Sentence;
}

void Task2_Dictionary(string Sentence)
{
	system("cls");
	cout << "Вы ввели предложение: " << endl;
	cout << Sentence << endl;

	typedef map<string, vector<int>>::iterator words_it;
	map<string, vector<int>> Words;

	regex e("\\w+");

	regex_iterator<string::iterator> rit(Sentence.begin(), Sentence.end(), e);
	regex_iterator<string::iterator> rend;

	while (rit != rend)
	{
		Words[rit->str()].push_back(rit->position(0));
		++rit;
	}

	cout << endl;
	cout << "Получившийся словарь слов: " << endl;
	for (auto &w : Words)
	{
		cout << w.first << ' ' << w.second.size() << endl;
	}

	for (words_it i = Words.begin(); i != Words.end(); ++i)
	{
		if (i->second.size() > 1)
		{

			string n = "(" + to_string(i->second.size()) + ")";
			Sentence.insert(i->second[0], n);
			for (words_it j = i; j != Words.end(); ++j)
				for (auto &p : j->second)
					if (p > i->second[0]) p += n.size();

			int ws = i->first.size();
			for (int ii = i->second.size() - 1; ii > 0; --ii)
			{
				Sentence.erase(i->second[ii], ws);
				words_it j = i;
				for (++j; j != Words.end(); ++j)
					for (auto &p : j->second)
						if (p > i->second[ii]) p -= ws;
			}

		}
	}
	cout << "Обработанное предложение: " << endl;
	cout << endl << Sentence << endl;
	system("pause");
}