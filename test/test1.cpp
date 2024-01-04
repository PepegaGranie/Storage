#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <cstdlib>
#include "test.h"

using namespace std;

int option;
int listoption;

map<int,string>names{{1,"Grzegorz Brzeczyszczykiewicz"},{2,"Wladyslaw Remont"},{3,"Janusz Nosacz"},{4,"Tomasz Problem"},{5,"Maria Skladowska-Kiri"},{6,"Ludwik Karolak"},{7,"Jadwiga Dzwigala"},{8,"Stanislawa Mordel"},};
map<int,float>moneytable{{1,currentmoneytable(1)},{2,currentmoneytable(2)},{3,currentmoneytable(3)},{4,currentmoneytable(4)},{5,currentmoneytable(5)},{6,currentmoneytable(6)},{7,currentmoneytable(7)},{8,currentmoneytable(8)}};

struct{
string name;
float value;
int id;
} user;

vector<string>firstlist{"Dzien dobry",
"1. Lista uzytkownikow",
"2. Logowanie",
"3. Wyjscie"
};

vector<string>secondlist{"1. Wyplac",
"2. Przelew na konto",
"3. Wplac",
"4. Wyloguj sie"};

int moneygen(){
float money[7];
default_random_engine generator;
uniform_real_distribution<float>distribution(0,99999);
int i=1;
do{
money[i-1]=round(distribution(generator)*100)/100;
moneytable.find(i)->second=money[i-1];
i++;
}
while(i<=8);
return 0;
}

int savemoney(){
float a[8]={moneytable[1],moneytable[2],moneytable[3],moneytable[4],moneytable[5],moneytable[6],moneytable[7],moneytable[8]};
remove("test.h");
fstream data;
data.open("test.h",ios::out);
data<<"#include <math.h>"<<endl;
data<<"#include <map>"<<endl;
data<<"#ifndef test_h"<<endl;
data<<"#define test_h"<<endl<<endl;
data<<"using namespace std;"<<endl<<endl;
data<<"float currentmoneytable(int a){"<<endl;
data<<"map<int,float>currentmoney={{1,"<<a[0]<<"},{2,"<<a[1]<<"},{3,"<<a[2]<<"},{4,"<<a[3]<<"},{5,"<<a[4]<<"},{6,"<<a[5]<<"},{7,"<<a[6]<<"},{8,"<<a[7]<<"}};"<<endl;
data<<"return currentmoney[a];}"<<endl<<endl;
data<<"#endif // test.h"<<endl;
data.close();
return 0;
}

int showdata(){
cout<<"Lista uzytkownikow"<<endl;
cout<<"Id  |Nazwa                  |Nr konta   |Saldo"<<endl;
for(int i=1;i<=8;i++){
cout<<i<<"   |"<<names[i]<<"        |"<<"00"<<i<<"      |"<<setprecision(2)<<fixed<<moneytable[i]<<" pln"<<endl;
}
cout<<"1. Powrot do menu"<<endl;
cin>>option;
switch(option){
case 1:
cout<<endl;
return 0;
break;
default:
cout<<"Brak opcji pod tym numerem (dany numer znajduje sie obok opcji np: 1. Lista uzytkownikow (liczba jeden jest tutaj numerem opcji))"<<endl<<endl;
}
return 0;
}

int deposit(){
float amount;
cout<<"Ile pln chcesz wplacic?"<<endl;
cin>>amount;
if(amount>0){
moneytable[user.id]=moneytable[user.id]+amount;
savemoney();
cout<<"Operacja przebiegla pomyslnie"<<endl<<endl;
}
else{
cout<<"Nieprawidlowa wartosc"<<endl;
cout<<"1. Sprobuj ponownie"<<endl;
cout<<"2. Powrot"<<endl;
cin>>option;
switch(option){
case 1:
cout<<endl;
deposit();
break;
case 2:
cout<<endl;
break;
default:
cout<<"Brak opcji pod tym numerem (dany numer znajduje sie obok opcji np: 1. Lista uzytkownikow (liczba jeden jest tutaj numerem opcji))"<<endl<<endl;
deposit();
}
}
return 0;
}

int withdraw(){
float amount;
cout<<"Ile pln chcesz wyplacic?"<<endl;
cin>>amount;
if(amount>0){
if(amount<moneytable[user.id]){
moneytable[user.id]=moneytable[user.id]-amount;
savemoney();
cout<<"Operacja przebiegla pomyslnie"<<endl<<endl;
}
else{
cout<<"Za malo srodkow na koncie, aby wyplacic podana wartosc"<<endl;
cout<<"1. Sprobuj ponownie"<<endl;
cout<<"2. Powrot"<<endl;
cin>>option;
switch(option){
case 1:
cout<<endl;
withdraw();
break;
case 2:
cout<<endl;
break;
default:
cout<<"Brak opcji pod tym numerem (dany numer znajduje sie obok opcji np: 1. Lista uzytkownikow (liczba jeden jest tutaj numerem opcji))"<<endl<<endl;
withdraw();
}
}
}
else{
cout<<"Nieprawidlowa wartosc"<<endl;
cout<<"1. Sprobuj ponownie"<<endl;
cout<<"2. Powrot"<<endl;
cin>>option;
switch(option){
case 1:
cout<<endl;
withdraw();
break;
case 2:
cout<<endl;
break;
default:
cout<<"Brak opcji pod tym numerem (dany numer znajduje sie obok opcji np: 1. Lista uzytkownikow (liczba jeden jest tutaj numerem opcji))"<<endl<<endl;
withdraw();
}
}
return 0;
}

int transferparttwo(){
float amount;
cout<<"Ile pln chcesz przelac?"<<endl;
cin>>amount;
if(amount>0){
if(amount<moneytable[user.id]){
moneytable[user.id]=moneytable[user.id]-amount;
moneytable[listoption]=moneytable[listoption]+amount;
savemoney();
cout<<"Operacja przebiegla pomyslnie"<<endl<<endl;
}
else{
cout<<"Za malo srodkow na koncie, aby przelac podana wartosc"<<endl;
cout<<"1. Sprobuj ponownie"<<endl;
cout<<"2. Powrot"<<endl;
cin>>option;
switch(option){
case 1:
cout<<endl;
transferparttwo();
break;
case 2:
cout<<endl;
break;
default:
cout<<"Brak opcji pod tym numerem (dany numer znajduje sie obok opcji np: 1. Lista uzytkownikow (liczba jeden jest tutaj numerem opcji))"<<endl<<endl;
transferparttwo();
}
}
}
else{
cout<<"Nieprawidlowa wartosc"<<endl;
cout<<"1. Sprobuj ponownie"<<endl;
cout<<"2. Powrot"<<endl;
cin>>option;
switch(option){
case 1:
cout<<endl;
transferparttwo();
break;
case 2:
cout<<endl;
break;
default:
cout<<"Brak opcji pod tym numerem (dany numer znajduje sie obok opcji np: 1. Lista uzytkownikow (liczba jeden jest tutaj numerem opcji))"<<endl<<endl;
transferparttwo();
}
}
return 0;
}

int transfer(){
float amount;
cout<<"Lista uzytkownikow"<<endl;
cout<<"Numer    |Uzytkownik"<<endl;
for(int i=1;i<=8;i++){
cout<<i<<".     "<<names[i]<<endl;
}
cout<<endl<<"0. Anuluj"<<endl;
cout<<"Wybierz uzytkownika, na ktory ma zostac wyslany przelew (wpisz liczbe obok danego uzytkownika z listy)"<<endl;
cin>>listoption;
if(listoption>0 && listoption<=8){
transferparttwo();
}
else if(listoption==0){
return 0;
}
else{
cout<<"Nie znaleziono uzytkownika"<<endl<<endl;
transfer();
}
return 0;
}

int loggedin(){
cout<<"Zalogowano pomyslnie"<<endl<<endl;
cout<<"Zalogowany: "<<user.name<<endl;
cout<<"Stan konta: "<<setprecision(2)<<fixed<<user.value<<" pln"<<endl;
for(int i=0;i<secondlist.size();i++){
cout<<secondlist[i]<<endl;
}
cout<<"Wybierz opcje: ";
cin>>option;
switch(option){
case 1:
if(withdraw()==0){
loggedin();
}
break;
case 2:
if(transfer()==0){
loggedin();
}
break;
case 3:
if(deposit()==0){
loggedin();
}
break;
case 4:
break;
default:
cout<<"Brak opcji pod tym numerem (dany numer znajduje sie obok opcji np: 1. Lista uzytkownikow (liczba jeden jest tutaj numerem opcji))"<<endl<<endl;
loggedin();
}
return 0;
}

int login(){
string id;
int a;
string b="0";
int c;
string d;
cout<<"Logowanie"<<endl;
cout<<"Podaj numer konta: ";
cin>>id;
cout<<endl;
a=id.size();
d=id.substr(0,2);
if(a==3 && d=="00"){
b=id.substr(2,1);
c=atoi(b.c_str());
if(c>0 && c<=8){
user.name=names[c];
user.value=moneytable[c];
user.id=c;
loggedin();
}
else{
cout<<"Nieprawidlowy numer konta"<<endl;
cout<<"1. Sprobuj ponownie"<<endl;
cout<<"2. Powrot do menu"<<endl;
cin>>option;
switch(option){
case 1:
cout<<endl;
login();
break;
case 2:
cout<<endl;
break;
default:
cout<<"Brak opcji pod tym numerem (dany numer znajduje sie obok opcji np: 1. Lista uzytkownikow (liczba jeden jest tutaj numerem opcji))"<<endl<<endl;
login();
}
}
}
else{
cout<<"Nieprawidlowy numer konta"<<endl;
cout<<"1. Sprobuj ponownie"<<endl;
cout<<"2. Powrot do menu"<<endl;
cin>>option;
switch(option){
case 1:
cout<<endl;
login();
break;
case 2:
cout<<endl;
break;
default:
cout<<"Brak opcji pod tym numerem (dany numer znajduje sie obok opcji np: 1. Lista uzytkownikow (liczba jeden jest tutaj numerem opcji))"<<endl<<endl;
login();
}
}
return 0;
}

int start(){
for(int i=0;i<firstlist.size();i++){
cout<<firstlist[i]<<endl;
}
cout<<"Wybierz opcje: ";
cin>>option;
switch(option){
case 1:
showdata();
start();
break;
case 2:
if(login()==0){
start();
}
break;
case 3:
return 0;
break;
default:
cout<<"Brak opcji pod tym numerem (dany numer znajduje sie obok opcji np: 1. Lista uzytkownikow (liczba jeden jest tutaj numerem opcji))"<<endl<<endl;
start();
}
return 0;
}

int main()
{
/*           uzyte wczesniej, w celu wygenerowania liczb do kont uzytkownikow
moneygen();
savemoney();
*/
start();

return 0;
}
