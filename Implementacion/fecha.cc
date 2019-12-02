#include "fecha.h"

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

string getSysFecha()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,sizeof(buffer),"%d/%m/%Y",timeinfo);
  string str(buffer);

  return str;
}

int cmpFecha(string const &fecha1, string const &fecha2)
{
  int day1, day2;
  day1=stoi(fecha1.substr(0,2))+stoi(fecha1.substr(3,2))+stoi(fecha1.substr(6,4));
  day2=stoi(fecha2.substr(0,2))+stoi(fecha2.substr(3,2))+stoi(fecha2.substr(6,4));
  return day1==day2?0:(day1<day2?(-1):1);
}
