#include "pch.h"
#include <iostream>
#include<string>
#include<windows.h>
using namespace std;
#include "animaatio.h"
// toteuta kyseinen funktio
void toivota_pelaaja_sisään() {	cout << "Tervetuloa pelaamaan hirsipuuta" << endl;}
void haluaako_käyttäjä_pelata() {
	char valinta;
	cout << "Uskallatko aloittaa pelin." << endl
		<< "Vielä voit perääntyä.(k/e) Sisältää K18 COREa" << endl;
	cin >> valinta;
	if (valinta != 'k') { exit(0); }
	cout << "Hyvä valinta!! Aloitetaan" << endl
		<< "Arvaa seuraava piilossa oleva kirjain sanasta:" << endl;
}
// Tilanne on se, että käyttäjä arvannut u:n, jolloin tulostuksen
// pitäisi näyttää -> _ u u _ _
string sana = "muuli";
					//     0      1       2       3       4
char  sana_kirjain[5] = { 'm'    ,'u'    ,'u'    ,'l'    ,'i'    };
bool sana_tiedossa[5] = {  false , false  ,false   ,false  ,false };
char kirjain;
int MAX_arvauksia = 5 + 2;
int arvauksia = 1;

void näytä_arvaukset() {
	cout << "Arvaukset :" << arvauksia << " / " << MAX_arvauksia << " ";
}

void lopetetaanko() {
	// ALKUOSA TARKISTAA VOITTIKO PELAAJA
	int laskuri = 0;
//	cout << "sana_tiedossa: ";
	for (int i = 0; i < 5; i++) {
		if (sana_tiedossa[i] == true) {
			laskuri++;
		}
//		cout << sana_tiedossa[i] << " ";
	}
	if (laskuri == 5) {
		cout << "Peli loppui." << endl;
		exit(0);
		// niin sitten tehdään jotain
	}
//	cout << " Laskuri on " << laskuri << endl;
	// LOPPUOSA TARKISTAA VOITTIKO KONE
	if (arvauksia == MAX_arvauksia) {
			cout << hangman10;
			exit(0);


	}
}

void tarkista_onko_kirjain_taulukossa_ja_muuta_taulukkoa() {
	for (int i = 0; i < 5; i++) {
		if (kirjain == sana_kirjain[i]) { 
			sana_tiedossa[i] = true; 
		}
	}
	// Lopputilanne -> sana_tiedossa -taulukko on muuttunut
	// jotkuts falset ovat ehkä muuttuneet true:iksi
}
void korotetaanko_arvauksia() {
	bool löytyikö_kirjain = false;
	for (int i = 0; i < 5; i++) {
		if (kirjain == sana_kirjain[i]) {
			löytyikö_kirjain = true;  // KIRJAIN LÖYTYI!!!
		}
	}
	if (löytyikö_kirjain == false ) {
		arvauksia++;
	}
}
void näytä_hirsipuusana() {
	for (int i = 0; i < 5; i++) {
		if ( sana_tiedossa[i] ) { 
			cout << sana_kirjain[i] << " "; // tulostetaan kirjain
		}
		else {
			cout << "_ "; // tulostetaan tyhjämerkki
		}
	}
} // näytä_hirsipuusana -funktio loppuu

void kysy_kirjain() {
	cout << "Syötä kirjain:";
	cin >> kirjain;
}

int main()
{
	setlocale(LC_ALL, "fi-FI");
	system("CLS"); 
	cout << hangman1;
	Sleep(1000);
	system("CLS");
	cout << hangman2;
	Sleep(1000);
	system("CLS");
	cout << hangman3;
	Sleep(1000);
	system("CLS");
	cout << hangman4;
	Sleep(1000);
	system("CLS");
	cout << hangman5;
	Sleep(1000);
	system("CLS");
	cout << hangman6;
	Sleep(1000);
	system("CLS");
	cout << hangman7;
	Sleep(1000);
	system("CLS");
	cout << hangman8;
	Sleep(1000);
	system("CLS");
	cout << hangman9;
	Sleep(1000);
	system("CLS");
	cout << hangman10;
	exit(0);

	cout << boolalpha;
	// Pistä seuraava koodi kysymään järkevästi, 5 kertaa
	toivota_pelaaja_sisään();
	haluaako_käyttäjä_pelata();
	while (true) {
		näytä_arvaukset();
		näytä_hirsipuusana();
		kysy_kirjain();
		tarkista_onko_kirjain_taulukossa_ja_muuta_taulukkoa();
		korotetaanko_arvauksia();
	
		// HAASTE: Mieti, missä tarkistetaan onko arvattu
		// jo liikaa ja ukko joutuu hirteen
		lopetetaanko();
	}
}
// 1. Toivotetaan tulija tervetulleeksi DONE
// 2.a Haluatko pelata?
// 2.b Käyttäjältä otetaan syöte ( sana tai yksittäinen kirjain )
// 3. tarkistaa onko syöte sanassa
// 4. Tulostaa kuinka monta arvauskertaa jäljellä 
// 5. Näyttää mitkä kirjaimet arvattu oikein
// 6. tarkistaa onko sanatullut arvatuksi
//2. mitä sanoja (int,while,char,cout) tullaan tarvitsemaan ja mihin
