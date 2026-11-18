// ejerercicio 4

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    int x = 30;
    int y = 12;
    
    int x_inicio = 10;
    int x_fin = 49; 
    int y_inicio = 5;
    int y_fin = 19;   

    system("cls");

    for (int i = x_inicio; i <= x_fin; i++) {
        gotoxy(i, y_inicio); cout << "-";
        gotoxy(i, y_fin); cout << "-";
    }
    for (int j = y_inicio; j <= y_fin; j++) {
        gotoxy(x_inicio, j); cout << "|";
        gotoxy(x_fin, j); cout << "|";
    }

    int tecla = 0;

    while (tecla != 27) {
        gotoxy(x_inicio, y_fin + 2);
        cout << "Posicion actual -> X: " << x << "  Y: " << y << "   ";
        gotoxy(x_inicio, y_fin + 3);
        cout << "Presiona ESC para salir. Use las flechas para mover.";

        gotoxy(x, y);
        cout << "x";

        tecla = getch();

        if (tecla == 224) {
            tecla = getch();

            gotoxy(x, y);
            cout << " ";

            if (tecla == 72 && y > (y_inicio + 1)) {
                y--;
            }
            if (tecla == 80 && y < (y_fin - 1)) {
                y++;
            }
            if (tecla == 75 && x > (x_inicio + 1)) {
                x--;
            }
            if (tecla == 77 && x < (x_fin - 1)) {
                x++;
            }
        }
    }

    gotoxy(0, y_fin + 5);
    cout << "Programa terminado." << endl;
    return 0;
}

