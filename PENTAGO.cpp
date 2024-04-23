#include <iostream>
#include <cmath>

using namespace std;
struct gracz
{
	string imie;
	char zeton;
	int czas;
};
const int ROZMIAR_PLANSZY = 6, RUCHY_MAX = 36;
void imiona_graczy(gracz& gracz1, gracz& gracz2);
void menu(gracz& gracz1, gracz& gracz2);
void kolko_i_krzyzyk(gracz& gracz1, gracz& gracz2);
void pentago(gracz& gracz1, gracz& gracz2);
void wybierz_zeton(gracz& gracz1, gracz& gracz2);
void ruch(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void ruch_pentago(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void wyswietl(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void wyswietl_przeglad(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void plansza_wyswietl(char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void plansza_przepisz(char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void plansza_predefiniowana(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int& licznik);
int wygrana_warunek(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int& licznik);
void wygrana_wyswietl(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void wygrana_czas_wyswietl(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void remis_wyswietl(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void przeglad_partii(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void plansza_wyczysc(char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY]);
void imiona_wyswietl(gracz& gracz1, gracz& gracz2, int& licznik);
void imiona_wyswietl_przeglad(gracz& gracz1, gracz& gracz2, int& licznik);
void obsluga_programu();
void opcje(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void zmien_zeton(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void kolko_i_krzyzyk_undo(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void pentago_undo(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void obroc(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik);
void wczytaj_czas(gracz& gracz1, gracz& gracz2);


int main()
{
	gracz gracz1, gracz2;
	imiona_graczy(gracz1, gracz2);
	menu(gracz1, gracz2);
}


void menu(gracz& gracz1, gracz& gracz2)
{
	system("cls");
	char wybor;
	cout << "========MENU========" << endl << "1. Kolko i krzyzyk" << endl << "2. Pentago" << endl << "3. Obsluga programu" << endl << "4. Zmien imiona graczy" << endl << "5. Wyjscie" << endl << "Wybor: ";
	cin >> wybor;
	switch (wybor)
	{
	case '1':
	{
		kolko_i_krzyzyk(gracz1, gracz2);
		break;
	}

	case '2':
	{
		pentago(gracz1, gracz2);
		break;
	}
	case '3':
	{
		obsluga_programu();
		menu(gracz1, gracz2);
		break;
	case '4':
	{
		imiona_graczy(gracz1, gracz2);
		menu(gracz1, gracz2);
		break;
	case '5':
	{
		exit(0);
	}
	}
	default:
		menu(gracz1, gracz2);
	}
	}
}
void obsluga_programu()
{
	system("cls");
	cout << "q,w,a,s - wybor części planszy odpowiednio: lewej gornej, prawej gornej, lewej dolnej, prawej dolnej" << endl << "1..9 - wybor pola na czesci planszy jak na klawiaturze numerycznej tj. 1 to dolne lewe pole" << endl << "z,x - obrot odpowiednio: zgodnie z ruchem wskazowek zegara, odwrotnie do ruchu wskazowek" << endl << "p - pauza" << endl << "u - undo" << endl << "o - wczytanie predefiniowanej planszy" << endl << "m - wejscie do opcji" << endl << "h - wejscie do opisu programu" << endl << endl << "Nacisnij enter aby wyjsc" << endl;
	getchar();
	getchar();

}
void imiona_graczy(gracz& gracz1, gracz& gracz2)
{
	system("cls");
	cout << "======Wpisz swoje Imie======" << endl << "Gracz 1: ";
	cin >> gracz1.imie;
	cout << endl << "Gracz 2: ";
	cin >> gracz2.imie;
}
void kolko_i_krzyzyk(gracz& gracz1, gracz& gracz2)
{
	char plansza[RUCHY_MAX + 1][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY];
	wybierz_zeton(gracz1, gracz2);
	wczytaj_czas(gracz1, gracz2);
	plansza_wyczysc(plansza);
	int licznik = 0;
	for (;;)
	{
		wyswietl(gracz1, gracz2, plansza, licznik);
		ruch(gracz1, gracz2, plansza, licznik);
		plansza_przepisz(plansza, licznik);
		if (wygrana_warunek(gracz1, gracz2, plansza, licznik) == 1)
		{
			wyswietl(gracz1, gracz2, plansza, licznik);
			wygrana_wyswietl(gracz1, gracz2, plansza, licznik);
			break;
		}
		else if (wygrana_warunek(gracz1, gracz2, plansza, licznik) == 2)
		{
			licznik--;
			wyswietl(gracz1, gracz2, plansza, licznik);
			wygrana_czas_wyswietl(gracz1, gracz2, plansza, licznik);
			break;
		}
		else if (wygrana_warunek(gracz1, gracz2, plansza, licznik) == 0)
		{
			wyswietl(gracz1, gracz2, plansza, licznik);
			remis_wyswietl(gracz1, gracz2, plansza, licznik);
			break;
		}
		else
		{
			if (licznik < 35)
				licznik++;
		}

	}


}
void pentago(gracz& gracz1, gracz& gracz2)
{
	char plansza[RUCHY_MAX + 1][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY];
	wybierz_zeton(gracz1, gracz2);
	wczytaj_czas(gracz1, gracz2);
	plansza_wyczysc(plansza);
	int licznik = 0;
	for (;;)
	{
		wyswietl(gracz1, gracz2, plansza, licznik);
		ruch_pentago(gracz1, gracz2, plansza, licznik);
		wyswietl(gracz1, gracz2, plansza, licznik);
		obroc(gracz1, gracz2, plansza, licznik);
		plansza_przepisz(plansza, licznik);
		if (wygrana_warunek(gracz1, gracz2, plansza, licznik) == 1)
		{
			wyswietl(gracz1, gracz2, plansza, licznik);
			wygrana_wyswietl(gracz1, gracz2, plansza, licznik);
			break;
		}
		else if (wygrana_warunek(gracz1, gracz2, plansza, licznik) == 2)
		{
			licznik--;//aby pokazalo gracza ktory wygral
			wyswietl(gracz1, gracz2, plansza, licznik);
			wygrana_czas_wyswietl(gracz1, gracz2, plansza, licznik);
			break;
		}
		else if (wygrana_warunek(gracz1, gracz2, plansza, licznik) == 0)
		{
			wyswietl(gracz1, gracz2, plansza, licznik);
			remis_wyswietl(gracz1, gracz2, plansza, licznik);
			break;
		}
		else
		{
			if (licznik < 35)
				licznik++;
		}

	}
}
void wybierz_zeton(gracz& gracz1, gracz& gracz2)
{
	gracz1.zeton = 'X';
	gracz2.zeton = 'O';   //deklaracja, żeby nie wyswietlił się komunikat "Zetony musza byc rozne!"
	do
	{
		system("cls");
		if (gracz1.zeton == gracz2.zeton)
			cout << "Zetony musza byc rozne!" << endl << endl;
		cout << gracz1.imie << " wybierz zeton: ";
		cin >> gracz1.zeton;
		cout << endl << gracz2.imie << " wybierz zeton: ";
		cin >> gracz2.zeton;
	} while (gracz1.zeton == gracz2.zeton);
}
void ruch(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{
	char czesc_planszy = ' ';
	char pole_char = ' ';
	int pole = 0, czas_temp = 0;
	if (licznik % 2 == 0)
	{
		czas_temp = time(NULL);
		do
		{
			if (pole < 0 || pole > 9 || (czesc_planszy == 'q' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3] != ' ') || (czesc_planszy == 'w' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3 + 3] != ' ') || (czesc_planszy == 'a' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3] != ' ') || (czesc_planszy == 's' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3 + 3] != ' '))
			{
				wyswietl(gracz1, gracz2, plansza, licznik);
				cout << "Bledne pole!!!";
			}

			do
			{
				if (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's' || czesc_planszy == 'o')
				{
					wyswietl(gracz1, gracz2, plansza, licznik);

				}

				if (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's' && czesc_planszy != 'p' && czesc_planszy != 'm' && czesc_planszy != 'h' && czesc_planszy != ' ' || (czesc_planszy == 'o' && licznik != 0))
				{
					cout << "Bledna czesc planszy!!!";
				}

				cout << endl << "Ruch gracza: " << gracz1.imie << endl << endl << "                       q w" << endl << "Wybierz czesc planszy  a s" << endl;
				cin >> czesc_planszy;

				if (czesc_planszy == 'o' && licznik == 0)
				{
					plansza_predefiniowana(gracz1, gracz2, plansza, licznik);
					plansza_przepisz(plansza, licznik);
				}
				else if (czesc_planszy == 'm')
				{
					opcje(gracz1, gracz2, plansza, licznik);
				}
				else if (czesc_planszy == 'h')
				{
					obsluga_programu();
				}
				else if (czesc_planszy == 'u' && licznik > 1)
				{
					kolko_i_krzyzyk_undo(gracz1, gracz2, plansza, licznik);
				}
				else if (czesc_planszy == 'p')
				{
					int czas_temp1;
					czas_temp1 = time(NULL);
					system("cls");
					cout << "PAUZA, nacisnij enter aby wznowic rozgrywke";
					getchar();
					getchar();
					gracz1.czas = gracz1.czas + (time(NULL) - czas_temp1); //po odpowiednich obliczeniach nie liczy czasu podczas pauzy
				}

			} while (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's');

			cout << endl << "             7 8 9" << endl << "             4 5 6" << endl << "Wybierz pole 1 2 3" << endl;
			cin >> pole_char;
			pole = pole_char - '0';
			if (pole == 0)
				pole = 10; //zabezpoeczenie prawidlowego wyswietlania informacji - bledne pole
		} while (pole < 1 || pole > 9 || (czesc_planszy == 'q' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3] != ' ') || (czesc_planszy == 'w' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3 + 3] != ' ') || (czesc_planszy == 'a' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3] != ' ') || (czesc_planszy == 's' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3 + 3] != ' '));

		switch (czesc_planszy) //odpowiednie funkcje dla kazdej cwiartki
		{
		case 'q':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3] = gracz1.zeton;
			break;
		}
		case 'w':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3 + 3] = gracz1.zeton;
			break;
		}
		case 'a':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3] = gracz1.zeton;
			break;
		}
		case 's':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3 + 3] = gracz1.zeton;
			break;
		}
		}
		gracz1.czas = gracz1.czas - (time(NULL) - czas_temp);
	}
	else
	{
		czas_temp = time(NULL);
		do
		{
			if (pole < 0 || pole > 9 || (czesc_planszy == 'q' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3] != ' ') || (czesc_planszy == 'w' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3 + 3] != ' ') || (czesc_planszy == 'a' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3] != ' ') || (czesc_planszy == 's' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3 + 3] != ' '))
			{
				wyswietl(gracz1, gracz2, plansza, licznik);
				cout << "Bledne pole!!!";
			}

			do
			{
				if (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's')
				{
					wyswietl(gracz1, gracz2, plansza, licznik);
				}
				if (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's' && czesc_planszy != 'p' && czesc_planszy != 'm' && czesc_planszy != 'h' && czesc_planszy != ' ')
				{
					cout << "Bledna czesc planszy!!!";
				}


				cout << endl << "Ruch gracza: " << gracz2.imie << endl << endl << "                       q w" << endl << "Wybierz czesc planszy  a s" << endl;
				cin >> czesc_planszy;

				if (czesc_planszy == 'm')
				{
					opcje(gracz1, gracz2, plansza, licznik);
				}
				else if (czesc_planszy == 'h')
				{
					obsluga_programu();
				}
				else if (czesc_planszy == 'u' && licznik > 1)
				{
					kolko_i_krzyzyk_undo(gracz1, gracz2, plansza, licznik);
				}
				else if (czesc_planszy == 'p')
				{
					int czas_temp1;
					czas_temp1 = time(NULL);
					system("cls");
					cout << "PAUZA, nacisnij enter aby wznowic rozgrywke";
					getchar();
					getchar();
					gracz2.czas = gracz2.czas + (time(NULL) - czas_temp1); //po odpowiednich obliczeniach nie liczy czasu podczas pauzy
				}


			} while (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's');

			cout << endl << "             7 8 9" << endl << "             4 5 6" << endl << "Wybierz pole 1 2 3" << endl;
			cin >> pole_char;
			pole = pole_char - '0';
			if (pole == 0)
				pole = 10; //zabezpoeczenie prawidlowego wyswietlania informacji - bledne pole
		} while (pole < 1 || pole > 9 || (czesc_planszy == 'q' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3] != ' ') || (czesc_planszy == 'w' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3 + 3] != ' ') || (czesc_planszy == 'a' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3] != ' ') || (czesc_planszy == 's' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3 + 3] != ' '));

		switch (czesc_planszy)
		{
		case 'q':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3] = gracz2.zeton;
			break;
		}
		case 'w':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3 + 3] = gracz2.zeton;
			break;
		}
		case 'a':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3] = gracz2.zeton;
			break;
		}
		case 's':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3 + 3] = gracz2.zeton;
			break;
		}
		}
		gracz2.czas = gracz2.czas - (time(NULL) - czas_temp);
	}

}
void ruch_pentago(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{
	char czesc_planszy = ' ';
	char pole_char = ' ';
	int pole = 0, czas_temp = 0;
	if (licznik % 2 == 0)
	{
		czas_temp = time(NULL);
		do
		{
			if (pole < 0 || pole > 9 || (czesc_planszy == 'q' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3] != ' ') || (czesc_planszy == 'w' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3 + 3] != ' ') || (czesc_planszy == 'a' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3] != ' ') || (czesc_planszy == 's' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3 + 3] != ' '))
			{
				wyswietl(gracz1, gracz2, plansza, licznik);
				cout << "Bledne pole!!!";
			}

			do
			{
				if (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's' || czesc_planszy == 'o')
				{
					wyswietl(gracz1, gracz2, plansza, licznik);

				}

				if (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's' && czesc_planszy != 'p' && czesc_planszy != 'm' && czesc_planszy != 'h' && czesc_planszy != ' ' || (czesc_planszy == 'o' && licznik != 0))
				{
					cout << "Bledna czesc planszy!!!";
				}

				cout << endl << "Ruch gracza: " << gracz1.imie << endl << endl << "                       q w" << endl << "Wybierz czesc planszy  a s" << endl;
				cin >> czesc_planszy;

				if (czesc_planszy == 'o' && licznik == 0)
				{
					plansza_predefiniowana(gracz1, gracz2, plansza, licznik);
					plansza_przepisz(plansza, licznik);
				}
				else if (czesc_planszy == 'm')
				{
					opcje(gracz1, gracz2, plansza, licznik);
				}
				else if (czesc_planszy == 'h')
				{
					obsluga_programu();
				}
				else if (czesc_planszy == 'u' && licznik > 1)
				{
					pentago_undo(gracz1, gracz2, plansza, licznik);
				}
				else if (czesc_planszy == 'p')
				{
					int czas_temp1;
					czas_temp1 = time(NULL);
					system("cls");
					cout << "PAUZA, nacisnij enter aby wznowic rozgrywke";
					getchar();
					getchar();
					gracz1.czas = gracz1.czas + (time(NULL) - czas_temp1); //po odpowiednich obliczeniach nie liczy czasu podczas pauzy
				}


			} while (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's');

			cout << endl << "             7 8 9" << endl << "             4 5 6" << endl << "Wybierz pole 1 2 3" << endl;
			cin >> pole_char;
			pole = pole_char - '0';
			if (pole == 0)
				pole = 10; //zabezpoeczenie prawidlowego wyswietlania informacji - bledne pole
		} while (pole < 1 || pole > 9 || (czesc_planszy == 'q' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3] != ' ') || (czesc_planszy == 'w' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3 + 3] != ' ') || (czesc_planszy == 'a' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3] != ' ') || (czesc_planszy == 's' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3 + 3] != ' '));

		switch (czesc_planszy)
		{
		case 'q':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3] = gracz1.zeton;
			break;
		}
		case 'w':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3 + 3] = gracz1.zeton;
			break;
		}
		case 'a':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3] = gracz1.zeton;
			break;
		}
		case 's':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3 + 3] = gracz1.zeton;
			break;
		}
		}
		gracz1.czas = gracz1.czas - (time(NULL) - czas_temp);
	}
	else
	{
		czas_temp = time(NULL);
		do
		{
			if (pole < 0 || pole > 9 || (czesc_planszy == 'q' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3] != ' ') || (czesc_planszy == 'w' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3 + 3] != ' ') || (czesc_planszy == 'a' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3] != ' ') || (czesc_planszy == 's' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3 + 3] != ' '))
			{
				wyswietl(gracz1, gracz2, plansza, licznik);
				cout << "Bledne pole!!!";
			}

			do
			{
				if (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's')
				{
					wyswietl(gracz1, gracz2, plansza, licznik);
				}
				if (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's' && czesc_planszy != 'p' && czesc_planszy != 'm' && czesc_planszy != 'h' && czesc_planszy != ' ')
				{
					cout << "Bledna czesc planszy!!!";
				}


				cout << endl << "Ruch gracza: " << gracz2.imie << endl << endl << "                       q w" << endl << "Wybierz czesc planszy  a s" << endl;
				cin >> czesc_planszy;

				if (czesc_planszy == 'm')
				{
					opcje(gracz1, gracz2, plansza, licznik);
				}
				else if (czesc_planszy == 'h')
				{
					obsluga_programu();
				}
				else if (czesc_planszy == 'u' && licznik > 1)
				{
					pentago_undo(gracz1, gracz2, plansza, licznik);
				}
				else if (czesc_planszy == 'p')
				{
					int czas_temp1;
					czas_temp1 = time(NULL);
					system("cls");
					cout << "PAUZA, nacisnij enter aby wznowic rozgrywke";
					getchar();
					getchar();
					gracz2.czas = gracz2.czas + (time(NULL) - czas_temp1); //po odpowiednich obliczeniach nie liczy czasu podczas pauzy
				}


			} while (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's');

			cout << endl << "             7 8 9" << endl << "             4 5 6" << endl << "Wybierz pole 1 2 3" << endl;
			cin >> pole_char;
			pole = pole_char - '0';
			if (pole == 0)
				pole = 10; //zabezpoeczenie prawidlowego wyswietlania informacji - bledne pole
		} while (pole < 1 || pole > 9 || (czesc_planszy == 'q' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3] != ' ') || (czesc_planszy == 'w' && plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3 + 3] != ' ') || (czesc_planszy == 'a' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3] != ' ') || (czesc_planszy == 's' && plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3 + 3] != ' '));

		switch (czesc_planszy)
		{
		case 'q':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3] = gracz2.zeton;
			break;
		}
		case 'w':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2)][(pole - 1) % 3 + 3] = gracz2.zeton;
			break;
		}
		case 'a':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3] = gracz2.zeton;
			break;
		}
		case 's':
		{
			plansza[licznik][abs((pole - 1) / 3 - 2) + 3][(pole - 1) % 3 + 3] = gracz2.zeton;
			break;
		}
		}
		gracz2.czas = gracz2.czas - (time(NULL) - czas_temp);
	}

}
void wyswietl(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{
	system("cls");
	plansza_wyswietl(plansza, licznik);
	imiona_wyswietl(gracz1, gracz2, licznik);
}
void wyswietl_przeglad(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{
	system("cls");
	plansza_wyswietl(plansza, licznik);
	imiona_wyswietl_przeglad(gracz1, gracz2, licznik);
}
void plansza_wyswietl(char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{
	int temp = 0;
	for (int j = 0; j < 2; j++)
	{
		cout << "ÉÍÍÍËÍÍÍËÍÍÍ» ÉÍÍÍËÍÍÍËÍÍÍ»" << endl;
		for (int i = 0; i < ROZMIAR_PLANSZY / 2; i++)
		{
			cout << "ş " << plansza[licznik][i + temp][0] << " ş " << plansza[licznik][i + temp][1] << " ş " << plansza[licznik][i + temp][2] << " ş ş " << plansza[licznik][i + temp][3] << " ş " << plansza[licznik][i + temp][4] << " ş " << plansza[licznik][i + temp][5] << " ş" << endl;
			if (i == 2)
			{
				cout << "ČÍÍÍĘÍÍÍĘÍÍÍĽ ČÍÍÍĘÍÍÍĘÍÍÍĽ" << endl;
			}
			else
				cout << "ĚÍÍÍÎÍÍÍÎÍÍÍą ĚÍÍÍÎÍÍÍÎÍÍÍą" << endl;
		}
		temp = 3;
	}

}
void plansza_przepisz(char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{

	for (int i = 0; i < ROZMIAR_PLANSZY; i++)
	{
		for (int j = 0; j < ROZMIAR_PLANSZY; j++)
		{
			plansza[licznik + 1][i][j] = plansza[licznik][i][j];
		}
	}
}
void plansza_wyczysc(char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY])
{
	for (int k = 0; k < RUCHY_MAX; k++)
	{
		for (int i = 0; i < ROZMIAR_PLANSZY; i++)
		{
			for (int j = 0; j < ROZMIAR_PLANSZY; j++)
			{
				plansza[k][i][j] = ' ';
			}
		}
	}
}
void plansza_predefiniowana(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int& licznik)
{
	plansza[0][0][1] = gracz2.zeton;
	plansza[0][1][2] = gracz2.zeton;
	plansza[0][1][4] = gracz2.zeton;
	plansza[0][4][0] = gracz2.zeton;
	plansza[0][5][1] = gracz2.zeton;
	plansza[0][4][4] = gracz2.zeton;
	plansza[0][5][4] = gracz2.zeton;
	plansza[0][5][5] = gracz2.zeton;
	plansza[0][1][0] = gracz1.zeton;
	plansza[0][1][1] = gracz1.zeton;
	plansza[0][2][1] = gracz1.zeton;
	plansza[0][3][0] = gracz1.zeton;
	plansza[0][3][1] = gracz1.zeton;
	plansza[0][4][2] = gracz1.zeton;
	plansza[0][1][3] = gracz1.zeton;
	plansza[0][0][4] = gracz1.zeton;
}
void imiona_wyswietl(gracz& gracz1, gracz& gracz2, int& licznik)
{
	cout << gracz1.imie << "   zeton: " << gracz1.zeton << endl << gracz2.imie << "   zeton: " << gracz2.zeton << endl;
	if (licznik % 2 == 0)
		cout << "Pozostalo " << gracz1.czas << " sekund" << endl;
	else
		cout << "Pozostalo " << gracz2.czas << " sekund" << endl;
}
void imiona_wyswietl_przeglad(gracz& gracz1, gracz& gracz2, int& licznik)
{
	cout << gracz1.imie << "   zeton: " << gracz1.zeton << endl << gracz2.imie << "   zeton: " << gracz2.zeton << endl;
}
int wygrana_warunek(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int& licznik)
{
	if (gracz1.czas < 1 || gracz2.czas < 1)
	{
		licznik++;
		return 2;
	}

	for (int i = 0, j = 1; i < 2; i++)
	{

		if (plansza[licznik][j][i] != ' ' && plansza[licznik][j][i] == plansza[licznik][j + 1][i + 1] && plansza[licznik][j + 1][i + 1] == plansza[licznik][j + 2][i + 2] && plansza[licznik][j + 2][i + 2] == plansza[licznik][j + 3][i + 3] && plansza[licznik][j + 3][i + 3] == plansza[licznik][j + 4][i + 4])
			return 1;
		j--;
	}
	for (int i = 0, j = 0; i < 2; i++)
	{

		if (plansza[licznik][j][i] != ' ' && plansza[licznik][j][i] == plansza[licznik][j + 1][i + 1] && plansza[licznik][j + 1][i + 1] == plansza[licznik][j + 2][i + 2] && plansza[licznik][j + 2][i + 2] == plansza[licznik][j + 3][i + 3] && plansza[licznik][j + 3][i + 3] == plansza[licznik][j + 4][i + 4])
			return 1;
		j++;
	}
	for (int i = 0, j = 5; i < 2; i++)
	{

		if (plansza[licznik][j][i] != ' ' && plansza[licznik][j][i] == plansza[licznik][j - 1][i + 1] && plansza[licznik][j - 1][i + 1] == plansza[licznik][j - 2][i + 2] && plansza[licznik][j - 2][i + 2] == plansza[licznik][j - 3][i + 3] && plansza[licznik][j - 3][i + 3] == plansza[licznik][j - 4][i + 4])
			return 1;
		j--;
	}
	for (int i = 0, j = 4; i < 2; i++)
	{

		if (plansza[licznik][j][i] != ' ' && plansza[licznik][j][i] == plansza[licznik][j - 1][i + 1] && plansza[licznik][j - 1][i + 1] == plansza[licznik][j - 2][i + 2] && plansza[licznik][j - 2][i + 2] == plansza[licznik][j - 3][i + 3] && plansza[licznik][j - 3][i + 3] == plansza[licznik][j - 4][i + 4])
			return 1;
		j++;
	}
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < ROZMIAR_PLANSZY; i++)
		{

			if (plansza[licznik][j][i] != ' ' && plansza[licznik][j][i] == plansza[licznik][j + 1][i] && plansza[licznik][j + 1][i] == plansza[licznik][j + 2][i] && plansza[licznik][j + 2][i] == plansza[licznik][j + 3][i] && plansza[licznik][j + 3][i] == plansza[licznik][j + 4][i])
				return 1;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < ROZMIAR_PLANSZY; j++)
		{

			if (plansza[licznik][j][i] != ' ' && plansza[licznik][j][i] == plansza[licznik][j][i + 1] && plansza[licznik][j][i + 1] == plansza[licznik][j][i + 2] && plansza[licznik][j][i + 2] == plansza[licznik][j][i + 3] && plansza[licznik][j][i + 3] == plansza[licznik][j][i + 4])
				return 1;
		}
	}

	int licz = 0;
	for (int i = 0; i < ROZMIAR_PLANSZY; i++)
	{
		for (int j = 0; j < ROZMIAR_PLANSZY; j++)
		{
			if (plansza[licznik][j][i] != ' ')
				licz++;
		}
		if (licz == 36)
			return 0;
	}

}
void wygrana_wyswietl(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{
	int wybor = 1;
	cout << endl << "Koniec gry" << endl << "Nacisnij enter aby przejsc dalej" << endl;
	if (licznik % 2 == 0)
	{
		getchar();
		getchar();
		system("cls");
		cout << "Gratulacje, wygrywa " << gracz1.imie << endl;
	}
	else
	{
		getchar();
		getchar();
		system("cls");
		cout << "Gratulacje, wygrywa " << gracz2.imie << endl;
	}
	cout << endl << "1. Przeglad rozgrywki" << endl << "2. Powrot do menu" << endl;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
	{
		przeglad_partii(gracz1, gracz2, plansza, licznik);
		break;
	}
	case 2:
	{
		menu(gracz1, gracz2);
		break;
	}
	}
}
void wygrana_czas_wyswietl(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{
	int wybor = 1;
	cout << endl << "Koniec czasu" << endl << "Nacisnij enter aby przejsc dalej" << endl;
	if (licznik % 2 == 0)
	{
		getchar();
		getchar();
		system("cls");
		cout << "Gratulacje, wygrywa " << gracz1.imie << endl;
	}
	else
	{
		getchar();
		getchar();
		system("cls");
		cout << "Gratulacje, wygrywa " << gracz2.imie << endl;
	}
	cout << endl << "1. Przeglad rozgrywki" << endl << "2. Powrot do menu" << endl;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
	{
		przeglad_partii(gracz1, gracz2, plansza, licznik);
		break;
	}
	case 2:
	{
		menu(gracz1, gracz2);
		break;
	}
	}
}
void przeglad_partii(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{
	char wybor;

	for (int i = 0; i <= licznik; i++)
	{
		wyswietl_przeglad(gracz1, gracz2, plansza, i);
		if ((i + 1) % 2 == 0)
			cout << endl << "Ruch gracza : " << gracz1.imie << endl;
		else
			cout << endl << "Ruch gracza : " << gracz2.imie << endl;
		cout << "Nacisnij dowolny klawisz, a nastepnie enter, aby przejesc do przodu" << endl << "Nacisnij \'u\', a nastepnie enter aby przejesc do tylu" << endl;
		cin >> wybor;
		if (wybor == 'u' && i > 0)
			i = i - 2;
	}
	cout << "Koniec partii, nacisnij enter aby wrocic do menu" << endl;
	getchar();
	getchar();
	menu(gracz1, gracz2);
}
void opcje(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{
	int wybor;
	system("cls");
	cout << "======Opcje=======" << endl << "1. Powrot do gry" << endl << "2. Zmien zeton" << endl << "3. Zagraj od poczatku" << endl << "4. Menu glowne" << endl << "5. Wyjdz z gry" << endl;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
	{
		break;
	}
	case 2:
	{
		zmien_zeton(gracz1, gracz2, plansza, licznik);
		break;
	}
	case 3:
	{
		kolko_i_krzyzyk(gracz1, gracz2);
		break;
	}
	case 4:
	{
		menu(gracz1, gracz2);
		break;
	}
	case 5:
	{
		exit(0);
	}
	default:
	{
		opcje(gracz1, gracz2, plansza, licznik);
	}
	}
}
void zmien_zeton(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{
	char nowy_zeton = ' ';


	if (licznik % 2 == 0)
	{
		do
		{
			if (nowy_zeton == gracz2.zeton)
			{
				system("cls");
				cout << "======Zmiana zetonu======" << endl << "Podany zeton jest zetonem przeciwnika" << endl << "Podaj nowy zeton: ";
				cin >> nowy_zeton;
			}
			else
			{
				system("cls");
				cout << "======Zmiana zetonu======" << endl << "Podaj nowy zeton: ";
				cin >> nowy_zeton;
			}
		} while (nowy_zeton == gracz2.zeton);
		for (int k = 0; k < RUCHY_MAX; k++)
		{
			for (int i = 0; i < ROZMIAR_PLANSZY; i++)
			{
				for (int j = 0; j < ROZMIAR_PLANSZY; j++)
				{
					if (plansza[k][i][j] == gracz1.zeton)
						plansza[k][i][j] = nowy_zeton;
				}
			}
		}
		gracz1.zeton = nowy_zeton;
	}
	else
	{
		do
		{
			if (nowy_zeton == gracz2.zeton)
			{
				system("cls");
				cout << "======Zmiana zetonu======" << endl << "Podany zeton jest zetonem przeciwnika" << endl << "Podaj nowy zeton: ";
				cin >> nowy_zeton;
			}
			{
				system("cls");
				cout << "======Zmiana zetonu======" << endl << "Podaj nowy zeton: ";
				cin >> nowy_zeton;
			}

		} while (nowy_zeton == gracz1.zeton);
		for (int k = 0; k < RUCHY_MAX; k++)
		{
			for (int i = 0; i < ROZMIAR_PLANSZY; i++)
			{
				for (int j = 0; j < ROZMIAR_PLANSZY; j++)
				{
					if (plansza[k][i][j] == gracz2.zeton)
						plansza[k][i][j] = nowy_zeton;
				}
			}
		}
		gracz2.zeton = nowy_zeton;
	}
}
void remis_wyswietl(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{
	int wybor = 1;
	cout << endl << "Koniec gry" << endl << "Nacisnij enter aby przejsc dalej" << endl;

	getchar();
	getchar();
	system("cls");
	cout << "Remis, nikt nie zwycezyl, dobra rozgrywka" << endl;

	cout << endl << "1. Przeglad rozgrywki" << endl << "2. Powrot do menu" << endl;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
	{
		przeglad_partii(gracz1, gracz2, plansza, licznik);
		break;
	}
	case 2:
	{
		menu(gracz1, gracz2);
		break;
	}
	}
}
void kolko_i_krzyzyk_undo(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{
	licznik--;
	licznik--;
	plansza_przepisz(plansza, licznik);
	licznik++;
	for (;;)
	{
		wyswietl(gracz1, gracz2, plansza, licznik);
		ruch(gracz1, gracz2, plansza, licznik);
		plansza_przepisz(plansza, licznik);
		if (wygrana_warunek(gracz1, gracz2, plansza, licznik) == 1)
		{
			wyswietl(gracz1, gracz2, plansza, licznik);
			wygrana_wyswietl(gracz1, gracz2, plansza, licznik);
			break;
		}
		else if (wygrana_warunek(gracz1, gracz2, plansza, licznik) == 2)
		{
			wyswietl(gracz1, gracz2, plansza, licznik);
			wygrana_czas_wyswietl(gracz1, gracz2, plansza, licznik);
			break;
		}
		else if (wygrana_warunek(gracz1, gracz2, plansza, licznik) == 0)
		{
			wyswietl(gracz1, gracz2, plansza, licznik);
			remis_wyswietl(gracz1, gracz2, plansza, licznik);
			break;
		}
		else
		{
			if (licznik < 35)
				licznik++;
		}

	}
}
void pentago_undo(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{
	licznik--;
	licznik--;
	plansza_przepisz(plansza, licznik);
	licznik++;
	for (;;)
	{
		wyswietl(gracz1, gracz2, plansza, licznik);
		ruch_pentago(gracz1, gracz2, plansza, licznik);
		wyswietl(gracz1, gracz2, plansza, licznik);
		obroc(gracz1, gracz2, plansza, licznik);
		plansza_przepisz(plansza, licznik);
		if (wygrana_warunek(gracz1, gracz2, plansza, licznik) == 1)
		{
			wyswietl(gracz1, gracz2, plansza, licznik);
			wygrana_wyswietl(gracz1, gracz2, plansza, licznik);
			break;
		}
		else if (wygrana_warunek(gracz1, gracz2, plansza, licznik) == 2)
		{
			wyswietl(gracz1, gracz2, plansza, licznik);
			wygrana_czas_wyswietl(gracz1, gracz2, plansza, licznik);
			break;
		}
		else if (wygrana_warunek(gracz1, gracz2, plansza, licznik) == 0)
		{
			wyswietl(gracz1, gracz2, plansza, licznik);
			remis_wyswietl(gracz1, gracz2, plansza, licznik);
			break;
		}
		else
		{
			if (licznik < 35)
				licznik++;
		}

	}
}
void obroc(gracz& gracz1, gracz& gracz2, char plansza[RUCHY_MAX][ROZMIAR_PLANSZY][ROZMIAR_PLANSZY], int licznik)
{
	char czesc_planszy = ' ', obrot = ' ', temp[8];
	if (licznik % 2 == 0)
	{
		do
		{
			if (obrot != 'z' && obrot != 'x' && obrot != ' ')
			{
				wyswietl(gracz1, gracz2, plansza, licznik);
				cout << "Bledny kierunek obrotu!!!";
			}

			do
			{
				if (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's' && czesc_planszy != ' ')
				{
					wyswietl(gracz1, gracz2, plansza, licznik);
					cout << "Bledna czesc planszy!!!";

				}

				cout << endl << "Ruch gracza: " << gracz1.imie << endl << endl << "                       q w" << endl << "Wybierz czesc planszy  a s" << endl;
				cin >> czesc_planszy;

			} while (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's');


			cout << "Wybierz kierunek ruchu planszy (z, x): ";
			cin >> obrot;
		} while (obrot != 'z' && obrot != 'x');

		switch (czesc_planszy)
		{
		case 'q':
		{
			if (obrot == 'z')
			{
				temp[0] = plansza[licznik][0][0];
				temp[1] = plansza[licznik][0][1];
				temp[2] = plansza[licznik][0][2];
				temp[3] = plansza[licznik][1][2];
				temp[4] = plansza[licznik][2][2];
				temp[5] = plansza[licznik][2][1];
				temp[6] = plansza[licznik][2][0];
				temp[7] = plansza[licznik][1][0];
				plansza[licznik][0][2] = temp[0];
				plansza[licznik][1][2] = temp[1];
				plansza[licznik][2][2] = temp[2];
				plansza[licznik][2][1] = temp[3];
				plansza[licznik][2][0] = temp[4];
				plansza[licznik][1][0] = temp[5];
				plansza[licznik][0][0] = temp[6];
				plansza[licznik][0][1] = temp[7];
			}
			else
			{
				temp[0] = plansza[licznik][0][0];
				temp[1] = plansza[licznik][0][1];
				temp[2] = plansza[licznik][0][2];
				temp[3] = plansza[licznik][1][2];
				temp[4] = plansza[licznik][2][2];
				temp[5] = plansza[licznik][2][1];
				temp[6] = plansza[licznik][2][0];
				temp[7] = plansza[licznik][1][0];
				plansza[licznik][2][0] = temp[0];
				plansza[licznik][1][0] = temp[1];
				plansza[licznik][0][0] = temp[2];
				plansza[licznik][0][1] = temp[3];
				plansza[licznik][0][2] = temp[4];
				plansza[licznik][1][2] = temp[5];
				plansza[licznik][2][2] = temp[6];
				plansza[licznik][2][1] = temp[7];
			}
			break;
		}
		case 'w':
		{
			if (obrot == 'z')
			{
				temp[0] = plansza[licznik][0][3];
				temp[1] = plansza[licznik][0][4];
				temp[2] = plansza[licznik][0][5];
				temp[3] = plansza[licznik][1][5];
				temp[4] = plansza[licznik][2][5];
				temp[5] = plansza[licznik][2][4];
				temp[6] = plansza[licznik][2][3];
				temp[7] = plansza[licznik][1][3];
				plansza[licznik][0][5] = temp[0];
				plansza[licznik][1][5] = temp[1];
				plansza[licznik][2][5] = temp[2];
				plansza[licznik][2][4] = temp[3];
				plansza[licznik][2][3] = temp[4];
				plansza[licznik][1][3] = temp[5];
				plansza[licznik][0][3] = temp[6];
				plansza[licznik][0][4] = temp[7];
			}
			else
			{
				temp[0] = plansza[licznik][0][3];
				temp[1] = plansza[licznik][0][4];
				temp[2] = plansza[licznik][0][5];
				temp[3] = plansza[licznik][1][5];
				temp[4] = plansza[licznik][2][5];
				temp[5] = plansza[licznik][2][4];
				temp[6] = plansza[licznik][2][3];
				temp[7] = plansza[licznik][1][3];
				plansza[licznik][2][3] = temp[0];
				plansza[licznik][1][3] = temp[1];
				plansza[licznik][0][3] = temp[2];
				plansza[licznik][0][4] = temp[3];
				plansza[licznik][0][5] = temp[4];
				plansza[licznik][1][5] = temp[5];
				plansza[licznik][2][5] = temp[6];
				plansza[licznik][2][4] = temp[7];
			}
			break;
		}
		case 'a':
		{
			if (obrot == 'z')
			{
				temp[0] = plansza[licznik][3][0];
				temp[1] = plansza[licznik][3][1];
				temp[2] = plansza[licznik][3][2];
				temp[3] = plansza[licznik][4][2];
				temp[4] = plansza[licznik][5][2];
				temp[5] = plansza[licznik][5][1];
				temp[6] = plansza[licznik][5][0];
				temp[7] = plansza[licznik][4][0];
				plansza[licznik][3][2] = temp[0];
				plansza[licznik][4][2] = temp[1];
				plansza[licznik][5][2] = temp[2];
				plansza[licznik][5][1] = temp[3];
				plansza[licznik][5][0] = temp[4];
				plansza[licznik][4][0] = temp[5];
				plansza[licznik][3][0] = temp[6];
				plansza[licznik][3][1] = temp[7];
			}
			else
			{
				temp[0] = plansza[licznik][3][0];
				temp[1] = plansza[licznik][3][1];
				temp[2] = plansza[licznik][3][2];
				temp[3] = plansza[licznik][4][2];
				temp[4] = plansza[licznik][5][2];
				temp[5] = plansza[licznik][5][1];
				temp[6] = plansza[licznik][5][0];
				temp[7] = plansza[licznik][4][0];
				plansza[licznik][5][0] = temp[0];
				plansza[licznik][4][0] = temp[1];
				plansza[licznik][3][0] = temp[2];
				plansza[licznik][3][1] = temp[3];
				plansza[licznik][3][2] = temp[4];
				plansza[licznik][4][2] = temp[5];
				plansza[licznik][5][2] = temp[6];
				plansza[licznik][5][1] = temp[7];
			}
			break;
		}
		case 's':
		{
			if (obrot == 'z')
			{
				temp[0] = plansza[licznik][3][3];
				temp[1] = plansza[licznik][3][4];
				temp[2] = plansza[licznik][3][5];
				temp[3] = plansza[licznik][4][5];
				temp[4] = plansza[licznik][5][5];
				temp[5] = plansza[licznik][5][4];
				temp[6] = plansza[licznik][5][3];
				temp[7] = plansza[licznik][4][3];
				plansza[licznik][3][5] = temp[0];
				plansza[licznik][4][5] = temp[1];
				plansza[licznik][5][5] = temp[2];
				plansza[licznik][5][4] = temp[3];
				plansza[licznik][5][3] = temp[4];
				plansza[licznik][4][3] = temp[5];
				plansza[licznik][3][3] = temp[6];
				plansza[licznik][3][4] = temp[7];
			}
			else
			{
				temp[0] = plansza[licznik][3][3];
				temp[1] = plansza[licznik][3][4];
				temp[2] = plansza[licznik][3][5];
				temp[3] = plansza[licznik][4][5];
				temp[4] = plansza[licznik][5][5];
				temp[5] = plansza[licznik][5][4];
				temp[6] = plansza[licznik][5][3];
				temp[7] = plansza[licznik][4][3];
				plansza[licznik][5][3] = temp[0];
				plansza[licznik][4][3] = temp[1];
				plansza[licznik][3][3] = temp[2];
				plansza[licznik][3][4] = temp[3];
				plansza[licznik][3][5] = temp[4];
				plansza[licznik][4][5] = temp[5];
				plansza[licznik][5][5] = temp[6];
				plansza[licznik][5][4] = temp[7];
			}
			break;
		}
		}
	}
	else
	{
		do
		{
			if (obrot != 'z' && obrot != 'x' && obrot != ' ')
			{
				wyswietl(gracz1, gracz2, plansza, licznik);
				cout << "Bledny kierunek obrotu!!!";
			}

			do
			{
				if (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's' && czesc_planszy != ' ')
				{
					wyswietl(gracz1, gracz2, plansza, licznik);
					cout << "Bledna czesc planszy!!!";

				}

				cout << endl << "Ruch gracza: " << gracz2.imie << endl << endl << "                       q w" << endl << "Wybierz czesc planszy  a s" << endl;
				cin >> czesc_planszy;

			} while (czesc_planszy != 'q' && czesc_planszy != 'w' && czesc_planszy != 'a' && czesc_planszy != 's');


			cout << "Wybierz kierunek ruchu planszy (z, x): ";
			cin >> obrot;
		} while (obrot != 'z' && obrot != 'x');

		switch (czesc_planszy)
		{
		case 'q':
		{
			if (obrot == 'z')
			{
				temp[0] = plansza[licznik][0][0];
				temp[1] = plansza[licznik][0][1];
				temp[2] = plansza[licznik][0][2];
				temp[3] = plansza[licznik][1][2];
				temp[4] = plansza[licznik][2][2];
				temp[5] = plansza[licznik][2][1];
				temp[6] = plansza[licznik][2][0];
				temp[7] = plansza[licznik][1][0];
				plansza[licznik][0][2] = temp[0];
				plansza[licznik][1][2] = temp[1];
				plansza[licznik][2][2] = temp[2];
				plansza[licznik][2][1] = temp[3];
				plansza[licznik][2][0] = temp[4];
				plansza[licznik][1][0] = temp[5];
				plansza[licznik][0][0] = temp[6];
				plansza[licznik][0][1] = temp[7];
			}
			else
			{
				temp[0] = plansza[licznik][0][0];
				temp[1] = plansza[licznik][0][1];
				temp[2] = plansza[licznik][0][2];
				temp[3] = plansza[licznik][1][2];
				temp[4] = plansza[licznik][2][2];
				temp[5] = plansza[licznik][2][1];
				temp[6] = plansza[licznik][2][0];
				temp[7] = plansza[licznik][1][0];
				plansza[licznik][2][0] = temp[0];
				plansza[licznik][1][0] = temp[1];
				plansza[licznik][0][0] = temp[2];
				plansza[licznik][0][1] = temp[3];
				plansza[licznik][0][2] = temp[4];
				plansza[licznik][1][2] = temp[5];
				plansza[licznik][2][2] = temp[6];
				plansza[licznik][2][1] = temp[7];
			}
			break;
		}
		case 'w':
		{
			if (obrot == 'z')
			{
				temp[0] = plansza[licznik][0][3];
				temp[1] = plansza[licznik][0][4];
				temp[2] = plansza[licznik][0][5];
				temp[3] = plansza[licznik][1][5];
				temp[4] = plansza[licznik][2][5];
				temp[5] = plansza[licznik][2][4];
				temp[6] = plansza[licznik][2][3];
				temp[7] = plansza[licznik][1][3];
				plansza[licznik][0][5] = temp[0];
				plansza[licznik][1][5] = temp[1];
				plansza[licznik][2][5] = temp[2];
				plansza[licznik][2][4] = temp[3];
				plansza[licznik][2][3] = temp[4];
				plansza[licznik][1][3] = temp[5];
				plansza[licznik][0][3] = temp[6];
				plansza[licznik][0][4] = temp[7];
			}
			else
			{
				temp[0] = plansza[licznik][0][3];
				temp[1] = plansza[licznik][0][4];
				temp[2] = plansza[licznik][0][5];
				temp[3] = plansza[licznik][1][5];
				temp[4] = plansza[licznik][2][5];
				temp[5] = plansza[licznik][2][4];
				temp[6] = plansza[licznik][2][3];
				temp[7] = plansza[licznik][1][3];
				plansza[licznik][2][3] = temp[0];
				plansza[licznik][1][3] = temp[1];
				plansza[licznik][0][3] = temp[2];
				plansza[licznik][0][4] = temp[3];
				plansza[licznik][0][5] = temp[4];
				plansza[licznik][1][5] = temp[5];
				plansza[licznik][2][5] = temp[6];
				plansza[licznik][2][4] = temp[7];
			}
			break;
		}
		case 'a':
		{
			if (obrot == 'z')
			{
				temp[0] = plansza[licznik][3][0];
				temp[1] = plansza[licznik][3][1];
				temp[2] = plansza[licznik][3][2];
				temp[3] = plansza[licznik][4][2];
				temp[4] = plansza[licznik][5][2];
				temp[5] = plansza[licznik][5][1];
				temp[6] = plansza[licznik][5][0];
				temp[7] = plansza[licznik][4][0];
				plansza[licznik][3][2] = temp[0];
				plansza[licznik][4][2] = temp[1];
				plansza[licznik][5][2] = temp[2];
				plansza[licznik][5][1] = temp[3];
				plansza[licznik][5][0] = temp[4];
				plansza[licznik][4][0] = temp[5];
				plansza[licznik][3][0] = temp[6];
				plansza[licznik][3][1] = temp[7];
			}
			else
			{
				temp[0] = plansza[licznik][3][0];
				temp[1] = plansza[licznik][3][1];
				temp[2] = plansza[licznik][3][2];
				temp[3] = plansza[licznik][4][2];
				temp[4] = plansza[licznik][5][2];
				temp[5] = plansza[licznik][5][1];
				temp[6] = plansza[licznik][5][0];
				temp[7] = plansza[licznik][4][0];
				plansza[licznik][5][0] = temp[0];
				plansza[licznik][4][0] = temp[1];
				plansza[licznik][3][0] = temp[2];
				plansza[licznik][3][1] = temp[3];
				plansza[licznik][3][2] = temp[4];
				plansza[licznik][4][2] = temp[5];
				plansza[licznik][5][2] = temp[6];
				plansza[licznik][5][1] = temp[7];
			}
			break;
		}
		case 's':
		{
			if (obrot == 'z')
			{
				temp[0] = plansza[licznik][3][3];
				temp[1] = plansza[licznik][3][4];
				temp[2] = plansza[licznik][3][5];
				temp[3] = plansza[licznik][4][5];
				temp[4] = plansza[licznik][5][5];
				temp[5] = plansza[licznik][5][4];
				temp[6] = plansza[licznik][5][3];
				temp[7] = plansza[licznik][4][3];
				plansza[licznik][3][5] = temp[0];
				plansza[licznik][4][5] = temp[1];
				plansza[licznik][5][5] = temp[2];
				plansza[licznik][5][4] = temp[3];
				plansza[licznik][5][3] = temp[4];
				plansza[licznik][4][3] = temp[5];
				plansza[licznik][3][3] = temp[6];
				plansza[licznik][3][4] = temp[7];
			}
			else
			{
				temp[0] = plansza[licznik][3][3];
				temp[1] = plansza[licznik][3][4];
				temp[2] = plansza[licznik][3][5];
				temp[3] = plansza[licznik][4][5];
				temp[4] = plansza[licznik][5][5];
				temp[5] = plansza[licznik][5][4];
				temp[6] = plansza[licznik][5][3];
				temp[7] = plansza[licznik][4][3];
				plansza[licznik][5][3] = temp[0];
				plansza[licznik][4][3] = temp[1];
				plansza[licznik][3][3] = temp[2];
				plansza[licznik][3][4] = temp[3];
				plansza[licznik][3][5] = temp[4];
				plansza[licznik][4][5] = temp[5];
				plansza[licznik][5][5] = temp[6];
				plansza[licznik][5][4] = temp[7];
			}
			break;
		}
		}
	}
}
void wczytaj_czas(gracz& gracz1, gracz& gracz2)
{
	system("cls");
	cout << "Podaj czas dostepny dla gracza: ";
	cin >> gracz1.czas;
	gracz2.czas = gracz1.czas;
}