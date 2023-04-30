//  this project was created by muhammet cömert

#include<iostream>
#include<fstream>
#include <iomanip>
#include <locale.h>
#include <ctime>
#include<regex>
#include "windows.h"
#include <ctype.h>
#include "header.h"

using namespace std;

int main()
{
	int profil, islem, deger;    //secimlerin tutulacagi degiskenler
	system("CLS");

	// kullanicinin islem yapacagi birim seciliyor.
    etiketGeriDonus:
	cout << "\n-> Kiyafet Sepetine Hosgeldiniz" << endl;
	cout << "\n-> Yapmak istediginiz islemi secin : " << endl;
	cout << "#########################################\n";
	cout << "-> [1] Giris Yap" << endl;
	cout << "-> [2] Uye Kaydi" << endl;
	cout << "-> [3] Cikis" << endl;
	cout << "#########################################\n";
	cout << "->"; cin >> islem;

	if (islem < 4 && islem > 0)
	{
		if (islem == 2 || islem == 1)
		{
			islemler(islem);
		}
		else { return 0; } 	
	}
	else { cout << "Hatali deger girildi... Tekrar deneyin\n" << endl; return main(); }

	cout << endl;
	cout << "###########################################################\n";
	cout << "Yeni Islem Yapmak istiyormusunuz : " << endl;
	cout << "[1] = Evet" << endl;
	cout << "[2] = Hayir" << endl;
	cin >> deger;

	if (deger == 1) { system("CLS"); return main(); }
	else { return 0; }
} 
