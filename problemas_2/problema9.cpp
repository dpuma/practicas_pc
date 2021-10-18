// problema 706 - LC-Display

// entrada ej:
//     3 12345
//     2 67890
//     0 0   // termina los ingresos

// salida: los numeros 12345 y 67890 dibujados

#include <iostream>
#include <vector>
using namespace std;

string crearLineaVertical(int cant, bool izq, bool der)
{
    string linea;

    if(izq) linea.push_back('|');
    else    linea.push_back(' ');

    for(int i = 0; i < cant; i++)
        linea.push_back(' ');

    if(der) linea.push_back('|');
    else    linea.push_back(' ');

    return linea;
}

string crearLineaHorizontal(int cant, bool hayLinea)
{
    string linea;
    linea.push_back(' ');

    char simbolo;
    if(hayLinea) simbolo = '-';
    else simbolo = ' ';

    for(int i = 0; i < cant; i++)
        linea.push_back(simbolo);

    linea.push_back(' ');

    return linea;
}

void crearNumero(vector<string> &matriz, char numero, int lado)
{
    string lineaHorLlena = crearLineaHorizontal(lado, true);
    string lineaHorVacia = crearLineaHorizontal(lado, false);
    string lineaVerIzq   = crearLineaVertical(lado, true, false);
    string lineaVerDer   = crearLineaVertical(lado, false, true);
    string lineaVerAmbas = crearLineaVertical(lado, true, true);

    if(numero == '0')
    {
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerAmbas);
        matriz.push_back(lineaHorVacia);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerAmbas);
        matriz.push_back(lineaHorLlena);
    }
    else if(numero == '1')
    {
        matriz.push_back(lineaHorVacia);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerDer);
        matriz.push_back(lineaHorVacia);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerDer);
        matriz.push_back(lineaHorVacia);
    }
    else if(numero == '2')
    {
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerDer);
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerIzq);
        matriz.push_back(lineaHorLlena);
    }
    else if(numero == '3')
    {
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerDer);
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerDer);
        matriz.push_back(lineaHorLlena);
    }
    else if(numero == '4')
    {
        matriz.push_back(lineaHorVacia);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerAmbas);
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerDer);
        matriz.push_back(lineaHorVacia);
    }
    else if(numero == '5')
    {
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerIzq);
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerDer);
        matriz.push_back(lineaHorLlena);
    }
    else if(numero == '6')
    {
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerIzq);
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerAmbas);
        matriz.push_back(lineaHorLlena);
    }
    else if(numero == '7')
    {
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerDer);
        matriz.push_back(lineaHorVacia);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerDer);
        matriz.push_back(lineaHorVacia);
    }
    else if(numero == '8')
    {
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerAmbas);
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerAmbas);
        matriz.push_back(lineaHorLlena);
    }
    else if(numero == '9')
    {
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerAmbas);
        matriz.push_back(lineaHorLlena);
        for(int i = 0; i < lado; i++)
            matriz.push_back(lineaVerDer);
        matriz.push_back(lineaHorLlena);
    }
}

int main()
{
    int lado;
    string numero;
    vector<int> lados;
    vector<string> numeros;
    int cont = 0;

    while(true)
    {
        cin >> lado >> numero;
        if(lado == 0 && numero == "0")
            break;
        lados.push_back(lado);
        numeros.push_back(numero);
        cont++;
    }

    for(int k = 0; k < numeros.size(); k++)
    {
        lado = lados[k];
        numero = numeros[k];

        vector<vector<string>> matNumeros;
        for(int i = 0; i < numero.size(); i++)
        {
            vector<string> matNum;
            crearNumero(matNum, numero[i], lado);
            matNumeros.push_back(matNum);
        }
        for(int i = 0; i < matNumeros[0].size(); i++)
        {
            for(int j = 0; j < numero.size(); j++)
            {
                cout << matNumeros[j][i];
                if(j+1 != matNumeros[0].size())
                    cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
