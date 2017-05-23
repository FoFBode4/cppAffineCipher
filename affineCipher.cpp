#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

//prototyping
void encrypt(string input, int x, int y);
void decrypt(string input, int x, int y);
int inverseMod (int x, int y);

int main (void)
{
	int x=0;//first value in cipher
	int y=0;//second value in cipher
	int choice=0;
	string input;//the string that will be encrypted or decrypted

	cout << "\nEnter value X:" << endl;
	cin >> x;
	cout << "\nEnter value Y:" << endl;
	cin >> y;

	cout << "Enter string to encrypt/decrypt:" << endl;
	cin >> input;

	while (choice < 1 || choice > 2)
	{
		cout << "1. Encrypt\n2. Decrypt" << endl;
		cin >> choice;
	}
	
	if (choice == 1)
	{
		encrypt(input, x, y);
	}
	else
	{
		decrypt(input, x, y);
	}

	return 0;
}

void encrypt(string input, int x, int y)
{
	int i=0;

	for(i = 0; i < input.length(); i++)
	{
		if(input[i] >= 'a' && input[i] <= 'z')
		{
            cout << (char)((x * (input[i] - 'a') + y) % 26 + 'a');
        } 
        else if(input[i] >= 'A' && input[i] <= 'Z')
        {
            cout << (char)((x * (input[i] - 'A') + y) % 26 + 'A');
        } 
        else
        {
            cout << input[i];
        }
	}
	cout << endl;
}

void decrypt(string input, int x, int y)
{
	for(int i = 0; i < input.length(); ++i)
	{
        if(input[i] >= 'a' && input[i] <= 'z')//if the character is lower case
        {
            cout << (char)(inverseMod(x, 26) * (26 + input[i] - 'a' - y) % 26 + 'a');
        } 
        else if(input[i] >= 'A' && input[i] <= 'Z')// if the character is upper case
        {
            cout << (char)(inverseMod(x, 26) * (26 + input[i] - 'A' - y) % 26 + 'A');
        } 
        else//handles any non-alpha char, ex. a space will just be printed as a space
        {
            cout << input[i];
        }
    }
    cout << endl;
}

int inverseMod (int x, int y)
{
	int b0 = y, t, q;
    int x0 = 0; 
    int x1 = 1;
    if (y == 1)
    { 
    	return 1;
    }
    while (x > 1) 
    {
        q = x / y;
        t = y, y = x % y, x = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0)
    { 
    	x1 += b0;
    }
    
    return x1;
}