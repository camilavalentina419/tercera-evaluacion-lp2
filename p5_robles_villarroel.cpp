/*Realice un programa que, usando la metodología mostrada en clase 
(for anidados + gotoxy + condicionales), grafique el año de nacimiento de cada integrante.
Lea los dos años (1950 a 2012) y el tamaño n de las cifras (5 a 7), 
y dibuje cada cifra con # en un cuadro de $n \times n$, al estilo de un display de siete segmentos,
con un año debajo del otro. Los rótulos «Integrante 1» e «Integrante 2» se muestran 
con cout sobre cada año (no se grafican letra por letra). Puede emplear funciones para este 
ejercicio.*/




#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void dibujarDigito(int d, int x, int y, int n) {
    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            bool encendido = false;
            int mitad = n / 2;

            
            if (d == 0) {
                if (i == 0 || i == n - 1 || j == 0 || j == n - 1) encendido = true;
            } else if (d == 1) {
                if (j == n - 1) encendido = true;
            } else if (d == 2) {
                if (i == 0 || i == mitad || i == n - 1 || (j == n - 1 && i < mitad) || (j == 0 && i > mitad)) encendido = true;
            } else if (d == 3) {
                if (i == 0 || i == mitad || i == n - 1 || j == n - 1) encendido = true;
            } else if (d == 4) {
                if (i == mitad || j == n - 1 || (j == 0 && i < mitad)) encendido = true;
            } else if (d == 5) {
                if (i == 0 || i == mitad || i == n - 1 || (j == 0 && i < mitad) || (j == n - 1 && i > mitad)) encendido = true;
            } else if (d == 6) {
                if (i == 0 || i == mitad || i == n - 1 || j == 0 || (j == n - 1 && i > mitad)) encendido = true;
            } else if (d == 7) {
                if (i == 0 || j == n - 1) encendido = true;
            } else if (d == 8) {
                if (i == 0 || i == mitad || i == n - 1 || j == 0 || j == n - 1) encendido = true;
            } else if (d == 9) {
                if (i == 0 || i == mitad || i == n - 1 || j == n - 1 || (j == 0 && i < mitad)) encendido = true;
            }

            if (encendido) {
                gotoxy(x + j, y + i);
                cout << "#";
            }
        }
    }
}

int main() {
    char opcion;
    do {
        system("cls");
        int anio1, anio2, n;

        cout << "Ingrese el year de nacimiento del Integrante 1 (1950 - 2012): ";
        while (!(cin >> anio1) || anio1 < 1950 || anio1 > 2012) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Ingrese el año del Integrante 1 (1950 - 2012): ";
        }

        cout << "Ingrese el year de nacimiento del Integrante 2 (1950 - 2012): ";
        while (!(cin >> anio2) || anio2 < 1950 || anio2 > 2012) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Ingrese el año del Integrante 2 (1950 - 2012): ";
        }

        cout << "Ingrese el tamaño n de las cifras (5 a 7): ";
        while (!(cin >> n) || n < 5 || n > 7) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Ingrese el tamaño n (5 a 7): ";
        }

        system("cls");

        // Integrante 1
        gotoxy(5, 1);
        cout << "Integrante 1";
        
        int d1_1 = anio1 / 1000;
        int d1_2 = (anio1 / 100) % 10;
        int d1_3 = (anio1 / 10) % 10;
        int d1_4 = anio1 % 10;

        dibujarDigito(d1_1, 5, 3, n);
        dibujarDigito(d1_2, 5 + n + 1, 3, n);
        dibujarDigito(d1_3, 5 + 2 * (n + 1), 3, n);
        dibujarDigito(d1_4, 5 + 3 * (n + 1), 3, n);

        // Integrante 2
        int y_segundo = 3 + n + 2;
        gotoxy(5, y_segundo);
        cout << "Integrante 2";

        int d2_1 = anio2 / 1000;
        int d2_2 = (anio2 / 100) % 10;
        int d2_3 = (anio2 / 10) % 10;
        int d2_4 = anio2 % 10;

        dibujarDigito(d2_1, 5, y_segundo + 2, n);
        dibujarDigito(d2_2, 5 + n + 1, y_segundo + 2, n);
        dibujarDigito(d2_3, 5 + 2 * (n + 1), y_segundo + 2, n);
        dibujarDigito(d2_4, 5 + 3 * (n + 1), y_segundo + 2, n);

        gotoxy(5, y_segundo + n + 4);
        cout << "Repetir (s/n)?: ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    return 0;
}
