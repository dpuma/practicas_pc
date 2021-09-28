#include <iostream>
using namespace std;

int main()
{
    int casos, filas, columnas, i;
    cin >> casos;


    for(i = 0; i < casos; i++)
    {
        cin >> filas >> columnas;
        cout << (filas/3)*(columnas/3) << endl;
    }
    return 0;
}
