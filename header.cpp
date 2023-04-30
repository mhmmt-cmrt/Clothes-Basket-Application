//  this project was created by muhammet

#include<iostream>
#include<iomanip>
#include<fstream>
#include<ctime>
#include<regex>
#include<array>
#include<chrono>
#include<string>
#include<conio.h>  //for _getch()
#include <sstream> //for string int convert stoi
#include<stdio.h>  //for rename remove
#include <locale.h>
#include "windows.h"
#include <ctype.h>

#include "header.h"

using namespace std;

Kisi::Kisi()
{
}

Kisi::Kisi(const string _ad, const string _soyad, const string _telNo)
{
	setAd(_ad);
	setSoyad(_soyad);
	setTelefonNo(_telNo);
}

Kisi::~Kisi()
{
}

void Kisi::setAd(const string _ad)
{
	this->ad = _ad;
}

string Kisi::getAd() const
{
	return this->ad;
}

void Kisi::setSoyad(const string _soyad)
{
	this->soyad = _soyad;
}

string Kisi::getSoyad() const
{
	return this->soyad;
}

void Kisi::setTelefonNo(const string _telNo)
{
	this->telNo = _telNo;
}

string Kisi::getTelefonNo() const
{
	return this->telNo;
}
//-----------------------------------Kisi sinifi sonu----------------------------
Kullanici::Kullanici()
{
	cout << "hatali giris !!!" << endl
		 << "lutfen kullaniciAdi,ePosta,adresIlce,sifre,"
		 << "indirimKodu, dogumTarihi eksiksiz girin" << endl;
}

Kullanici::Kullanici(const string ad, const string soyad, const string telNo, const string _KullaniciAdý,
					 const string _ePosta, const string _adresIlce, const string _sifre,
					 const string _dogumTarihi , const string _indirimKodu)
	:Kisi(ad,soyad,telNo)
{
	setKullaniciAdý(_KullaniciAdý);
	setEPosta(_ePosta);
	setAdresIlce(_adresIlce);
	setSifre(_sifre);
	setIndirimKodu(_indirimKodu);
	setDogumTarihi(_dogumTarihi);
}

Kullanici::~Kullanici()
{
}

void Kullanici::setKullaniciAdý(const string _KullaniciAdý)
{
		this->kullaniciAdý = _KullaniciAdý;
}

string Kullanici::getKullaniciAdý() const
{
	return this->kullaniciAdý;
}

void Kullanici::setEPosta(const string _ePosta)
{
	this->ePosta = _ePosta;
}

string Kullanici::getEPosta() const
{
	return this->ePosta;
}

void Kullanici::setAdresIlce(const string _adresÝlce)
{
	this->adresÝlce = _adresÝlce;
}

string Kullanici::getAdresIlce() const
{
	return this->adresÝlce;
}

void Kullanici::setSifre(const string _sifre)
{
	this->k_sifre = _sifre;
}

string Kullanici::getSifre() const
{
	return this->k_sifre;
}

void Kullanici::setIndirimKodu(const string _indirimKodu)
{
	this->indirimKodu = _indirimKodu;
}

string Kullanici::getIndirimKodu() const
{
	return this->indirimKodu;
}

void Kullanici::setDogumTarihi(const string _dogumTarihi)
{
	this->dogumTarihi  = _dogumTarihi;
}

string Kullanici::getDogumTarihi() const
{
	return this->dogumTarihi;
}
//--------------------Kullanici sinifi sonu--------------------------------------
Yonetici::Yonetici()
{
	cout << "hatali giris !!!" << endl
		 << "sifre girin" << endl;
}

Yonetici::Yonetici(const string ad, const string soyad, const string telNo, const string _sifre)
	:Kisi(ad,soyad, telNo)
{
	setSifre(_sifre);
}

void Yonetici::setSifre(const string _sifre)
{
	this->y_Sifre = _sifre;
}

string Yonetici::getSifre() const
{
	return this->y_Sifre;
}
//--------------------Yönetici sinifi sonu--------------------------------------
Zaman::Zaman()
{
	setSaat(0);
	setDakika(0);
}

Zaman::Zaman(int _iSaat, int _iDakika)
{
	setSaat(_iSaat);
	setDakika(_iDakika);
}

void Zaman::dakikaEkle(int _iDakika)
{
	int aDakika = this->dakika + _iDakika;
	this->dakika = aDakika % 60;
	this->saat += aDakika / 60;
	this->saat = this->saat % 24;
}


Zaman Zaman::operator+(int _iDakika) //saate dakika ekler
{
	Zaman temp;
	int aDakika = this->dakika + _iDakika;
	temp.dakika = aDakika % 60;
	temp.saat += this->saat + (aDakika / 60);
	temp.saat = (temp.saat % 24);
	return temp;

}
int Zaman::operator-(Zaman& zaman) //iki saat arasý mesaffeyi dakika cinsinden bulur
{

	int aDakika = this->dakika + this->saat * 60;
	int bDakika = zaman.dakika + zaman.saat * 60;

	return aDakika - bDakika;
}
bool Zaman::operator < (Zaman & zaman) //hangi saatin ilerde olduðunu bulmak için kullanýlýr
{
	int aDakika = this->dakika + this->saat * 60;
	int bDakika = zaman.dakika + zaman.saat * 60;

	return aDakika < bDakika;
}

void Zaman::operator = (string a) //stringi ayrýþtýrýr saate atar.
{
	this->saat = stoi(a.substr(0, 2));
	this->dakika = stoi(a.substr(3, 2));
}

ostream& operator << (ostream& output, const Zaman& z)
{
	//oprator asiri yukleme yapiliyor

	output << z.saat << ":"
		   << z.dakika;

	return output;
}

//istream& operator >> (istream& input, Zaman& z)
//{
//	//oprator asiri yukleme yapiliyor
//
//	input >> setw(2) >> z.saat;
//	input.ignore();
//	input >> setw(2) >> z.dakika;
//
//	return input;
//}

void Zaman::setSaat(int _iSaat)
{
	this->saat = _iSaat;
}

int Zaman::getSaat() const
{
	return this->saat;
}

void Zaman::setDakika(int _iDakika)
{
	this->dakika = _iDakika;
}

int Zaman::getDakika() const
{
	return this->dakika;
}
void Zaman:: sistemSaatiniAl()
{
	string saat;
	time_t tarih_saat = time(NULL);
	struct tm tarih_saat_bilgisi;
	localtime_s(&tarih_saat_bilgisi, &tarih_saat);
	this->saat = tarih_saat_bilgisi.tm_hour;
	this->dakika = tarih_saat_bilgisi.tm_min;
}
string Zaman::getGuncelTarih()
{
	string tarih;
	time_t tarih_saat = time(NULL);
	struct tm tarih_saat_bilgisi;
	localtime_s(&tarih_saat_bilgisi, &tarih_saat);

	return tarih = to_string(tarih_saat_bilgisi.tm_mday) 
		         + "-" + to_string(tarih_saat_bilgisi.tm_mon + 1)
		         + "-" + to_string(tarih_saat_bilgisi.tm_year + 1900);
}

//--------------------Zaman sinifi sonu-------------------------------------- 
Kurye::Kurye()
{
}

Kurye::Kurye(string ad, string soyad, string telNo, Zaman &zaman, int _siparisNo)
	:Kisi(ad,soyad,telNo)
{
	setSiparisNumaralari(_siparisNo);
	setDagitimBitisler(zaman);
}

void Kurye::setSiparisNumaralari(int _siparisNo)
{
	siparisNo = _siparisNo;
}
int Kurye::getSiparisNumaralari() const
{
	return siparisNo;
}
void Kurye::setDagitimBitisler(Zaman & _dagitim_Bitiþler)
{
	this->dagitim_Bitiþler = _dagitim_Bitiþler;
}
Zaman Kurye::getDagitimBitisler() const
{
	return this->dagitim_Bitiþler;
}
//--------------------Kurye sinifi sonu--------------------------------------

Kiyafet::Kiyafet()
{
}

Kiyafet::Kiyafet(string _kategori, string _kiyafet_Adi, double _fiyat, std::string _beden, std::string _renk)
{
	setKategori(_kategori);
	setKiyafetAdi(_kiyafet_Adi);
	setFiyat(_fiyat);
	setBeden(_beden);
	setRenk(_renk);
}

void Kiyafet::setKategori(string _kategori)
{
	this->kategori = _kategori;
}

string Kiyafet::getKategori() const
{
	return this->kategori;
}

void Kiyafet::setKiyafetAdi(string _kiyafet_Adi)
{
	this->kiyafet_Adi = _kiyafet_Adi;
}

string Kiyafet::getKiyafetAdi() const
{
	return this->kiyafet_Adi;
}

void Kiyafet::setFiyat(double _fiyat)
{
	this->fiyat = _fiyat;
}

double Kiyafet::getFiyat() const
{
	return this->fiyat;
}

void Kiyafet::setBeden(string _beden)
{
	this->beden = _beden;
}

string Kiyafet::getBeden() const
{
	return this->beden;
}

void Kiyafet::setRenk(string _renk)
{
	this->renk = _renk;
}

string Kiyafet::getRenk() const
{
	return this->renk;
}
//-----------------------------Kiyafet sýnýfý sonu----------------------
Siparis::Siparis()
{
	cout << "hatali giris"
		 << "siparis_No, siparis_Fiyat, siparis_Baslangic, siparis_Ulasim " << endl;
}

Siparis::Siparis(int _siparis_No, double _siparis_Fiyat, Zaman& _siparis_Baslangic, Zaman& _siparis_Ulasim)
{
	setSiparisNo(_siparis_No);
	setSiparisFiyat(_siparis_Fiyat);
	setSiparisBaslangic(_siparis_Baslangic);
	setSiparisUlasim(_siparis_Ulasim);
}
void Siparis::setSiparisNo(int _siparis_No)
{
	this->siparis_No = _siparis_No;
}

int Siparis::getSiparisNo() const
{
	return this->siparis_No;
}

void Siparis::setSiparisFiyat(double _siparis_Fiyat)
{
	this->siparis_Fiyat = _siparis_Fiyat;
}

double Siparis::getSiparisFiyat() const
{
	return this->siparis_Fiyat;
}

void Siparis::setSiparisBaslangic(Zaman &_siparis_Baslangic)
{
	this->siparis_Baslangic = _siparis_Baslangic;
}

Zaman Siparis::getSiparisBaslangic() const
{
	return this->siparis_Baslangic;
}

void Siparis::setSiparisUlasim(Zaman &_siparis_Ulasim)
{
	this->siparis_Ulasim = _siparis_Ulasim;
}

Zaman Siparis::getSiparisUlasim() const
{
	return this->siparis_Ulasim;
}
//-----------------------------Siparis sýnýfý sonu-----------------------------------------------

void islemler(int islem)
{
	if (islem == 1)                  // giriþ yapma iþlemleri
	{
		int profil;
		etiketProfilsec:
		cout << "-> Giris Yapmak Istediginiz Profili Secin :" << endl;
		cout << "#########################################\n";
		cout << "-> [1] Yonetici Girisi" << endl;
		cout << "-> [2] Musteri Girisi" << endl;
		cout << "#########################################\n";
		cout << "->"; cin >> profil;

		if (!(profil < 3 && profil > 0)) { goto etiketProfilsec;}

		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>yonetici girisi iþlemleri<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		//#######################################################################################

		if (profil == 1)			
		{
			etiketYoneticigiris:
			string sifre;
			cout << "Hosgeldiniz Yonetici...!" << endl;
			cout << "Lutfen Yonetici Sifrenizi Girin\n";
			cout << "-> "; cin >> sifre;

			string m_sifre;
			string ad;
			string soyad;
			string tel;

			ifstream ifDosya1;
			ifDosya1.open("Yoneticiler.txt");
			while (ifDosya1 >> m_sifre)
			{
				ifDosya1 >> ad;
				ifDosya1 >> soyad;
				ifDosya1 >> tel;
			}
			ifDosya1.close();

			if (sifre == m_sifre)							 ////Yönetici girisi dogrulama
			{
				system("CLS");
				system("color 9e");
				cout << "Giris basarili" << endl;
				Yonetici yonetici(ad,soyad, tel, m_sifre);
				//Yönetici islemlerini gerçekleþtirme
				etiketYoneticiIslemSecme:
				int task;
				cout << "Yapmak Istediginiz Islemi Secer misiniz" << endl;
				cout << "############################################\n";
				cout << "-> [1] Kiyafet Kategorisine Urun Girisi Yap." << endl;
				cout << "-> [2] Sisteme Kurye Ekle." << endl;
				cout << "-> [3] Sikayet ~ Oneri Oku." << endl;
				cout << "-> [4] Indirim Kodu Tanimla." << endl;
				cout << "-> [5] Siparislerin Faturalarini goruntule" << endl;
				cout << "############################################\n";
				cout << "->"; cin >> task;
				//---------------------------***** ürün girisi yapýlan kýsým ******--------------
				if (task == 1)
				{
					int m_iKategori;
					double m_fiyat;
					string m_kiyafet_Adi;
					string m_sKategori;
					string m_beden;
					string m_renk;
					string dosyaAdi;
					string bedenBilgiDosyasi;
					string renkBilgiDosyasi;

				    etiketKategori:  //etiket 
					cout << "Hangi Kategoriye urun girisi yaplacagini secin : " << endl;
					cout << "############################################\n";
					cout << "-> [1] Pantolon " << endl;
					cout << "-> [2] Gomlek " << endl;
					cout << "-> [3] Tisort " << endl;
					cout << "-> [4] Elbise " << endl;
					cout << "-> [5] Ayakkabi " << endl;
					cout << "-> [6] Etek " << endl;
					cout << "############################################\n";
					cout << "->"; cin >> m_iKategori;

					if (m_iKategori == 1)
					{
						m_sKategori = "Pantolon", dosyaAdi = "Pantolon.txt",
						bedenBilgiDosyasi = "BedenPantolon.txt"; renkBilgiDosyasi = "RenkPantolon.txt";
					}
					else if (m_iKategori == 2) 
					{
						m_sKategori = "Gomlek";   dosyaAdi = "Gomlek.txt"; 
						bedenBilgiDosyasi = "BedenGomlek.txt"; renkBilgiDosyasi = "RenkGomlek.txt";
					}
					else if (m_iKategori == 3) 
					{ 
						m_sKategori = "Tisort";   dosyaAdi = "Tisort.txt";
						bedenBilgiDosyasi = "BedenTisort.txt"; renkBilgiDosyasi = "RenkTisort.txt";
					}
					else if (m_iKategori == 4) 
					{
						m_sKategori = "Elbise";   dosyaAdi = "Elbise.txt";
						bedenBilgiDosyasi = "BedenElbise.txt"; renkBilgiDosyasi = "RenkElbise.txt";
					}
					else if (m_iKategori == 5) 
					{ 
						m_sKategori = "Ayakkabi"; dosyaAdi = "Ayakkabi.txt";
						bedenBilgiDosyasi = "BedenAyakkabi.txt"; renkBilgiDosyasi = "RenkAyakkabi.txt";
					}
					else if (m_iKategori == 6) 
					{ 
						m_sKategori = "Etek";     dosyaAdi = "Etek.txt";
						bedenBilgiDosyasi = "BedenEtek.txt"; renkBilgiDosyasi = "RenkEtek.txt";
					}
					else { cout << "hatali deger girisi.\n Tekrar deneyin\n"; goto etiketKategori; }

					cout << "Kiyafet Adini Girin : " << endl;
					cout << "->"; cin.ignore(); getline(cin, m_kiyafet_Adi);
					cout << "Kiyafet Fiyati Girin : " << endl;
					cout << "->"; cin >> m_fiyat;
					
					ofstream ofDosya2;      //dosya nesnesi olusturuluyor
					ofDosya2.open(dosyaAdi, ios::app);
					ofDosya2 << left
						<< setw(20) << m_sKategori
						<< setw(20) << m_kiyafet_Adi
						<< setw(20) << m_fiyat << endl;	
					ofDosya2.close(); //dosya kapama

					etiketRenkBedenEkle:
					cout << "Kiyafet Bedeni Girin : " << endl;
					cout << "->"; cin >> m_beden;
					cout << "Kiyafet Rengi Girin : " << endl;
					cout << "->"; cin >> m_renk;

					ofstream ofBedenDosya;      //dosya nesnesi olusturuluyor
					ofBedenDosya.open(bedenBilgiDosyasi, ios::app);
					ofBedenDosya << left
						<< setw(20) << m_kiyafet_Adi
						<< setw(20) << m_beden << endl;
					ofBedenDosya.close(); //dosya kapama

					ofstream ofRenkDosya; //dosya nesnesi olusturuluyor
					ofRenkDosya.open(renkBilgiDosyasi, ios::app);
					ofRenkDosya << left
						<< setw(20) << m_kiyafet_Adi
						<< setw(20) << m_renk << endl;
					ofRenkDosya.close(); //dosya kapama

					int aradeger;
					cout << "Bu urun icin baska renk-beden eklemek istiyor musunuz ? " << endl;
					cout << "[1] = Evet" << endl;
					cout << "[2] = Hayir" << endl;
					cin >> aradeger;
					if (aradeger == 1) { goto etiketRenkBedenEkle; }
						
					int deger;
					cout << "Urun eklenmistir.!!! " << endl << endl;
					cout << "Baska urun eklemek istiyor musunuz ? " << endl;
					cout << "[1] = Evet" << endl;
					cout << "[2] = Hayir" << endl;
					cin >> deger;

					if (deger == 1) { goto etiketKategori; }
				}				
				//------------------***** kurye ekleme yapýlan kýsým ******----------------------
			    else if (task == 2)  
				{
					string k_Ad, k_Soyad, k_Tel, strData;
					int saat = 0,dakika= 0;
					Zaman zaman;
					int siparisNo;

					cout << "-> Kuryenin Adini Girin " << endl;
					cout << "->"; cin >> k_Ad;
					cout << "---------------------------------------------------\n";
					cout << "-> Kuryenin Soyadini Girin" << endl;
					cout << "->"; cin >> k_Soyad;
					cout << "---------------------------------------------------\n";
					cout << "-> Kuryenin Telefon Numarasini Girin" << endl;
					cout << "->"; cin >> k_Tel;
					cout << "-> Kuryenin kurye Nosunu Girin" << endl;
					cout << "->"; cin >> siparisNo;
					cout << "-> Kuryenin Dagitim Bitis Zamanini  Saat Dakaki Olarak Ayri Ayri Girin" << endl;
					cout << "-> Saat : ";   cin  >> saat;
					cout << "-> Dakika : "; cin  >> dakika;
					zaman.setSaat(saat);
					zaman.setDakika(dakika);

					Kurye kurye(k_Ad, k_Soyad, k_Tel, zaman, siparisNo);

					ofstream ofDosyaKurye;							     //dosya nesnesi olusturuluyor
					ofDosyaKurye.open("Kuryeler.txt", ios::app);		 //dosya acma
					ofDosyaKurye << left
						<< setw(20) << k_Ad
						<< setw(20) << k_Soyad
						<< setw(20) << k_Tel
						<< setw(20) << siparisNo
						<< zaman<<endl;
					ofDosyaKurye.close();
				}
				//----------------***** sikayet öneri okunan kýsým *****-------------------------
				else if (task == 3) 
				{
					string strData;
					ifstream ifDosya3;					
					ifDosya3.open("Sikayet_Oneri.txt");
					cout << ">> ";
					while (ifDosya3 >> strData)                      
					{ 
						if (strData == "#")
						{
							cout << strData << " ";
							cout << endl;
							cout << ">> ";
						}
						else
						{
							cout << strData << " "; 
						}				
					}
					cout << endl;
				}
				//-----------------***** indirim kodu tanýmlamasý yapýlan kýsým *****------------
				else if (task == 4)											
				{
					string yeniIndirimKodu, aranilanKullanici;
					int value;
					cout << "Tanimlanacak olan indirim kodunu girin : " << endl;
					cout << "->"; cin >> yeniIndirimKodu;
					cout << "Indirim Kodunu nereye tanimlayacaksiniz ?" << endl;
					cout << "[1] = Sisteme Indirim Kodu Tanimla" << endl;
					cout << "[2] = Kullaniciya Indirim Kodu Tanimla" << endl;
					cout << "->"; cin >> value;
					if (value == 1) //sisteme ekleme yapar
					{
						ofstream ofDosya4;									 //dosya nesnesi olusturuluyor
						ofDosya4.open("indirimKodlari.txt", ios::app);		 //dosya acma
						ofDosya4 << left
							<< setw(20) << yeniIndirimKodu << endl;
						ofDosya4.close();	//dosya kapama
					}
					if(value == 2)//kullaniciya ekleme yapar.
					{
						string ad, soyad, telNo, kullaniciAdi, ePosta,
							adresIlce, sifre, indirimKodu, dogumTarihi;
						cout << "Indirim Kodu Tanimlanacak Kisinin Kullanici Adini Girin ?" << endl;
						cout << "->"; cin >> aranilanKullanici;

						ofstream ofDosya17;
						ifstream ifDosya16;
						ifDosya16.open("Kullanicilar.txt");
						ofDosya17.open("deneme1.txt", ios::app);
						//---------------------------
						while (ifDosya16 >> ad)                 //adý oku
						{
							ofDosya17 << left << setw(20) << ad;
							ifDosya16 >> soyad; ofDosya17 << setw(20) << soyad;    //soyad okuyaz
							ifDosya16 >> telNo; ofDosya17 << setw(20) << telNo;    //telno okuyaz
							ifDosya16 >> kullaniciAdi;						     //k_adý

							if (kullaniciAdi == aranilanKullanici)
							{
								ofDosya17 << setw(20) << kullaniciAdi;
								ifDosya16 >> ePosta;      ofDosya17 << setw(20) << ePosta;		    //ePosta
								ifDosya16 >> adresIlce;   ofDosya17 << setw(20) << adresIlce;		//adresIlce
								ifDosya16 >> sifre;		  ofDosya17 << setw(20) << sifre;
								ifDosya16 >> dogumTarihi; ofDosya17 << setw(20) << dogumTarihi;
								ifDosya16 >> indirimKodu; ofDosya17 << setw(20) << yeniIndirimKodu << endl; //yeni kod
							}
							else
							{
								ofDosya17 << setw(20) << kullaniciAdi;                                   //k adý yaz
								ifDosya16 >> ePosta;	  ofDosya17 << setw(20) << ePosta;			     //eposta
								ifDosya16 >> adresIlce;   ofDosya17 << setw(20) << adresIlce;			 //adresilce
								ifDosya16 >> sifre;       ofDosya17 << setw(20) << sifre;
								ifDosya16 >> dogumTarihi; ofDosya17 << setw(20) << dogumTarihi;          //indirimkodu//k_sifre
								ifDosya16 >> indirimKodu; ofDosya17 << setw(20) << indirimKodu << endl;	 //dogumtarihi
							}
						}

						ifDosya16.close(); //dosya kapama
						ofDosya17.close();   //dosya kapama

						string dosya = "Kullanicilar.txt";
						int a = remove(dosya.c_str());
						int b = rename("deneme1.txt", dosya.c_str());	
					}
					cout << "Indirim kodunuz tanimlanmistir..!!!" << endl<<endl;
				}
				//-------------------------***** fatura görüntülenmesi yapýlan kýsým *****-------
				else if (task == 5)										
				{
					cout << "##############################################################" << endl;					
					cout << left << setw(10) << "Adi" << setw(10) << "Soyadi" << setw(10) << "Kategori"
						 << setw(13) << "Kiyafet_Adi" << setw(10) << "Fiyat" << setw(10)
						 << "Beden" << setw(10) << "Renk" << setw(20) << "Saat--Tarih" << endl;
				
					string strData;
					double total = 0;
					ifstream ifDosya14;
					ifDosya14.open("Faturalar.txt");
					while (ifDosya14 >> strData)  // verileri okur
					{
						cout <<left<< setw(10) << strData;
						ifDosya14 >> strData; cout << setw(10) << strData;
						ifDosya14 >> strData; cout << setw(10) << strData;
						ifDosya14 >> strData; cout << setw(13) << strData;
						ifDosya14 >> strData; cout << setw(10) << strData; total += stod(strData);
						ifDosya14 >> strData; cout << setw(10) << strData;
						ifDosya14 >> strData; cout << setw(10) << strData;
						ifDosya14 >> strData; cout << setw(20) << strData << endl;
					}
					ifDosya14.close();
					cout << endl << "TOPLAM UCRET : " << total << "TL" << endl;
				}

				else {cout << "Hatali Deger Girildi. Tekrar Deneyin" << endl; goto etiketYoneticiIslemSecme;}
			}						 
			else                                             //giris basarisiz
			{
				cout << "Giris basarisiz ...Tekrar deneyin" << endl;
				goto etiketYoneticigiris;
			}
		}
		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>musteri girisi iþlemleri<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		//#######################################################################################
		if (profil == 2)				      
		{
			etiketMusteriGiris:
			string ad;				  //dosyadan okunacak verilerin atanacagý data memberlar.
			string soyad;
			string telNo;
			string kullaniciAdý;               
			string ePosta;
			string adresIlce;
			string k_sifre;
			string indirimKodu;
			string dogumTarihi;
			bool eslesmeDurumu = false;

			string k_adi;					 //kontrol için kullanýcýdan alýnan degerler
			string k_sfr;

			cout << "Hosgeldiniz...!" << endl;
			cout << "Lutfen Kullanici Adinizi Girin\n";
			cout << "-> "; cin >> k_adi;
			cout << "Lutfen Sifrenizi Girin\n";
			cout << "-> "; cin >> k_sfr;

			string strData;
			ifstream ifDosya5;
			ifDosya5.open("Kullanicilar.txt");
			
			while (ifDosya5 >> ad)                        
			{
				ifDosya5 >> soyad;
				ifDosya5 >> telNo;
				ifDosya5 >> kullaniciAdý;
				ifDosya5 >> ePosta;
				ifDosya5 >> adresIlce;
				ifDosya5 >> k_sifre;
				ifDosya5 >> dogumTarihi;
				ifDosya5 >> indirimKodu;

				if ((k_adi == kullaniciAdý) && (k_sfr == k_sifre))   //musteri girisi dogrulama
				{
					system("CLS");
					system("color 9e");
					ifDosya5.close();
					eslesmeDurumu = true;
					cout << ">>>>>>>>>>>>>>>Giris basarili<<<<<<<<<<<<<<<<" << endl;
					Kullanici kullanici(ad, soyad, telNo, kullaniciAdý, ePosta, 
						                adresIlce, k_sifre, dogumTarihi, indirimKodu);

					system("CLS");
					 
					int task;
					cout << "Yapmak Istediginiz Islemi Secin " << endl;
					cout << "############################################\n";
					cout << "-> [1] Kiyafetleri Gor ve Urun Secimi Yap." << endl;
					cout << "-> [2] Siparis Takip." << endl;
					cout << "-> [3] Sikayet\Oneri de Bulun." << endl;
					cout << "-> [4] Sifre Degistir." << endl;
					cout << "-> [5] Geri Don" << endl;
					cout << "############################################\n";
					cout << "->"; cin >> task;

					//------------***** kýyafet kategörilerinin gösterimi ve ürün secimi *****-----------------

					if (task == 1)  
					{
						int kategori = 0;
						string dosyaAdi;
						string bedenBilgiDosyasi;
						string renkBilgiDosyasi;
					    etiketKategoriSec:
						cout << "Satin Alma Yapacaginiz Urun Kategorisini secin : " << endl;
						cout << "################################################\n";
						cout << "-> [1] Pantolon " << endl;
						cout << "-> [2] Gomlek " << endl;
						cout << "-> [3] Tisort " << endl;
						cout << "-> [4] Elbise " << endl;
						cout << "-> [5] Ayakkabi " << endl;
						cout << "-> [6] Etek " << endl;
						cout << "################################################\n";
						cout << "->"; cin >> kategori;

						if (kategori == 1)
						{
							dosyaAdi = "Pantolon.txt", bedenBilgiDosyasi = "BedenPantolon.txt", renkBilgiDosyasi = "RenkPantolon.txt";	 
					    }
						else if (kategori == 2) 
						{ 
							dosyaAdi = "Gomlek.txt", bedenBilgiDosyasi = "BedenGomlek.txt", renkBilgiDosyasi = "RenkGomlek.txt";
						}
						else if (kategori == 3) 
						{ 
							dosyaAdi = "Tisort.txt", bedenBilgiDosyasi = "BedenTisort.txt", renkBilgiDosyasi = "RenkTisort.txt";
						}
						else if (kategori == 4) 
						{ 
							dosyaAdi = "Elbise.txt", bedenBilgiDosyasi = "BedenElbise.txt", renkBilgiDosyasi = "RenkElbise.txt";
						}
						else if (kategori == 5) 
						{ 
							dosyaAdi = "Ayakkabi.txt", bedenBilgiDosyasi = "BedenAyakkabi.txt", renkBilgiDosyasi = "RenkAyakkabi.txt";
						}
						else if (kategori == 6) 
						{ 
							dosyaAdi = "Etek.txt", bedenBilgiDosyasi = "BedenEtek.txt", renkBilgiDosyasi = "RenkEtek.txt";
						}
						else { cout << "hatali deger girildi. Tekrar deneyin\n"; goto etiketKategoriSec; }

						system("CLS");
						int urunNo;//ürün secim icin
						cout << "Satin alinmak istenilen urunun numarasini girin."<<endl;
						cout << "###########################################################" << endl;
						cout << left << setw(12) << "Urunun No" << setw(20) << "Urunun Kategorisi"
							<< setw(20) << "Urunun Ismi"
							<< setw(20) << "Urunun Fiyati"<< endl;

						int i = 0;//indis icin  //Ürün Secimi için ürünün satir nosu alinan kisim
						ifstream ifDosya6;                
						ifDosya6.open(dosyaAdi);
						while (ifDosya6 >> strData)  // verileri okur
						{
							cout << left << "-> " <<"[ "<< i << setw(6) << " ]" ;
							cout<< setw(20) << strData;
							ifDosya6 >> strData; cout << setw(20) << strData;
							ifDosya6 >> strData; cout << setw(20) << strData << endl;
							i++;
						}
						ifDosya6.close();
						cin >> urunNo;
						//--------------------------------------------------------
						int urunBedenNo;//beden secim icin  //Beden Secimi için bedenin satir nosu alinan kisim
						cout << "Urun icin beden seciniz" <<endl;
						cout << "#############################################"<<endl;
						cout << left << setw(12) << "Urunun No" << setw(20) << "Urunun Ismi"
							 << setw(20) << "Urun Bedeni" << endl;

						int j = 0; //indis icin
						ifstream ifDosyaBeden;
						ifDosyaBeden.open(bedenBilgiDosyasi);
						while (ifDosyaBeden >> strData)  // verileri okur
						{
							cout << left << "-> " << "[ " << j << setw(6) << " ]";
							cout << setw(20) << strData;
							ifDosyaBeden >> strData; cout << setw(20) << strData << endl;
							j++;
						}
						ifDosyaBeden.close();
						cin >> urunBedenNo;
						//-------------------------------------------------------------
						int urunRenkNo;//renk secim icin  //Renk Secimi için Renk satir nosu alinan kisim
						cout << "Urun icin renk seciniz" << endl;
						cout << "#############################################" << endl;;
						cout << left << setw(12) << "Urunun No" << setw(20) << "Urunun Ismi"
							<< setw(20) << "Urun Rengi" << endl;

						int k = 0; //indis icin
						ifstream ifDosyaRenk;
						ifDosyaRenk.open(renkBilgiDosyasi);
						while (ifDosyaRenk >> strData)  // verileri okur
						{
							cout << left << "-> " << "[ " << k << setw(6) << " ]";
							cout << setw(20) << strData;
							ifDosyaRenk >> strData; cout << setw(20) << strData << endl;
							k++;
						}
						ifDosyaRenk.close();
						cin >> urunRenkNo;
						//alinan satir numaralarina göre ürünü secen ve faturasýný dosyaya kaydeden fonksiyon
						urunSecimi(kullanici,kategori,urunNo, urunBedenNo, urunRenkNo);
						cout << "###################################################" << endl;
						cout << "Urun sepetinize eklenmistir" << endl;

						int secim;
						cout << "sepetinize bir urun daha eklemek istermisiniz?" << endl;
						cout << "[1] = Evet" << endl;
						cout << "[2] = Hayir" << endl;
						cin >> secim;
						if (secim == 1) { system("CLS"); goto etiketKategoriSec; }

						//müsteriye fatura gösteren kisim
						cout << "###################################################" << endl; //Fatura gösterme						
						cout <<setw(10) <<"Adi" <<setw(10)<<"Soyadi" << setw(10) <<"Kategori" 
							 << setw(20) <<"Kiyafet_Adi" << setw(10) <<"Fiyat" << setw(10) 
							 <<"Beden" << setw(10) <<"Renk" << setw(20) <<"Saat~Tarih" << endl;

						double total = 0;
						string strData, faturaAd, faturaSoyad;
						ifstream ifDosya13;
						ifDosya13.open("Faturalar.txt");
						while(ifDosya13 >> faturaAd)  // verileri okur
						{
							ifDosya13 >> faturaSoyad;
							if ((faturaAd == kullanici.getAd()) && (faturaSoyad == kullanici.getSoyad())) //aranan satýr buysa
							{
								cout << setw(10) << faturaAd;
								cout << setw(10) << faturaSoyad;
								ifDosya13 >> strData; cout << setw(10) << strData;
								ifDosya13 >> strData; cout << setw(20) << strData;
								ifDosya13 >> strData; cout << setw(10) << strData; total += stod(strData);
								ifDosya13 >> strData; cout << setw(10) << strData;
								ifDosya13 >> strData; cout << setw(10) << strData;
								ifDosya13 >> strData; cout << setw(10) << strData << endl;
							}
							else
							{
								ifDosya13 >> strData; 
								ifDosya13 >> strData; 
								ifDosya13 >> strData; 
								ifDosya13 >> strData; 
								ifDosya13 >> strData; 
								ifDosya13 >> strData;
							}
						}
						ifDosya13.close();
						cout << endl << "TOPLAM UCRET : " << total << "TL" << endl;

						//----------------------------------------------------------------------------------
						//siparis oluþturulan kýsým.
						
						string adres; int sure = 0;
						adres = kullanici.getAdresIlce();

						if (adres == "Ortahisar")      { sure = 35; }
						else if (adres == "Akcaabat")  { sure = 50; }
						else if (adres == "Vakfikebir"){ sure = 90; }
						else if (adres == "Besikduzu") { sure = 110;}
						else if (adres == "Yomra")     { sure = 55; }
						else if (adres == "Arsin")     { sure = 70; }
						else if (adres == "Arakli")    { sure = 100;}

						int enYakýnKuryeNo;
						int eklemeDurumu = 0;
						bool aradeger = true;
						//dosyadan okulanacak verilerin kaydedileceði datalar
						string adVeri,soyadVeri,telVeri, kuryeNo, kuryeBitis;
						Zaman kuryeZaman; //kurye zamaný 
						Zaman sistemZaman; //sistem saati
						Zaman tempZaman; //yeni ulasým saati
						int enYakinKuryeZamani = 1440; //60*24
						sistemZaman.sistemSaatiniAl();

						ifstream ifDosyaKurye;       //dosya nesnesi olusturuluyor
						ofstream ofYeniKuryeDosya;

						ofYeniKuryeDosya.open("Deneme.txt",ios::app); //kuryenin yeni ulaþým zamaný için kullanýlacak
						ifDosyaKurye.open("Kuryeler.txt");

						while (ifDosyaKurye >> adVeri)  // verileri okur
						{
							ofYeniKuryeDosya << left << setw(20) << adVeri;
							ifDosyaKurye >> soyadVeri; ofYeniKuryeDosya << setw(20) << soyadVeri;
							ifDosyaKurye >> telVeri; ofYeniKuryeDosya << setw(20) << telVeri;
							ifDosyaKurye >> kuryeNo; ofYeniKuryeDosya << setw(20) << kuryeNo;
							ifDosyaKurye >> kuryeBitis;
							kuryeZaman = kuryeBitis;																					
							if (kuryeZaman < sistemZaman)   //operator overloading
							{
								if (aradeger)
								{
									eklemeDurumu++;
									tempZaman = (sistemZaman + sure);
									ofYeniKuryeDosya <<right<<setfill('0') << setw(2)<<tempZaman.getSaat() << ":" 
										             <<setw(2)<<tempZaman.getDakika()<< setfill(' ') << endl; //yeni ulasým zamaný
									string sis_zam;
									sis_zam = to_string(sistemZaman.getSaat()) + ":" + to_string(sistemZaman.getDakika());
									ofstream ofDosyaSiparis;       //siparis txt
									ofDosyaSiparis.open("Siparisler.txt", ios::app); //dosya acma
									ofDosyaSiparis << left
										<< setw(20) << kuryeNo //kurye no (zamaný sistem zamanýndan küçük olanlarýn ilki)
										<< setw(20) << adres //varýþ noktasý
										<< setw(20) << sis_zam//siparis baþlangýç zamaný + //operator overloading //20 geniþliðinden dolayý cast yaptýk
										<< setw(20) << sure //süre
										<<right<<setfill('0') << setw(2) << tempZaman.getSaat() <<":" 
										                      << setw(2) << tempZaman.getDakika() << setfill(' ') << endl;  //operator overloading
									ofDosyaSiparis.close(); //dosya kapama
									aradeger = false;
								}
								else
								{
									ofYeniKuryeDosya << right << setfill('0') << setw(2) << kuryeZaman.getSaat() << ":" 
										             << setw(2) << kuryeZaman.getDakika() << setfill(' ') << endl;
								}
							}							
							else 
							{
								ofYeniKuryeDosya << right << setfill('0') << setw(2) << kuryeZaman.getSaat() << ":" 
									             << setw(2) << kuryeZaman.getDakika() << setfill(' ') << endl;
								if ((kuryeZaman - sistemZaman) < enYakinKuryeZamani) //operator overloading)
								{
									enYakinKuryeZamani = (kuryeZaman - sistemZaman);
								}								
							}					
						}
						ifDosyaKurye.close(); //dosya kapama
						ofYeniKuryeDosya.close();
						string dosya = "Kuryeler.txt";
						int a = remove(dosya.c_str());
						int b = rename("Deneme.txt", dosya.c_str());
						//-----------------------------------------------------------------------------------------------
						bool aradeger1 = true;
						string adVeri1, soyadVeri1, telVeri1, kuryeNo1, kuryeBitis1;
						Zaman kuryeZaman1;
						Zaman tempZaman1;

						if (eklemeDurumu == 0)  //yukarýda kurye ekleme olmadýysa en yakýný ekleyen kod
						{
							ifstream ifDosyaKurye1;       //dosya nesnesi olusturuluyor
							ofstream ofYeniKuryeDosya1;
							ofYeniKuryeDosya1.open("Deneme1.txt", ios::app); //kuryenin yeni ulaþým zamaný için kullanýlacak
							ifDosyaKurye1.open("Kuryeler.txt");
							while (ifDosyaKurye1 >> adVeri1)  // verileri okur
							{
								ofYeniKuryeDosya1 << left << setw(20) << adVeri1;
								ifDosyaKurye1 >> soyadVeri1; ofYeniKuryeDosya1 << setw(20) << soyadVeri1;
								ifDosyaKurye1 >> telVeri1; ofYeniKuryeDosya1 << setw(20) << telVeri1;
								ifDosyaKurye1 >> kuryeNo1; ofYeniKuryeDosya1 << setw(20) << kuryeNo1;
								ifDosyaKurye1 >> kuryeBitis1;  //operator overloading
								kuryeZaman1 = kuryeBitis1;
								if (enYakinKuryeZamani == (kuryeZaman1 - sistemZaman))   //operator overloading
								{
									if (aradeger1)//eger ayný saat birden çoksa sadece ilk eþlesen degeri alýr
									{
										tempZaman1 = (kuryeZaman1 + sure);
										ofYeniKuryeDosya1<<right<< setfill('0') << setw(2) << tempZaman1.getSaat() << ":" 
											             << setw(2) << tempZaman1.getDakika() << setfill(' ') << endl; //yeni ulasým zamaný
										string zam;
										zam = to_string(sistemZaman.getSaat()) + ":" + to_string(sistemZaman.getDakika());
										ofstream ofDosyaSiparis1;       //siparis txt
										ofDosyaSiparis1.open("Siparisler.txt", ios::app); //dosya acma
										ofDosyaSiparis1 << left
											<< setw(20) << kuryeNo1 //kurye no (zamaný sistem zamanýndan küçük olanlarýn ilki)
											<< setw(20) << adres //varýþ noktasý
											<< setw(20) << zam//siparis baþlangýç zamaný  +  //operator overloading
											<< setw(20) << sure //süre
											<<right<< setfill('0') << setw(2) << tempZaman1.getSaat() << ":" 
											<< setw(2) << tempZaman1.getDakika() << setfill(' ') << endl;  //operator overloading
										ofDosyaSiparis1.close(); //dosya kapama
										aradeger1 = false;
									}
									else
									{										
										ofYeniKuryeDosya1 << right << setfill('0') << setw(2) << kuryeZaman1.getSaat() << ":" 
											              << setw(2) << kuryeZaman1.getDakika() << setfill(' ') << endl;
									}
								}
								else
								{
									ofYeniKuryeDosya1 << right << setfill('0') << setw(2) << kuryeZaman1.getSaat() << ":" 
										              << setw(2) << kuryeZaman1.getDakika() << setfill(' ') << endl;
								}								
							}
							ifDosyaKurye1.close(); //dosya kapama
							ofYeniKuryeDosya1.close();

							string dosya = "Kuryeler.txt";

							int a = remove(dosya.c_str());
							int b = rename("Deneme1.txt", dosya.c_str());
						}
					}

					///--------------***** siparis takip yapilan kisim *****-------------------

					else if (task == 2)  
					{						
					    int sayac = 0;
						cout << "########################################################"; //Fatura gösterme	
						cout << "########################################################" << endl;
						cout << left<<setw(15) << "Siparis_NO" << setw(15) << "Kurye_No" 
							 << setw(20) << "Varis_Noktasi" << setw(20) << "Baslangic_Zamani"
							 << setw(10) << "Sure" << setw(20) << "Ulasim_Zamani" << endl;
						string strVeri2;
						ifstream ifDosyaSiparisTakip;       //dosya nesnesi olusturuluyor
						ifDosyaSiparisTakip.open("Siparisler.txt");
						while (ifDosyaSiparisTakip >> strVeri2)  // verileri okur
						{
							cout << left << setw(15) << sayac;
							cout << setw(15) << strVeri2;
							ifDosyaSiparisTakip >> strVeri2; cout << setw(20) << strVeri2;
							ifDosyaSiparisTakip >> strVeri2; cout << setw(20) << strVeri2;
							ifDosyaSiparisTakip >> strVeri2; cout << setw(10) << strVeri2;
							ifDosyaSiparisTakip >> strVeri2; cout << strVeri2 <<endl;
							sayac++;
						}
						ifDosyaSiparisTakip.close(); //dosya kapama
					}

					//--------------***** sikayet öneri yapýlan kýsým *****---------------------

					else if (task == 3)  
					{
						vector<string>name;
						string st;
						int i = 0;

						cout << "Lutfen sikayet ve onerinizi maximum 1000 kelime olacak sekilde girin.  "<<endl;
						cout << "Sonlandirmak icin Sikayet ve Onerinizin sonuna bir bosluk ve ' # ' isaretini ekleyin, enter a basin" << endl;
						cout << "#################################################################################" << endl;
						cout << "-> ";
						for (int i = 0; (name.size() < 1000 && st != "#"); i++)
						{
							cin >> st;
							name.push_back(st);
						}				
						ofstream sikayetfile;
						sikayetfile.open("Sikayet_Oneri.txt", ios::app);
						for (int i = 0; i < name.size(); i++)
						{
							sikayetfile << left << name[i] << " ";
						}
						sikayetfile << endl;
						 
						sikayetfile.close();
					}

					///-------------***** sifre deðiþimi yapýlan kýsým *****----------------------

					else if (task == 4)  
					{
						string eskiSifre;
						string yeniSifre;
						string kul_adi;

						string ad, soyad, telNo, kullaniciAdi, ePosta,
							adresIlce, sifre, indirimKodu, dogumTarihi;

						cout << "Kullanici Adinizi girin" << endl;
						cout << "->"; cin >> kul_adi;
						cout << "Eski Sifrenizi girin" << endl;
						cout << "->"; cin >> eskiSifre;
						cout << "Yeni Sifrenizi girin" << endl;
						cout << "->"; cin >> yeniSifre;

						//(ad, soyad, telNo, kullaniciAdý, ePosta, adresIlce, k_sifre, dogumTarihi, indirimKodu);
						ifstream mevcutDosya;
						ofstream yeniDosya;
						mevcutDosya.open("Kullanicilar.txt", ios::in);
						yeniDosya.open("deneme.txt", ios::app);
						while (mevcutDosya >> ad)                                        
						{
							yeniDosya << left << setw(20) << ad;
							mevcutDosya >> soyad; yeniDosya << setw(20) << soyad;    //soyad okuyaz
							mevcutDosya >> telNo; yeniDosya << setw(20) << telNo;    //telno okuyaz
							mevcutDosya >> kullaniciAdi;						     //k_adý

							if (kullaniciAdi == kul_adi)
							{
								yeniDosya << setw(20) << kullaniciAdi;
								mevcutDosya >> ePosta;    yeniDosya << setw(20) << ePosta;		    //ePosta
								mevcutDosya >> adresIlce; yeniDosya << setw(20) << adresIlce;		//adresIlce
								mevcutDosya >> sifre;											    //sifre oku

								if (sifre == eskiSifre) { yeniDosya << setw(20) << yeniSifre; }
								else { yeniDosya << setw(20) << sifre; }

								mevcutDosya >> indirimKodu; yeniDosya << setw(20) << indirimKodu;
								mevcutDosya >> dogumTarihi; yeniDosya << setw(20) << dogumTarihi << endl;
							}
							else 
						    {
								yeniDosya << setw(20) << kullaniciAdi;                                      //k adý yaz
								mevcutDosya >> ePosta;		yeniDosya << setw(20) << ePosta;			    //eposta
								mevcutDosya >> adresIlce;   yeniDosya << setw(20) << adresIlce;			    //adresilce
								mevcutDosya >> sifre;       yeniDosya << setw(20) << sifre;			        //k_sifre
								mevcutDosya >> indirimKodu; yeniDosya << setw(20) << indirimKodu;			//dogumtarihi
								mevcutDosya >> dogumTarihi; yeniDosya << setw(20) << dogumTarihi << endl;	//indirimkodu
							}						
						}
						mevcutDosya.close(); //dosya kapama
						yeniDosya.close();   //dosya kapama
						string dosya = "Kullanicilar.txt";
						int a = remove(dosya.c_str());	
						int b = rename("deneme.txt", dosya.c_str());
					}

					//--------------***** geri dönus menüsü *****---------------------------------

					else if (task == 5)  
					{
						goto etiketProfilsec;
					}
				}
			}
			ifDosya5.close();

			if(eslesmeDurumu == false)   //musteri girisi basarisiz
			{
				cout << "Giris Basarisiz...! Tekrar Deneyin..." << endl;
				goto etiketMusteriGiris;
			}
		}		
	}
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>> Uye kaydi iþlemleri<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    //###################################################################################

	if (islem == 2)                            //uye kaydinin yapildigi blok
	{
		system("CLS");
		string ad;
		string soyad;
		string telNo;
		string kullaniciAdý;                   //uye degiskenler tanimlaniyor
		string ePosta;
		string adresIlce;
		string k_sifre;
		string indirimKodu;
		string dogumTarihi;

		cout << "Hosgeldiniz," << endl;
		cout <<"kayit islemleri icin bilgilerinizi eksiksiz giriniz" << endl;
		cout << "---------------------------------------------------\n";
		cout << "-> Adiniz " << endl;
		cout << "->"; cin>>ad;
		cout << "---------------------------------------------------\n";
		cout << "-> Soyadiniz." << endl;
		cout << "->"; cin >>soyad;
		cout << "---------------------------------------------------\n";
		cout << "-> Telefon Numaraniz." << endl;
		cout << "->"; cin >> telNo;
		cout << "---------------------------------------------------\n";
		cout << "-> Sistem Girisi icin Kullanici Adi Belirleyin." << endl;
		cout << "->"; cin >> kullaniciAdý;
		cout << "---------------------------------------------------\n";
		cout << "-> Adres Ilcenizin kodunu secin" << endl;
		adresIlce = adresIlceSec();
		cout << "---------------------------------------------------\n";
		cout << "-> Indirim Kodunuz Varsa Girin Yoksa 0 Girin." << endl;
		cout << "->"; cin >> indirimKodu;
		cout << "---------------------------------------------------\n";
		etiketPosta: //etiket 
		cout << "-> E Posta adresiniz." << endl;
		cout << "->"; cin >> ePosta;

		if (ePosta_Check(ePosta))
			cout << ">>>> Girilen E Posta Gecerli <<<<" << endl;
		else
		{
			cout << ">>> Gecersiz E Posta Adresi <<<" << endl;
			goto etiketPosta;
		}
		cout << "---------------------------------------------------\n";
		
		int gun = 0,  ay = 0,  yil = 0;
		etiketTarih: //etiket 
		cout << "-> Dogum Tarihini Sirasiyla Gun:Ay:Yil Seklinde Girin." << endl;
		cout << "-> Gun : "; cin >> gun ;  
		cout << "-> Ay : ";  cin >> ay ;
		cout << "-> Yil : "; cin >> yil;
	
		//if ((!isdigit(gun)) || (!isdigit(ay)) || (!isdigit(yil))) { goto etiketTarih; }
		//string sGun, sAy, sYil; //stoi(sGun)
		bool kontrol = tarihKontrol(gun, ay, yil);
		if (kontrol == true)
		{
			cout << "girilen tarih degerleri gecerli" << endl;
		}
		else
		{
			cout << "gecersiz tarih degerleri girdiniz" << endl;
			cout << "lutfen tekrar tarih degerlerini girin" << endl;
			goto etiketTarih;
		}
		dogumTarihi = to_string(gun) +":" + to_string(ay) + ":" + to_string(yil);
		
		cout << "---------------------------------------------------\n";
		cout << "-> Son Olarak Guclu Bir Sifre Belirleyin." << endl;
		cout << "-> Sifrenizi Belirlerken Asagidaki Kurallari Dikkate Alin." << endl << endl;;
		cout << "#######################################################\n";
		cout << "-> Sifreniz tum ascii karakterleri kullanabilirsin." << endl;
		cout << "-> Sifreniz En Az Bir Adet Buyuk Harf Icermelidir." << endl;
		cout << "-> Sifreniz En Az Bir Adet Kucuk Harf Icermelidir." << endl;
		cout << "-> Sifreniz En Az Bir Adet Sayi Icermelidir." << endl;
		cout << "-> Sifrenizin Uzunlugu min 8, max 12 karakter olmalidir." << endl;
		cout << "#######################################################\n";

	    etiketSifre://etiket 
		string str;
		char ch;
		bool sonuc;
		cout << "-> ";
		while ((ch = _getch()) != 13)  //enter e tiklayana kadar
		{
			//ascii---del :127 , esc : 27 , spcae:32 ,tab: 9
			if (ch != 127 && ch != 27 && ch != 9 && ch != 32)
			{
				if (ch == 8)
				{
					if (str.length() != 0)
					{
						system("CLS");
						str.pop_back();
						cout << "-> ";
						for (int i = 0; i < str.length(); i++)
						{
							cout.put('*');
						}
					}
				}
				else
				{
					cout.put('*');
					str.push_back(ch); //sifreye ekleme kýsmý
				}
				if (str.length() >= 12)    //maximum uzunluk
				{
					break;
				}
			} 
		}
		
		cout << "\n---------------------------------------------------\n";
		sonuc = sifreKontrol(str);
		cout << "---------------------------------------------------\n";
		if (sonuc == false){goto etiketSifre;}
		else {k_sifre = str;}
		
		Kullanici kul(ad, soyad, telNo, kullaniciAdý, ePosta, adresIlce, k_sifre, dogumTarihi, indirimKodu);

		cout << "Kaydiniz Isleme Aliniyor....!!!" << endl;

		ofstream ofDosya7;       //dosya nesnesi olusturuluyor
		ofDosya7.open("Kullanicilar.txt", ios::app); //dosya acma

		ofDosya7 << left
						<< setw(20) << kul.getAd()
						<< setw(20) << kul.getSoyad()
						<< setw(20) << kul.getTelefonNo()
						<< setw(20) << kul.getKullaniciAdý()
						<< setw(20) << kul.getEPosta()
						<< setw(20) << kul.getAdresIlce()
						<< setw(20) << kul.getSifre()
			            << setw(20) << kul.getDogumTarihi()
						<< setw(20) << kul.getIndirimKodu()<< endl;

		ofDosya7.close(); //dosya kapama
	}
}

bool ePosta_Check(std::string ePosta) // eposta degerini regex e göre kontrol eder.
{
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match(ePosta, pattern);
}
bool tarihKontrol(int gun, int ay, int yil)			// gun ay yýl degerini kontrol eder.
{
	int i = 0;
	int const aySayisi = 12;
	const array<int, aySayisi + 1> aydakiMaxGun =
	{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };   	

	if(yil < 2023 && yil > 1923)
	{
		if ((ay > 0) && ay <= aySayisi)
		{
			i++;
			if (gun > 0 && gun <= aydakiMaxGun[ay])      // gun degeri 1-31 arasinda olmali
			{
				i++;
			}
		}
		if (ay == 2 && gun == 29 && (yil % 400 == 0 ||
			(yil % 4 == 0 && yil % 100 != 0)))			 // 29 subat ozel durumu kontrol ediliyor.
		{
			i++;
		}
	}
	if (i >= 2) {return true;}
	else{return false;}
}

bool sifreKontrol(string sifre)               //girilen sifrenin güclü olma durumunu kontrol eder.
{
	char temp;
	bool hasLow, hasUpp, hasdigit, hasSpace;
	hasLow = hasUpp = hasdigit = hasSpace = false;

	for (size_t i = 0; i < sifre.length(); ++i) {
		temp = sifre[i];
		if (isupper(temp))      hasUpp = true;
		else if (islower(temp)) hasLow = true;
		else if (isdigit(temp)) hasdigit = true;
		else if (isspace(temp)) hasSpace = true;
	}
	if ((hasUpp) && (hasLow) && (hasdigit) && (!hasSpace) && (sifre.length() >= 8))
	{
		cout << "Tebrikler..! Gecerli ve Guclu bir Sifre Belirlediniz." << endl;
		return true;
	}
	else
	{
		cout << "Sifreniz Gecersiz. Lutfen daha guclu bir sifre olusturun" << endl;	
		if (hasUpp == false)   { cout << "Sifrenizde Buyuk Harf Eksik" << endl;}
		if (hasLow == false)   { cout << "Sifrenizde Kucuk Harf Eksik" << endl;}
		if (hasdigit == false) { cout << "Sifrenizde Rakam  Eksik" << endl;}
		if (!hasSpace == false){ cout << "Sifrenizde Bosluk Olmamali" << endl;}
		if (sifre.length() < 8){ cout << "Sifrenizde En Az 8 Karakter Olmali" << endl;}
		return false;
	}
}
string adresIlceSec()
{
	etiketAdresIlce:
	int adresNo;
	string ilce;
	cout << "#####################\n";
	cout << "-> [1] Ortahisar" << endl;
	cout << "-> [2] Akcaabat " << endl;
	cout << "-> [3] Vakfikebir" << endl;
	cout << "-> [4] Besikduzu" << endl;
	cout << "-> [5] Yomra" << endl;
	cout << "-> [6] Arsin" << endl;
	cout << "-> [7] Arakli" << endl;
	cout << "#####################\n";
	cout << "->"; cin >> adresNo;

	if (adresNo >= 1 && adresNo <= 7)
	{
		switch (adresNo)
		{
		case 1:
			ilce = "Ortahisar";
				break;
		case 2:
			ilce = "Akcaabat";
				break;
		case 3:
			ilce = "Vakfikebir";
				break;
		case 4:
			ilce = "Besikduzu";
				break;
		case 5:
			ilce = "Yomra";
				break;
		case 6:
			ilce = "Arsin";
				break;
		case 7:
			ilce = "Arakli";
				break;
		default:
			break;
		}

		return ilce;
	}
	else
	{
		cout << "Aralik disi deger girildi.Tekrar deneyin" << endl;
		goto etiketAdresIlce;
	}
}

void urunSecimi(Kullanici &kullanici, int m_iKategori, int urunNo, int bedenNo, int renkNo)
{
	string dosyaAdi;
	string bedenBilgiDosyasi;
	string renkBilgiDosyasi;

	if (m_iKategori == 1)
	{
		 dosyaAdi = "Pantolon.txt",bedenBilgiDosyasi = "BedenPantolon.txt"; renkBilgiDosyasi = "RenkPantolon.txt";
	}
	else if (m_iKategori == 2)
	{
		dosyaAdi = "Gomlek.txt",  bedenBilgiDosyasi = "BedenGomlek.txt"; renkBilgiDosyasi = "RenkGomlek.txt";
	}
	else if (m_iKategori == 3)
	{
		dosyaAdi = "Tisort.txt",  bedenBilgiDosyasi = "BedenTisort.txt"; renkBilgiDosyasi = "RenkTisort.txt";
	}
	else if (m_iKategori == 4)
	{
		dosyaAdi = "Elbise.txt",  bedenBilgiDosyasi = "BedenElbise.txt"; renkBilgiDosyasi = "RenkElbise.txt";
	}
	else if (m_iKategori == 5)
	{
		dosyaAdi = "Ayakkabi.txt", bedenBilgiDosyasi = "BedenAyakkabi.txt"; renkBilgiDosyasi = "RenkAyakkabi.txt";
	}
	else if(m_iKategori == 6)
	{
		dosyaAdi = "Etek.txt",    bedenBilgiDosyasi = "BedenEtek.txt"; renkBilgiDosyasi = "RenkEtek.txt";
	}
    
	double m_fiyat = 0.0;
	string m_kiyafet_Adi;
	string m_beden;
	string m_renk;
	string m_sKategori;
	string strData;
//-----------------------------------------------------------------
	int deger = 0;
	ifstream ifDosya10;
	ifDosya10.open(dosyaAdi);
	while (ifDosya10 >> strData)  // verileri okur
	{
		if (deger == urunNo) //aranan satýr buysa
		{
			m_sKategori = strData;
			ifDosya10 >> strData; m_kiyafet_Adi = strData;
			ifDosya10 >> strData; m_fiyat = stod(strData);

			string araDeger;
			ifstream ifDosyaÝndirimKodlari;
			ifDosyaÝndirimKodlari.open("indirimKodlari.txt");
			while (ifDosyaÝndirimKodlari >> araDeger) //indirim kodunun kontrol edildigi kisim
			{
				if (kullanici.getIndirimKodu() == araDeger)
				{
					m_fiyat = m_fiyat - (m_fiyat * 50 / 100);
				}
			}
			ifDosyaÝndirimKodlari.close();
			break;
		}
		else
		{	
			ifDosya10 >> strData;
			ifDosya10 >> strData;
			deger++;
		}
	}
	ifDosya10.close();
//----------------------------------------------------------------
	int deger2 = 0;
	ifstream ifDosya11;
	ifDosya11.open(bedenBilgiDosyasi);
	while (ifDosya11 >> strData)  // verileri okur
	{
		if (deger2 == bedenNo) //aranan satýr buysa
		{
			ifDosya11 >> strData; m_beden = strData; //ilgili satýrdaki bedeni alýyoruz sadece
			break;
		}
		else
		{
			ifDosya11 >> strData;
			deger2++;
		}
	}
	ifDosya11.close();
//-----------------------------------------------------------
	int deger3 = 0;
	ifstream ifDosya12;
	ifDosya12.open(renkBilgiDosyasi);
	while (ifDosya12 >> strData)  // verileri okur
	{
		if (deger3 == renkNo) //aranan satýr buysa
		{
			ifDosya12 >> strData; m_renk = strData; //ilgili satýrdaki rengi alýyoruz sadece
			break;
		}
		else
		{
			ifDosya12 >> strData;
			deger3++;
		}
	}
	ifDosya12.close();

	Kiyafet kiyafet(m_sKategori, m_kiyafet_Adi, m_fiyat, m_beden, m_renk);

	/*time_t tarih_saat = time(NULL);
	struct tm tarih_saat_bilgisi;
	localtime_s(&tarih_saat_bilgisi, &tarih_saat);
	cout<< setfill('0') << setw(2) << tarih_saat_bilgisi.tm_hour << ":" << setw(2) << tarih_saat_bilgisi.tm_min << ":"
		<< setw(2) << tarih_saat_bilgisi.tm_sec << "|" << setw(2) << tarih_saat_bilgisi.tm_mday << "-"
		<< setw(2) << (tarih_saat_bilgisi.tm_mon + 1) << ":" << setw(4) << (tarih_saat_bilgisi.tm_year + 1900) << endl;*/

	Zaman zaman;
	zaman.sistemSaatiniAl();
	ofstream ofDosya13;       //dosya nesnesi olusturuluyor
	ofDosya13.open("Faturalar.txt", ios::app); //dosya acma
	ofDosya13 << left
		<< setw(20) << kullanici.getAd()
		<< setw(20) << kullanici.getSoyad()
		<< setw(20) << kiyafet.getKategori()
		<< setw(20) << kiyafet.getKiyafetAdi()
		<< setw(20) << kiyafet.getFiyat()
		<< setw(20) << kiyafet.getBeden()
		<< setw(20) << kiyafet.getRenk()
	    << zaman << "|" << (zaman.getGuncelTarih())<< endl;
	ofDosya13.close(); //dosya kapama
}
