// забележка: програмата е разработена под Линукс среда и може да не работи с Виндовс

#include<bits/stdc++.h>
using namespace std;

// Набор от букви използвани в декриптирането
string plaintext = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

//Функция генерираща кодирания текст
string encoder(string key)
{
	string encoded = "";
	bool arr[26] = {0};

//Този цъкъл въвежда ключовата дума в началото на криптиращия низ
	for (int i=0; i<key.size(); i++)
	{
		if(key[i] >= 'A' && key[i] <= 'Z')
		{
			
//цикъл за проверка дали е въведен символ по-рано в криптирания низ
			if (arr[key[i]-65] == 0)
			{
				encoded += key[i];
				arr[key[i]-65] = 1;
			}
		}
		else if (key[i] >= 'a' && key[i] <= 'z')
		{
			if (arr[key[i]-97] == 0)
			{
				encoded += key[i] - 32;
				arr[key[i]-97] = 1;
			}
		}
	}

//този цикъл въвежда останалите символи в криптиращия низ
	for (int i=0; i<26; i++)
	{
		if(arr[i] == 0)
		{
			arr[i]=1;
			encoded += char(i + 65);
		}
	}
	return encoded;
}

// Тази функция ще разкодира съобщението
string decipheredIt(string msg, string encoded)
{
	// Функция за задържане на позицията на всяка буква в разкодираното съобщение
	map <char,int> enc;
	for(int i=0; i<encoded.size(); i++)
	{
		enc[encoded[i]]=i;
	}

	string decipher="";

	//Този цикъл ще разкодира съобщението
 //Интервалите, специалните знаци и номери остават същите
	for (int i=0; i<msg.size(); i++)
	{
		if (msg[i] >='a' && msg[i] <='z')
		{
			int pos = enc[msg[i]-32];
			decipher += plaintext[pos];
		}
		else if(msg[i] >='A' && msg[i] <='Z')
		{
			int pos = enc[msg[i]];
			decipher += plaintext[pos];
		}
		else
		{
			decipher += msg[i];
		}
	}
	return decipher;
}

// Основен код
int main()
{
	//Втора криптира част с шифъра на Цесар с измествания
	string cesar;
	cout << "Въведете 2-ро ниво криптиран текст (основен): "; cin >> cesar;
	char c[cesar.size() + 1];
	strcpy(c, cesar.c_str());
	int n = 3;
	for(int i = 0; (i < 100 && c[i] != '\0'); i++)
	c[i] = c[i] - n;
	//край на част втора

	// Тук влиза употребата на клавиатурата
    string key;
    cout << "Въведете ключовата дума: "; cin >> key;
    cout << "Избраната ключова дума е: " <<key << endl;

	// Извикваща функция за кодираното съобщение
	string encoded = encoder(key);

	    // Съобщение за декодиране
    string message = c;

	// Извикваща функция за отпечатване на разкодираният текст
	cout << "Декриптираният текст е: " << decipheredIt(message,encoded) << endl;

	return 0;
}
