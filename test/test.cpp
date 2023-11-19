#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <random>
#include <iomanip>
#include <cmath>


using namespace std;

string names(int a){    //funkcja, w kt�rej na danej pozycji znajduje si� dana nazwa
setlocale(LC_CTYPE,"Polish");   //uwzgl�dnia polskie znaki
string nazwy[8]={"Grzegorz Brz�czyszczykiewicz","W�adys�aw Remont","Janusz Nosacz","Tomasz Problem","Maria Sk�adowska-Kiri","Ludwik Karolak","Jadwiga D�wiga�a","Stanis�awa Mordel"}; // tablica, zawieraj�ca nazwy
return nazwy[a-1];      //funkcja zwraca dan� nazwe
}

string code(int a){     //funkcja, kt�ra generuje kod
if(a<10 && a>0){        //petla rekurencyjna
string kod="00";        //ustawianie pierwszej cz�ci kodu
kod.insert(2,to_string(a)); //dodanie do cz�ci kodu dane id (tylko dla id o liczbie jednocyfrowej)
return kod;             //zwraca kod
}
else{                   //na wypadek, gdyby liczba by�a wi�ksza lub r�wna 10 albo mniejsza od 1 (na chwil� obecn� aplikacja ograniczona jest do max. 9 (gdy b�dzie wi�cej u�ytkownik�w, zrobi si� dla wi�cej u�ytkownik�w))
return 0;               //funkcja zwraca liczb� 0
}
}

float moneygen(int a){  //funkcja, kt�ra generuje losowe liczby do salda u�ytkownik�w na pocz�tek
float money[7];         //tablica, kt�ra b�dzie przechowywa� wygenerowane liczby do salda danego u�ytkownika na pocz�tek
default_random_engine generator;    //tworzenie silnika liczb losowych
uniform_real_distribution<float>distribution(0,99999);  //ustawianie liczb mo�liwych do wylosowania (od,do)
int i=1;                //zmienna, kt�ra przyda si� do petli poni�ej
do{                     //p�tla do...while
money[i-1]=round(distribution(generator)*100.0)/100.0;  //generowanie losowej liczby do tablicy liczb
i++;                    //inkrementacja zmiennej i
}
while(i<=8);            //wykonuje p�tle a� do i r�wnego 8
return money[a-1];      //funckja zwraca wygenerowan� liczb�
}

int createdata(){       //funkcja, kt�ra tworzy dane do naszego programu
fstream data;           //klasa strumienia wej�cia/wyj�cia do operowania na plikach
data.open("data.txt",ios::out);     //tworzy i otwiera plik tekstowy "data"
for(int i=1;i<=8;i++){              //p�tla rekurencyjna
data<<i<<endl;                      //wstawianie danych do pliku tekstowego (jedna linia, id)
data<<names(i)<<endl;               //wstawianie danych do pliku tekstowego (jedna linia, nazwa)
data<<code(i)<<endl;                //wstawianie danych do pliku tekstowego (jedna linia, nr konta)
data<<moneygen(i)<<endl;            //wstawianie danych do pliku tekstowego (jedna linia, saldo)
}
data.close();                       //zamyka plik tekstowy "data"
return 1;
}

int checkdata(){                    //funkcja, kt�ra sprawdza, czy plik tekstowy "data" istnieje
ifstream data("data.txt");          //pr�ba uruchomienia pliku tekstowego "data"
if(data.fail()){                    //jezeli nie uda si� otworzy� pliku to...
createdata();                       //tworzy plik tekstowy za pomoc� funkcji "createdata()"
}
return 1;                           //funcja zwraca liczb� 1
}
int showdata(){                     //funkcja, kt�ra wy�wietla list� u�ytkownik�w
setlocale(LC_CTYPE,"Polish");       //uwzgl�dnia polskie znaki
cout<<"Lista u�ytkownik�w"<<endl;   //wy�wietla tekst
cout<<"Id   |Nazwa          |Nr konta   |Saldo"<<endl;  //wy�wietla tekst
fstream data;                       //klasa strumienia wej�cia/wyj�cia do operowania na plikach
data.open("data.txt",ios::in);      //otwiera plik tekstowy "data"
string line;                        //zmienna string
int nr_line=1;                      //zmienna integer
while(getline(data,line)){          //wykonuje p�tle do ostatniej lini, kt�ra zawiera dane
if(nr_line==4){                     //w przypadku gdy "nr_line" osi�gnie liczb� 4
cout<<setprecision(2)<<fixed<<atof(line.c_str())<<" z�";     //wy�wietla saldo (przyk�ad: 1.20 z�)
cout<<endl;                         //"Enter"
nr_line=1;                          //zmienia liczb� "nr_line" z powrotem na 1
}
else{                               //gdy "nr_line" jest r�na od 4
cout<<line<<"   ";                  //wy�wietlanie danych
nr_line++;                          //inkrementacja zmiennej
}
}
data.close();                       //zamyka plik tekstowy "data"
return 1;                           //funkcja zwraca liczb� 1
}

int login(string a){
setlocale(LC_CTYPE,"Polish");
int b=atoi(a.c_str());
if(b>0 && b<9){
fstream data;
data.open("data.txt",ios::in);
string line;
int nr_line=1;
int nr_id=1;
while(getline(data,line)){
if(nr_line==4){
nr_id++;
nr_line=1;
}
else if(nr_id==b){
if(nr_line==2){
cout<<"Witaj "<<line<<endl;
}
else if(nr_line==4){
cout<<"Saldo: "<<line<<endl;
return 1;
}
}
else{
nr_line++;
}
}
}
else{
cout<<"Nieprawid�owy numer konta"<<endl;
return 0;
}
}

int main()
{
setlocale(LC_CTYPE,"Polish");
checkdata();





return 0;
}

