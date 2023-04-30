//  this project was created by muhammet

#include<iostream>
#include<string>
#include<iomanip>
class Kisi
{
public:

	Kisi();
	Kisi(const std::string, const std::string, const std::string);  // constructure-destructure tanýmlarý
	~Kisi();

	void setAd(const std::string Ad) ;                              // isim setter getter tanýmlamalarý
	std::string getAd() const;

	void setSoyad(const std::string Soyad) ;                        // soyisim setter getter tanýmlamalarý
	std::string getSoyad() const;

	void setTelefonNo(const std::string) ;                          // telefon setter getter tanýmlamalarý
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
	Kullanici(const std::string ad, const std::string Soyad, const std::string telNo, const std::string _KullaniciAdý,
			  const std::string ePosta, const std::string adresIlce,const std::string sifre, 
		      const std::string dogumTarihi,  const std::string indirimKodu = "####");
	~Kullanici();

	void setKullaniciAdý(const std::string);         // Kullanici Adý setter getter tanýmlamalarý
	std::string getKullaniciAdý() const;

	void setEPosta(const std::string);               // E Posta setter getter tanýmlamalarý
	std::string getEPosta() const ;

	void setAdresIlce(const std::string);            // Adres Ilce setter getter tanýmlamalarý
	std::string getAdresIlce() const ;

	void setSifre(const std::string);                // Sifre setter getter tanýmlamalarý
	std::string getSifre() const;

	void setIndirimKodu(const std::string);          // Indirim Kodu setter getter tanýmlamalarý
	std::string getIndirimKodu() const;

	void setDogumTarihi(const std::string);          // Dogum Tarihi setter getter tanýmlamalarý
	std::string getDogumTarihi() const;

private:

	std::string kullaniciAdý;                        //uye degiskenler tanimlaniyor
	std::string ePosta;
	std::string adresÝlce;
	std::string k_sifre;
	std::string indirimKodu;
	std::string dogumTarihi;
};
//-----------------------------kullanici sýnýfý sonu----------------------
class Yonetici : Kisi					              //yönetici sinifi kisi sinifindan miras alýr
{
public:
										              //constructure-destructure tanýmlarý
	Yonetici();
	Yonetici(const std::string ad, const std::string Soyad, 
		     const std::string telNo, const std::string y_Sifre);

	void setSifre(const std::string y_Sifre);         // setter-getter tanýmlarý
	std::string getSifre() const;

private:
	std::string y_Sifre;                              //uye degiskenler tanimlaniyor
};
//-----------------------------Yönetici sýnýfý sonu----------------------
class Zaman
{
	friend std::ostream& operator << (std::ostream& output, const Zaman& z);
	friend std::istream& operator >> (std::istream& input, Zaman& z);

public:

	Zaman();
	Zaman(int, int);					 // parametreli kurucu

	void dakikaEkle(int _dakika);	     //saate dakika ekler->normal fonksiyon ile
	Zaman operator + (int _dakika);	   	 //Saate Dakika Ekler->operator asýrý yukleme ile
	int operator - (Zaman &);			 //iki saat arasý kaç dak kaldýðýný dakika cinsinden bulur.
	bool operator < (Zaman&);			 //iki saat için hangisinin ilerde olduðunu dakikaya göre karþýlaþtýrýr.
	void operator = (std::string);		 //bir saati diðerine atar

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
//-----------------------------Zaman sýnýfý sonu----------------------
class Kurye : Kisi								//kurye sinifi kisi sinifindan miras alýr
{
public:

	Kurye();									//kurucu tanmlarý
	Kurye(std::string, std::string, std::string, Zaman& ,int);

	void setSiparisNumaralari(int);			    //setter getter taýmlarý
	int  getSiparisNumaralari() const;
	
	void setDagitimBitisler(Zaman &);           //siparis_Baslangic setter getter tanýmlarý
	Zaman getDagitimBitisler() const;

private:
	int siparisNo;					            //uye degiskenler tanimlaniyor
	Zaman dagitim_Bitiþler;
};
//-----------------------------Kurye sýnýfý sonu------------------------
class Kiyafet
{
public:
											 //kurucu tanimlari
	Kiyafet();
	Kiyafet(std::string kategori, std::string kiyafet_Adi, double fiyat, std::string beden, std::string renk);                              

	void setKategori(std::string);           //kategori setter getter tanýmý
	std::string getKategori() const;

	void setKiyafetAdi(std::string);		 //KiyafetAdi setter getter tanýmý
	std::string getKiyafetAdi()const;

	void setFiyat(double);					 //Fiyat setter getter tanýmý
	double getFiyat()const;

	void setBeden(std::string);              //Beden setter getter tanýmý
	std::string getBeden()const;

	void setRenk(std::string);               //Renk setter getter tanýmý
	std::string getRenk()const;

private:							         //uye degiskenler tanimlaniyor
	std::string kategori;
	std::string kiyafet_Adi;
	double fiyat;
	std::string beden;
	std::string renk;
};
//-----------------------------Kiyafet sýnýfý sonu----------------------
class Siparis : public Kiyafet					// siparis sininfi kiyafet sinifindan miras alir
{
public:

	Siparis();							        // kurucu tanimlamalari
	Siparis(int , double, Zaman &, Zaman &);            

	void setSiparisNo(int);				        //SiparisNo setter getter tanýmlarý
	int getSiparisNo() const;

	void setSiparisFiyat(double);               //siparis_Fiyat setter getter tanýmlarý
	double getSiparisFiyat() const;

	void setSiparisBaslangic(Zaman &);          //siparis_Baslangic setter getter tanýmlarý
	Zaman getSiparisBaslangic() const;

	void setSiparisUlasim(Zaman &);             //siparis_Ulasim setter getter tanýmlarý
	Zaman getSiparisUlasim() const;

private:
	Zaman siparis_Baslangic;
	Zaman siparis_Ulasim;//üye degiskenler tanimlaniyor
	int siparis_No;
	double siparis_Fiyat;
};
//-----------------------------Siparis sýnýfý sonu----------------------
void islemler(int);
bool ePosta_Check(std::string ePosta);
bool tarihKontrol(int gun, int ay, int yil);
bool sifreKontrol(std::string sifre);
std::string adresIlceSec();
void urunSecimi(Kullanici&, int,int, int, int);
