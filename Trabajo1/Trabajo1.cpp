#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>

//  Declaración de funciones 
void imprimirLunes();
void imprimirJueves(int hora);
void imprimirMartesODespues(int dia, int hora);
void cicloSemana(int diaActual);

//  Función principal 
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

//  Implementación de funciones 

void imprimirLunes() {
    std::cout << "Es lunes" << std::endl;
}

void imprimirJueves(int hora) {
    std::cout << "Es jueves antes del mediodia." << std::endl;
}

void imprimirMartesODespues(int dia, int hora) {
    const std::string dias[] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
    std::cout << "Es " << dias[dia] << std::endl;
    if (hora >= 12) {
        std::cout << "Son las " << hora << ", despues del mediodia." << std::endl;
    }
}

void cicloSemana(int diaActual) {
    const std::string dias[] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };

    std::cout << "\n Ciclo de la semana " << std::endl;
    for (int i = 0; i < 7; ++i) {
        if (i == diaActual) {
            std::cout << "Hoy si es " << dias[i] << "." << std::endl;
        }
        else {
            std::cout << "Hoy no es " << dias[i] << "." << std::endl;
        }
    }
}
