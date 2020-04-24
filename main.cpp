#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class osoba
{
	
	public:
		
		string imie,nazwisko;
		int pesel;
		string napis;
		char znak;
		
		ifstream plik1;
    	ofstream plik2;
		
		osoba();
        ~osoba();
		
		void wprowadzKonsola();
		void wypiszKonsola();
		void wprowadzPlik();
		void wypiszPlik();
};

osoba::osoba(){
	plik1.open("c:\\palindromy.txt");
    plik2.open("c:\\wynikJSON.txt");
};

void osoba::wprowadzKonsola(){
	cout<<"Podaj imie, nazwisko, pesel"<<endl;
	cin>>imie>>nazwisko>>pesel;
};

void osoba::wypiszKonsola(){
	cout<<"{\"imie"<<"\":\""<<imie<<"\",\"nazwisko\":\""<<nazwisko<<"\,\"pesel\":\""<<pesel<<"\"}";
}

void osoba::wprowadzPlik(){
	
	int i=0;
	string helped;
	
	while(!plik1.eof()){ 
		if(i<3){
	        plik1>>znak>>napis;
			
			if(i==0) imie=znak+napis;		
			if(i==1) nazwisko=znak+napis;		
			if(i==2) helped=znak+napis;
			
			pesel=atoi(helped.c_str());
			 
			i++;
		 }else{
		 	break;
		 }
	}
};

void osoba::wypiszPlik(){
	plik2<<"{\"imie"<<"\":\""<<imie<<"\",\"nazwisko\":\""<<nazwisko<<"\,\"pesel\":\""<<pesel<<"\"}";
}

class uczen:public osoba
{
	string klasa;
	string srednia_ocen;
	
	public:
		void wprowadz_ucznia_Konsola();
		void wprowadz_ucznia_Plik();
		void wypisz_ucznia_Konsola();
		void wypisz_ucznia_Plik();
};

void uczen::wprowadz_ucznia_Konsola(){
	wprowadzKonsola();
	cout<<endl<<"Klasa oraz srednia"<<endl;
	cin>>klasa>>srednia_ocen;
};

void uczen:: wypisz_ucznia_Konsola(){
	cout<<"{\"imie"<<"\":\""<<imie<<"\",\"nazwisko\":\""<<nazwisko<<"\,\"pesel\":\""
	<<pesel<<"\",\"klasa"<<"\":\""<<klasa<<"\",\"srednia\":\""<<srednia_ocen<<"\"}";
}

void uczen::wprowadz_ucznia_Plik(){
	int i=0;
	wprowadzPlik();
	while(!plik1.eof()){ 
        plik1>>znak>>napis;   
        
        if(i==0) klasa=znak+napis;
        if(i==1) srednia_ocen=znak+napis;
		i++; 
	}
};

void uczen::wypisz_ucznia_Plik(){
	plik2<<"{\"imie"<<"\":\""<<imie<<"\",\"nazwisko\":\""<<nazwisko<<"\,\"pesel\":\""
	<<pesel<<"\",\"klasa"<<"\":\""<<klasa<<"\",\"srednia\":\""<<srednia_ocen<<"\"}";
};

class nauczyciel:public osoba
{
	string przedmiot;
	
	public:
		void wprowadz_nauczyciela_Konsola();
		void wprowadz_nauczyciela_Plik();
		void wypisz_nauczyciela_Konsola();
		void wypisz_nauczyciela_Plik();
};

void nauczyciel::wprowadz_nauczyciela_Konsola(){
	wprowadzKonsola();
	cout<<endl<<"I przedmiot"<<endl;
	cin>>przedmiot;
}

void nauczyciel:: wypisz_nauczyciela_Konsola(){
	cout<<"{\"imie"<<"\":\""<<imie<<"\",\"nazwisko\":\""<<nazwisko<<"\,\"pesel\":\""
	<<pesel<<"\",\"przedmiot"<<"\":\""<<przedmiot<<"\"}";
}

void nauczyciel::wprowadz_nauczyciela_Plik(){
	wprowadzPlik();
	while(!plik1.eof()){ 
        plik1>>znak>>napis;    
	}
	cout<<znak<<napis;
}

void nauczyciel::wypisz_nauczyciela_Plik(){
	plik2<<"{\"imie"<<"\":\""<<imie<<"\",\"nazwisko\":\""<<nazwisko<<"\,\"pesel\":\""
	<<pesel<<"\",\"przedmiot"<<"\":\""<<przedmiot<<"\"}";
}

osoba::~osoba(){
    plik1.close();
    plik2.close();
}

int main(int argc, char** argv) {
	nauczyciel n1;
	osoba o1;
	uczen u1;

	return 0;
}
