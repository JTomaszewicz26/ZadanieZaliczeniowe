#include <iostream>
#include <cmath>

//funkcja wyswietla menu w konsoli i wywoluje pozostale funckje po wpisaniu danej cyferki
void menu();
//funkcja definiuje tablice, przypisuje jej wartosci i wykonuje na niej obliczenia
void tablica();
//funkcja pobiera od uzytkownika dwa boki prostokata oraz oblicza jego pole i obwod
void figura();
//funkcja w zaleznosci od podanej liczby x zwraca y
double wyrazenie(double x);

int main(){
	menu();
	return 0;
}

void menu(){
	//wyswietlanie menu
	
	std::cout<<"Wybierz opcje: \n"
			<<"1.TABLICA\n"
			<<"2.FIGURA\n"
			<<"3.WYRAZENIE\n"
			<<"4.KONIEC\n";
	//pobieranie opcji i sprawdzenie
	int opcja;
	std::cin>>opcja;
	
	switch(opcja){
		case 1:
			tablica();
			break;
		case 2:
			figura();
			break;
		case 3:
			double x;
			std::cout << "Podaj x: \n";
			std::cin >> x;
			std::cout << "\nDla podanego x funckja przyjmuje wartosc: " << wyrazenie(x); 
			//wyrazenie();
			break;
		case 4:
			//koniec
			break;
		default:
			system("CLS");//czyszczenie i wywolanie funkcji menu w przypadku niepoprawnych danych 
			menu();
	}
	
}

void tablica(){
	std::cout<<"\n\n\n";
	//w poleceniu nie okreslono czy tablica jest dynamiczna, czy ma staly rozmiar
	int rozmiar = 11;
	int tab[rozmiar];
	
	std::cout<<"Podaj liczby do tablicy: \n";
	for(int i = 0; i < rozmiar; i++){
		std::cin >> tab[i];
	}
	
	std::cout<<"Wypisanie tablicy: \n";
	for(int i = 0; i < rozmiar; i++){
		std::cout << tab[i] << ", ";
	}
	
	std::cout<<"\n";
	
	int suma = 0;
	for(int i = 0; i < rozmiar; i++){
		if(tab[i] < 0) suma += tab[i];
	}
	std::cout<< "Suma liczb ujemnych: " << suma;
	
	std::cout<<"\n";
	
	int srednia, ilosc = 0;
	for(int i = 0; i < rozmiar; i++){
		if(tab[i] > 0){
			ilosc++;
			srednia += tab[i];
		} 
	}
	
	srednia = srednia / ilosc;
	
	std::cout << "Srednia liczb dodatnich: " << srednia;
}

void figura(){
	std::cout << "\n\n\n";
	//w tresci zadania nie podano, czy boki maja byc typu zmiennoprzecinkowego.
	int a,b;
	std::cout << "Podaj boki prostokata:\n";
	std::cin >> a >> b;
	
	int pole = a * b;
	int obwod = 2 * a + 2 * b;
	
	std::cout<<"\nPole: " << pole <<" Obwod: "<<obwod;
}

double wyrazenie(double x){
	//jezeli x > 1, to y = cosinus x do kwadratu
	if(x > 0.0) return std::pow(std::cos(x), 2);
	//jezeli x = 0, to y = 1
	if(x == 0.0) return 1.0;
	//jezeli x < 0, to y = wartosc bezwzgledna z x do potegi 3
	if(x < 0.0) return std::abs(std::pow(x, 3));
	//funkcja nigdy nie zwroci -1, ale kompilator moze sie przyczepic gdyby tego nie bylo
	return -1.0;
}
