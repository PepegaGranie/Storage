#include <math.h>
#include <map>
#ifndef test_h
#define test_h

using namespace std;

float currentmoneytable(int a){
map<int,float>currentmoney={{1,0.780029},{2,13153.7},{3,75559.8},{4,45864.6},{5,53276.2},{6,21895.7},{7,4704.41},{8,67885.8}};
return currentmoney[a];}

#endif // test.h
