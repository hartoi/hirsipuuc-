#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
// toteuta kyseinen funktio
void toivota_pelaaja_sisään() {	cout << "Tervetuloa pelaamaan hirsipuuta" << endl;}
void haluaako_käyttäjä_pelata() {
	char valinta;
	cout << "Uskallatko aloittaa pelin." << endl
		<< "Vielä voit perääntyä.(k/e)" << endl;
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
void tarkista_onko_kirjain_taulukossa_ja_muuta_taulukkoa() {
	for (int i = 0; i < 5; i++) {
		if (kirjain == sana_kirjain[i]) { sana_tiedossa[i] = true; }
	}
	// Lopputilanne -> sana_tiedossa -taulukko on muuttunut
	// jotkuts falset ovat ehkä muuttuneet true:iksi
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
	// Pistä seuraava koodi kysymään järkevästi, 5 kertaa
	toivota_pelaaja_sisään();
	haluaako_käyttäjä_pelata(); 
	näytä_hirsipuusana();
	kysy_kirjain();
	tarkista_onko_kirjain_taulukossa_ja_muuta_taulukkoa();
	näytä_hirsipuusana();
	kysy_kirjain();
	näytä_hirsipuusana();
	kysy_kirjain();
	näytä_hirsipuusana();
	kysy_kirjain();
	näytä_hirsipuusana();
	kysy_kirjain();

}
// 1. Toivotetaan tulija tervetulleeksi DONE
// 2.a Haluatko pelata?
// 2.b Käyttäjältä otetaan syöte ( sana tai yksittäinen kirjain )
// 3. tarkistaa onko syöte sanassa
// 4. Tulostaa kuinka monta arvauskertaa jäljellä 
// 5. Näyttää mitkä kirjaimet arvattu oikein
// 6. tarkistaa onko sanatullut arvatuksi
//2. mitä sanoja (int,while,char,cout) tullaan tarvitsemaan ja mihin
