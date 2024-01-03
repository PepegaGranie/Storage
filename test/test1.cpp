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
#include "test.h"

using namespace std;


map<int,string>names{{1,"Grzegorz Brzeczyszczykiewicz"},{2,"Wladyslaw Remont"},{3,"Janusz Nosacz"},{4,"Tomasz Problem"},{5,"Maria Skladowska-Kiri"},{6,"Ludwik Karolak"},{7,"Jadwiga Dzwigala"},{8,"Stanislawa Mordel"},};
map<int,float>moneytable{{1,currentmoneytable(1)},{2,currentmoneytable(2)},{3,currentmoneytable(3)},{4,currentmoneytable(4)},{5,currentmoneytable(5)},{6,currentmoneytable(6)},{7,currentmoneytable(7)},{8,currentmoneytable(8)}};

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
float a=moneytable[1];
float b=moneytable[2];
float c=moneytable[3];
float d=moneytable[4];
float e=moneytable[5];
float f=moneytable[6];
float g=moneytable[7];
float h=moneytable[8];
remove("test.h");
fstream data;
data.open("test.h",ios::out);
data<<"#include <math.h>"<<endl;
data<<"#include <map>"<<endl;
data<<"#ifndef test_h"<<endl;
data<<"#define test_h"<<endl<<endl;
data<<"using namespace std;"<<endl<<endl;
data<<"float currentmoneytable(int a){"<<endl;
data<<"map<int,float>currentmoney={{1,"<<a<<"},{2,"<<b<<"},{3,"<<c<<"},{4,"<<d<<"},{5,"<<e<<"},{6,"<<f<<"},{7,"<<g<<"},{8,"<<h<<"}};"<<endl;
data<<"return currentmoney[a];}"<<endl<<endl;
data<<"#endif // test.h"<<endl;
data.close();
return 0;
}

int start(){

return 0;
}

int main()
{
/*           uzyte wczesniej, w celu wygenerowania liczb do kont uzytkownikow
moneygen();
savemoney();
*/


return 0;
}
