
#include<iostream>
#include<time.h>
using namespace std;
int main()
{
	char Harf[5][10];
	srand(time(0));  //rand fonksiyonu zamana bagl� olarak surekl� deg�secek
	char rastgele;
	int kontrol = 0; //bunu kullanarak rasgele gelen say�n�n dizide daha �nce olup olmad�gna bak�cam
		cout << "Tekrarsiz Ve Rasgele Dizi" << endl;
	for (int i = 0; i < 5; i++) // i� i�e 4 tane for kullanarak diziye farkli harfler atadim
	{
		for (int j = 0; j < 10; j++)
		{
			kontrol = 0;
			if (j % 2 == 0)  //sutun ciftse buyuk harf icin
				rastgele = 'A' + rand() % 26;
			else             //diger durumlarda sutun tek orayada kucuk harfleri
				rastgele = 'a' + rand() % 26;
			for (int x = 0; x < 5; x++)  //rastgele degiskeninin icindeki harf dizinin icinde var m� onu kontrol edicez
			{
				for (int y = 0; y < 10; y++)
				{
					if (Harf[x][y] == rastgele) //rasgele deg�sken�n�n icindeki harf eger matriste  varsa kontrol deg�sken�n�n degeri 1 artacak ve 0 dan farkl� olacak, yoksa 0 olarak kalacak
						kontrol++;
				}
			}
			if (kontrol == 0)    //eger 0 olarak kald�ysa bu deger matrisin icinde yoktur demektir ozaman bu harfi matrise atayip bastirabiliriz.
			{
				Harf[i][j] = rastgele;
				cout << Harf[i][j] << "\t";
			}
			else // kontrol 0dan farkliysa o harf onceden matrisin icinde vardir ozaman o degeri atamicaz ve j'yi 1 azaltip j yi donduren fonksiyona geri donup o j degeri icin tekrar bir rastgele harf aticaz
				j--;
		}
		cout << endl << endl;

	}
	char bos;
	for (int i = 0; i < 5; i++) //Buyuk harfleri matrisin en ust k�sm�nda olacak sekilde duzenlemek icin 4 tane ic ice for kullandim.
	{
		for (int j = 0; j < 10; j++)
		{
			for (int x = 0; x < 5; x++)
			{
				for (int y = 0; y < 10; y++)
				{
					if (Harf[i][j] < Harf[x][y]) //ascii kodda buyuk harflerin sayisal degeri daha buyuk oldugu icin sonradan gelen harfin ascii deger daha buyukse yerlerini degistiricez
					{
						bos = Harf[i][j];
						Harf[i][j] = Harf[x][y];
						Harf[x][y] = bos;
					}
				}
			}
		}
	}
	cout << "Siralanmis Dizi" << endl;
	for (int i = 0; i < 5; i++) //yukardaki ic ice 4 for dongusuyle siraladiktan sonra bu matrisi ekrana 2 tane ic ice for ile yazdiriyorum. ilk for satiri kontrol edecek.
	{
		for (int j = 0; j < 10; j++) // icteki for ise sutunlari kontrol edecek.
		{
			cout << Harf[i][j] << "\t";
		}
		cout << endl << endl;
	}
	system("PAUSE");
	return 0;
}