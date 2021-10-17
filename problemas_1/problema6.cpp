/***
Entrada
La primera linea de entrada da el número de casos de prueba, 1 <= t <= 100.
Hay dos líneas para cada caso de prueba caso de prueba. La primera da el número de tiendas
que Michael quiere visitar, 1 <= n <= 20, y la segunda da sus n posiciones enteras en la calle Larga, 0 <= xi <= 99.

Salida
Salida para cada caso de prueba una línea con la distancia minima que Miguel debe caminar dado el estacionamiento optimo
***/
#include <iostream>
using namespace std;

int main()
{
	int casos, n, minimo, maximo, dato1, dato2, d;
	cin >> casos;

	while(casos--)
    {
        cin >> n;
        if (n == 1)
        {
            cin >> d;
            cout << 0 << endl;
        }
        else
        {
            cin >> dato1 >> dato2;
            if(dato1 < dato2)
            {
                minimo = dato1;
                maximo = dato2;
            } else {
                minimo = dato2;
                maximo = dato1;
            }

            for(int i = 2; i < n; i++)
            {
                cin >> d;
                if (d > maximo)
                    maximo = d;
                else if(d < minimo)
                    minimo = d;
            }
            cout << (maximo-minimo)*2 << endl;
        }
    }
	return 0;
}
