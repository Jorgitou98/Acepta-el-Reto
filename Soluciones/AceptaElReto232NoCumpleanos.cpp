#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class fecha{
	private:
		int dia, mes, anyo;
	public:
		fecha(){}
		fecha(int dia1, int mes1, int anyo1){
			dia = dia1;
			mes = mes1;
			anyo = anyo1;
		}
		bool esNoCumpleanyos(fecha const& fecha1){
			return (dia != fecha1.dia || mes != fecha1.mes);
		}
		bool todoCero(){
			return (dia == 0 && mes == 0 && anyo == 0);
		}
		int diasHastaLaFecha(fecha const& fecha1){
			int dias = 0;
			vector <int> diasAnyo = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			if (fecha1.anyo > anyo){
				dias += diasAnyo[mes - 1] - dia;
				for (int i = mes; i < 12; ++i){
					dias += diasAnyo[i];
				}
				for (int i = anyo + 1; i < fecha1.anyo; ++i){
					dias += 364;
				}
				for (int i = 0; i < fecha1.mes - 1; ++i){
					dias += diasAnyo[i];
				}
				dias += fecha1.dia;
				if (mes < fecha1.mes || (mes == fecha1.mes && dia < fecha1.dia)){
					dias--;
				}
			}
			else if (fecha1.anyo == anyo){
				if (fecha1.mes == mes) dias += fecha1.dia - dia;
				else {
					dias += diasAnyo[mes - 1] - dia;
					for (int i = mes; i < fecha1.mes - 1; ++i){
						dias += diasAnyo[i];
					}
					dias += fecha1.dia;
				}
			}	
			return dias;
		}
};

inline istream & operator >>(istream & in, fecha &fecha1){
	int dia1, mes1, anyo1;
	in >> dia1 >> mes1 >> anyo1;
	fecha1 = fecha(dia1, mes1, anyo1);
	return in;
}


bool resuelveCaso() {
	fecha nacimiento, hoy;
	cin >> nacimiento >> hoy;
	if (nacimiento.todoCero() && hoy.todoCero())
		return false;
	if (nacimiento.esNoCumpleanyos(hoy)){
		cout << nacimiento.diasHastaLaFecha(hoy) << '\n';
	}
	else cout << "0\n";
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
