/*Realice un conversor de divisas: lea al inicio la tasa del dólar y la del euro en bolívares 
(mayores que 0) y muestre un menú: 1. $ a Bs, 2. Bs a $, 3. € a Bs, 4. Bs a €, 5. Salir[cite: 1]. 
Cada conversión debe hacerse con una función que reciba el monto y la tasa y 
devuelva el resultado[cite: 1]. Muestre los montos con dos decimales; 
use al menos dos secuencias de escape y un operador ternario[cite: 1]. 
Ejemplos: tasa del dólar 45: 20 $ $\rightarrow$900.00 Bs y 900 Bs$\rightarrow$20.00$; 
tasa del euro 50: 10 € $\rightarrow$ 500.00 Bs; un monto negativo y la opción 9 deben
rechazarse[cite: 1].*/



#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

double divisaABs(double monto, double tasa) {
    return monto * tasa;
}

double bsADivisa(double monto, double tasa) {
    return monto / tasa;
}

int main() {
    double tasaDolar, tasaEuro;

    cout << "Ingrese la tasa del dolar en Bs (> 0): ";
    while (!(cin >> tasaDolar) || tasaDolar <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. Ingrese una tasa valida (> 0): ";
    }

    cout << "Ingrese la tasa del euro en Bs (> 0): ";
    while (!(cin >> tasaEuro) || tasaEuro <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. Ingrese una tasa valida (> 0): ";
    }

    int opcion;
    do {
        system("cls");
        cout << "=== CONVERSOR DE DIVISAS ===\n\n";
        cout << "\t1. $ a Bs\n";
        cout << "\t2. Bs a $\n";
        cout << "\t3. EUR a Bs\n";
        cout << "\t4. Bs a EUR\n";
        cout << "\t5. Salir\n\n";
        cout << "Seleccione una opcion (1-5): ";

        while (!(cin >> opcion) || opcion < 1 || opcion > 5) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opcion rechazada. Ingrese una opcion valida (1-5): ";
        }

        if (opcion != 5) {
            double monto, resultado;
            cout << "\nIngrese el monto a convertir (>= 0): ";
            while (!(cin >> monto) || monto < 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Monto rechazado. Ingrese un monto valido (>= 0): ";
            }

            double tasaActual = (opcion == 1 || opcion == 2) ? tasaDolar : tasaEuro;

            cout << fixed << setprecision(2);

            switch (opcion) {
                case 1:
                    resultado = divisaABs(monto, tasaActual);
                    cout << "\nResultado: " << monto << " $ -> " << resultado << " Bs\n\n";
                    break;
                case 2:
                    resultado = bsADivisa(monto, tasaActual);
                    cout << "\nResultado: " << monto << " Bs -> " << resultado << " $\n\n";
                    break;
                case 3:
                    resultado = divisaABs(monto, tasaActual);
                    cout << "\nResultado: " << monto << " EUR -> " << resultado << " Bs\n\n";
                    break;
                case 4:
                    resultado = bsADivisa(monto, tasaActual);
                    cout << "\nResultado: " << monto << " Bs -> " << resultado << " EUR\n\n";
                    break;
            }
            system("pause");
        }

    } while (opcion != 5);

    return 0;
}
