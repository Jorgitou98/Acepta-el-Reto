// Jorge Villarrubia Elvira
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

int ultimaCifraFactorial(int num);


int ultimaCifraFactorial(int num){
	int ultimaCifra;
	if (num == 1 || num == 0) ultimaCifra = 1;
	else if (num == 2) ultimaCifra = 2;
	else ultimaCifra = num * ultimaCifraFactorial(num -1);
	if (ultimaCifra > 9) ultimaCifra = ultimaCifra % 10;
	return ultimaCifra;
}
