// c++ криптираща програма използваща два вида криптиране
// първия шифър е субституционен шифър с ключова дума
// вторият шифър е на Цезар с 3 измествания на първите букви от азбуката
// схемната реализация е следната
// plaintext -> [Шифър 1] -> ciphertext1 -> [Шифър 2] -> ciphertext2
// забележка: програмата е разработена под Линукс среда и може да не работи с Виндовс

#include<bits/stdc++.h>
using namespace std;

//Функция генерираща кодирания текст
string encoder(string key)
{
    string encoded = "";
    //Този масив представя 26 букви от азбуката
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

//Функция, която генерира криптирания(cipher) текст
string cipheredIt(string msg, string encoded)
{
    string cipher="";
    string cesar;

    // Този цикъл криптира текста
    //Интервалите, специалните знаци и номери остават същите
    for (int i=0; i<msg.size(); i++)
    {
        if (msg[i] >='a' && msg[i] <='z')
        {
            int pos = msg[i] - 97;
            cipher += encoded[pos];
        }
        else if (msg[i] >='A' && msg[i] <='Z')
        {
            int pos = msg[i] - 65;
            cipher += encoded[pos];
        }
        else
        {
            cipher += msg[i];
        }
    }
    return cipher;
}

//Основната приграма(код) или функция
int main()
{
    //Тук влиза употребата на клавиатурата
    string key;
    cout << "Въведете ключова дума: "; cin >> key;
    cout << "Избраната ключова дума е: " <<key << endl;

    //Извикваща функция за генериране на криптирания текст
    string encoded = encoder(key);

    //Въвежда се необходимият текст за криптиране
    string message;
    cout << "Въведете текст за криптиране: "; cin >> message;
    cout << endl;
    cout << "Текстът преди криптиране е: " << message << endl;

    //Извикваща функция за отпечатване на криптирания текст
    cout << "1-во ниво криптиран текст (допълнителен): " << cipheredIt(message,encoded) << endl;

    //Втора криптира част с шифъра на Цесар с измествания
    string cesar = cipheredIt(message,encoded);
    char c[cesar.size() + 1];
    strcpy(c, cesar.c_str());
    int n = 3;
    for(int i = 0; (i < 100 && c[i] != '\0'); i++)
    c[i] = c[i] + n;
    cout << "2-ро ниво криптиран текст (основен): " << c << endl;
    //край на част втора

    return 0;
}
