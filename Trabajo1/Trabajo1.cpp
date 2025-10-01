#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//  Declaración de funciones 
void imprimirLunes();
void imprimirJueves(int hora);
void imprimirMartesODespues(int dia, int hora);
void cicloSemana(int diaActual);

//  Función principal 
int main() {

	// Obtenemos la fecha y hora del sistema.
	time_t ahora = time(0);
	tm* horaLocal = localtime(&ahora);

	// tm_wday guarda el día de la semana (0 = domingo, 1 = lunes, etc.).
	int diaSemana = horaLocal->tm_wday;
	int horaActual = horaLocal->tm_hour;

	// Usamos una estructura 'if-else if' para asegurar que solo se ejecute un bloque.
	// Esto es más correcto y eficiente que usar 'if' separados.
	if (diaSemana == 1) { // Lunes
		imprimirLunes();
	}
	else if (diaSemana == 4 && horaActual < 12) { // Jueves (4)
		imprimirJueves(horaActual);
	}
	else if (diaSemana == 2 || diaSemana > 4) { // Martes (2) o después del jueves
		imprimirMartesODespues(diaSemana, horaActual);
	}

	// El ciclo de la semana para mostrar el día actual.
	cicloSemana(diaSemana);

	return 0;
}

//  Implementación de funciones 

void imprimirLunes() {
	cout << "Es lunes" << endl; // Ya no requiere std::
}

void imprimirJueves(int hora) {
	cout << "Es jueves antes del mediodia." << endl; // Ya no requiere std::
}

void imprimirMartesODespues(int dia, int hora) {
	const string dias[] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" }; // Ya no requiere std::
	cout << "Es " << dias[dia] << endl; // Ya no requiere std::
	if (hora >= 12) {
		cout << "Son las " << hora << ", despues del mediodia." << endl; // Ya no requiere std::
	}
}

void cicloSemana(int diaActual) {
	const string dias[] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" }; // Ya no requiere std::

	cout << "\n Ciclo de la semana " << endl; // Ya no requiere std::
	for (int i = 0; i < 7; ++i) {
		if (i == diaActual) {
			cout << "Hoy si es " << dias[i] << "." << endl; // Ya no requiere std::
		}
		else {
			cout << "Hoy no es " << dias[i] << "." << endl; // Ya no requiere std::
		}
	}
}