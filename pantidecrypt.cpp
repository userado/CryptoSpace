// CPP program for decoding the string
// which generate using classical cipher

#include<bits/stdc++.h>
using namespace std;

// Original Set of letters
string plaintext = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function generates the encoded text
string encoder(string key)
{
	string encoded = "";
	bool arr[26] = {0};

	// This loop inserts the keyword
	// at the start of the encoded string
	for (int i=0; i<key.size(); i++)
	{
		if(key[i] >= 'A' && key[i] <= 'Z')
		{
			// To check whether the character is inserted
			// earlier in the encoded string or not
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

	// This loop inserts the remaining
	// characters in the encoded string.
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

// This function will decode the message
string decipheredIt(string msg, string encoded)
{
	// Hold the position of every character (A-Z)
	// from encoded string
	map <char,int> enc;
	for(int i=0; i<encoded.size(); i++)
	{
		enc[encoded[i]]=i;
	}

	string decipher="";

	// This loop deciphered the message.
	// Spaces, special characters and numbers remain same.
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

// Driver code
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

	// Hold the Keyword
    string key;
    cout << "Въведете ключовата дума: "; cin >> key;
    cout << "Избраната ключова дума е: " <<key << endl;

	// Function call to generate encoded text
	string encoded = encoder(key);

	    // Message that need to encode
    string message = c;

	// Function call to print deciphered text
	cout << "Декриптираният текст е: " << decipheredIt(message,encoded) << endl;

	return 0;
}
