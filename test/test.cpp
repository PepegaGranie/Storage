#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <random>
#include <iomanip>
#include <cmath>


using namespace std;

string names(int a){    //funkcja, w której na danej pozycji znajduje siê dana nazwa
setlocale(LC_CTYPE,"Polish");   //uwzglêdnia polskie znaki
string nazwy[8]={"Grzegorz Brzêczyszczykiewicz","W³adys³aw Remont","Janusz Nosacz","Tomasz Problem","Maria Sk³adowska-Kiri","Ludwik Karolak","Jadwiga DŸwiga³a","Stanis³awa Mordel"}; // tablica, zawieraj¹ca nazwy
return nazwy[a-1];      //funkcja zwraca dan¹ nazwe
}

string code(int a){     //funkcja, która generuje kod
if(a<10 && a>0){        //petla rekurencyjna
string kod="00";        //ustawianie pierwszej czêci kodu
kod.insert(2,to_string(a)); //dodanie do czêci kodu dane id (tylko dla id o liczbie jednocyfrowej)
return kod;             //zwraca kod
}
else{                   //na wypadek, gdyby liczba by³a wiêksza lub równa 10 albo mniejsza od 1 (na chwilê obecn¹ aplikacja ograniczona jest do max. 9 (gdy bêdzie wiêcej u¿ytkowników, zrobi siê dla wiêcej u¿ytkowników))
return 0;               //funkcja zwraca liczbê 0
}
}

float moneygen(int a){  //funkcja, która generuje losowe liczby do salda u¿ytkowników na pocz¹tek
float money[7];         //tablica, która bêdzie przechowywaæ wygenerowane liczby do salda danego u¿ytkownika na pocz¹tek
default_random_engine generator;    //tworzenie silnika liczb losowych
uniform_real_distribution<float>distribution(0,99999);  //ustawianie liczb mo¿liwych do wylosowania (od,do)
int i=1;                //zmienna, która przyda siê do petli poni¿ej
do{                     //pêtla do...while
money[i-1]=round(distribution(generator)*100.0)/100.0;  //generowanie losowej liczby do tablicy liczb
i++;                    //inkrementacja zmiennej i
}
while(i<=8);            //wykonuje pêtle a¿ do i równego 8
return money[a-1];      //funckja zwraca wygenerowan¹ liczbê
}

int createdata(){       //funkcja, która tworzy dane do naszego programu
fstream data;           //klasa strumienia wejœcia/wyjœcia do operowania na plikach
data.open("data.txt",ios::out);     //tworzy i otwiera plik tekstowy "data"
for(int i=1;i<=8;i++){              //pêtla rekurencyjna
data<<i<<endl;                      //wstawianie danych do pliku tekstowego (jedna linia, id)
data<<names(i)<<endl;               //wstawianie danych do pliku tekstowego (jedna linia, nazwa)
data<<code(i)<<endl;                //wstawianie danych do pliku tekstowego (jedna linia, nr konta)
data<<moneygen(i)<<endl;            //wstawianie danych do pliku tekstowego (jedna linia, saldo)
}
data.close();                       //zamyka plik tekstowy "data"
return 1;
}

int checkdata(){                    //funkcja, która sprawdza, czy plik tekstowy "data" istnieje
ifstream data("data.txt");          //próba uruchomienia pliku tekstowego "data"
if(data.fail()){                    //jezeli nie uda siê otworzyæ pliku to...
createdata();                       //tworzy plik tekstowy za pomoc¹ funkcji "createdata()"
}
return 1;                           //funcja zwraca liczbê 1
}
int showdata(){                     //funkcja, która wyœwietla listê u¿ytkowników
setlocale(LC_CTYPE,"Polish");       //uwzglêdnia polskie znaki
cout<<"Lista u¿ytkowników"<<endl;   //wyœwietla tekst
cout<<"Id   |Nazwa          |Nr konta   |Saldo"<<endl;  //wyœwietla tekst
fstream data;                       //klasa strumienia wejœcia/wyjœcia do operowania na plikach
data.open("data.txt",ios::in);      //otwiera plik tekstowy "data"
string line;                        //zmienna string
int nr_line=1;                      //zmienna integer
while(getline(data,line)){          //wykonuje pêtle do ostatniej lini, która zawiera dane
if(nr_line==4){                     //w przypadku gdy "nr_line" osi¹gnie liczbê 4
cout<<setprecision(2)<<fixed<<atof(line.c_str())<<" z³";     //wyœwietla saldo (przyk³ad: 1.20 z³)
cout<<endl;                         //"Enter"
nr_line=1;                          //zmienia liczbê "nr_line" z powrotem na 1
}
else{                               //gdy "nr_line" jest ró¿na od 4
cout<<line<<"   ";                  //wyœwietlanie danych
nr_line++;                          //inkrementacja zmiennej
}
}
data.close();                       //zamyka plik tekstowy "data"
return 1;                           //funkcja zwraca liczbê 1
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
cout<<"Nieprawid³owy numer konta"<<endl;
return 0;
}
}

int main()
{
setlocale(LC_CTYPE,"Polish");
checkdata();





return 0;
}

