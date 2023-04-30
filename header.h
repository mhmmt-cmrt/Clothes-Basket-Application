//  this project was created by muhammet

#include<iostream>
#include<string>
#include<iomanip>
class Kisi
{
public:

	Kisi();
	Kisi(const std::string, const std::string, const std::string);  // constructure-destructure tan�mlar�
	~Kisi();

	void setAd(const std::string Ad) ;                              // isim setter getter tan�mlamalar�
	std::string getAd() const;

	void setSoyad(const std::string Soyad) ;                        // soyisim setter getter tan�mlamalar�
	std::string getSoyad() const;

	void setTelefonNo(const std::string) ;                          // telefon setter getter tan�mlamalar�
	std::string getTelefonNo() const;

private:
	std::string ad;
	std::string soyad;                                              // uye degisken tanimlari
	std::string telNo;
};
//-----------------------------------Kisi sinifi sonu----------------------------
class Kullanici : public Kisi
{
public:

	Kullanici();
	Kullanici(const std::string ad, const std::string Soyad, const std::string telNo, const std::string _KullaniciAd�,
			  const std::string ePosta, const std::string adresIlce,const std::string sifre, 
		      const std::string dogumTarihi,  const std::string indirimKodu = "####");
	~Kullanici();

	void setKullaniciAd�(const std::string);         // Kullanici Ad� setter getter tan�mlamalar�
	std::string getKullaniciAd�() const;

	void setEPosta(const std::string);               // E Posta setter getter tan�mlamalar�
	std::string getEPosta() const ;

	void setAdresIlce(const std::string);            // Adres Ilce setter getter tan�mlamalar�
	std::string getAdresIlce() const ;

	void setSifre(const std::string);                // Sifre setter getter tan�mlamalar�
	std::string getSifre() const;

	void setIndirimKodu(const std::string);          // Indirim Kodu setter getter tan�mlamalar�
	std::string getIndirimKodu() const;

	void setDogumTarihi(const std::string);          // Dogum Tarihi setter getter tan�mlamalar�
	std::string getDogumTarihi() const;

private:

	std::string kullaniciAd�;                        //uye degiskenler tanimlaniyor
	std::string ePosta;
	std::string adres�lce;
	std::string k_sifre;
	std::string indirimKodu;
	std::string dogumTarihi;
};
//-----------------------------kullanici s�n�f� sonu----------------------
class Yonetici : Kisi					              //y�netici sinifi kisi sinifindan miras al�r
{
public:
										              //constructure-destructure tan�mlar�
	Yonetici();
	Yonetici(const std::string ad, const std::string Soyad, 
		     const std::string telNo, const std::string y_Sifre);

	void setSifre(const std::string y_Sifre);         // setter-getter tan�mlar�
	std::string getSifre() const;

private:
	std::string y_Sifre;                              //uye degiskenler tanimlaniyor
};
//-----------------------------Y�netici s�n�f� sonu----------------------
class Zaman
{
	friend std::ostream& operator << (std::ostream& output, const Zaman& z);
	friend std::istream& operator >> (std::istream& input, Zaman& z);

public:

	Zaman();
	Zaman(int, int);					 // parametreli kurucu

	void dakikaEkle(int _dakika);	     //saate dakika ekler->normal fonksiyon ile
	Zaman operator + (int _dakika);	   	 //Saate Dakika Ekler->operator as�r� yukleme ile
	int operator - (Zaman &);			 //iki saat aras� ka� dak kald���n� dakika cinsinden bulur.
	bool operator < (Zaman&);			 //iki saat i�in hangisinin ilerde oldu�unu dakikaya g�re kar��la�t�r�r.
	void operator = (std::string);		 //bir saati di�erine atar

	void setSaat(int _saat);			 //saati ayarlar
	int getSaat() const;				 //saai dondurur

	void setDakika(int _dakika);		 //dakikayi ayarlar
	int getDakika() const;				 //dakikayi dondurur

	void sistemSaatiniAl();
	std::string getGuncelTarih();

private:
	int saat;							 //uye degiskenler tanimlaniyor
	int dakika;
};
//-----------------------------Zaman s�n�f� sonu----------------------
class Kurye : Kisi								//kurye sinifi kisi sinifindan miras al�r
{
public:

	Kurye();									//kurucu tanmlar�
	Kurye(std::string, std::string, std::string, Zaman& ,int);

	void setSiparisNumaralari(int);			    //setter getter ta�mlar�
	int  getSiparisNumaralari() const;
	
	void setDagitimBitisler(Zaman &);           //siparis_Baslangic setter getter tan�mlar�
	Zaman getDagitimBitisler() const;

private:
	int siparisNo;					            //uye degiskenler tanimlaniyor
	Zaman dagitim_Biti�ler;
};
//-----------------------------Kurye s�n�f� sonu------------------------
class Kiyafet
{
public:
											 //kurucu tanimlari
	Kiyafet();
	Kiyafet(std::string kategori, std::string kiyafet_Adi, double fiyat, std::string beden, std::string renk);                              

	void setKategori(std::string);           //kategori setter getter tan�m�
	std::string getKategori() const;

	void setKiyafetAdi(std::string);		 //KiyafetAdi setter getter tan�m�
	std::string getKiyafetAdi()const;

	void setFiyat(double);					 //Fiyat setter getter tan�m�
	double getFiyat()const;

	void setBeden(std::string);              //Beden setter getter tan�m�
	std::string getBeden()const;

	void setRenk(std::string);               //Renk setter getter tan�m�
	std::string getRenk()const;

private:							         //uye degiskenler tanimlaniyor
	std::string kategori;
	std::string kiyafet_Adi;
	double fiyat;
	std::string beden;
	std::string renk;
};
//-----------------------------Kiyafet s�n�f� sonu----------------------
class Siparis : public Kiyafet					// siparis sininfi kiyafet sinifindan miras alir
{
public:

	Siparis();							        // kurucu tanimlamalari
	Siparis(int , double, Zaman &, Zaman &);            

	void setSiparisNo(int);				        //SiparisNo setter getter tan�mlar�
	int getSiparisNo() const;

	void setSiparisFiyat(double);               //siparis_Fiyat setter getter tan�mlar�
	double getSiparisFiyat() const;

	void setSiparisBaslangic(Zaman &);          //siparis_Baslangic setter getter tan�mlar�
	Zaman getSiparisBaslangic() const;

	void setSiparisUlasim(Zaman &);             //siparis_Ulasim setter getter tan�mlar�
	Zaman getSiparisUlasim() const;

private:
	Zaman siparis_Baslangic;
	Zaman siparis_Ulasim;//�ye degiskenler tanimlaniyor
	int siparis_No;
	double siparis_Fiyat;
};
//-----------------------------Siparis s�n�f� sonu----------------------
void islemler(int);
bool ePosta_Check(std::string ePosta);
bool tarihKontrol(int gun, int ay, int yil);
bool sifreKontrol(std::string sifre);
std::string adresIlceSec();
void urunSecimi(Kullanici&, int,int, int, int);
