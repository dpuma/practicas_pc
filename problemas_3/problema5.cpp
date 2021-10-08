#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<string> &vec)
{
    int n = vec.size();
    int i, j;
    string key;
    for (i = 1; i < n; i++)
    {
        key = vec[i];
        j = i - 1;

        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}

vector<string> split(string frase)
{
    vector<string> vecPalabras;
    string palabra;
    for(int i = 0; i < frase.size(); i++)
    {
        if(isalpha(frase[i]))
            palabra.push_back(frase[i]);
        else {
            if(palabra.size() != 0)
                vecPalabras.push_back(palabra);
            palabra.clear();
        }
    }
    vecPalabras.push_back(palabra);
    return vecPalabras;
}

int main()
{
    string expresion;
    char c;
    while ((c =getchar ())!= EOF)
        expresion += c;

    for(int i = 0; i < expresion.size(); i++)
        expresion[i] = tolower(expresion[i]);

    vector<string> vecExpresion = split(expresion);
    vector<string> vecDiccionario;

    bool flag;
    for(int i = 0; i < vecExpresion.size(); i++)
    {
        flag = true;
        for(int j = 0; j < vecDiccionario.size(); j++) {
            if(vecExpresion[i] == vecDiccionario[j])
            {
                flag = false;
                break;
            }
        }

        if(flag)
            vecDiccionario.push_back(vecExpresion[i]);
    }
    insertionSort(vecDiccionario);
    vecDiccionario.erase(vecDiccionario.begin());

    for(int i = 0; i < vecDiccionario.size(); i++)
    {
        cout << vecDiccionario[i] << endl;
    }

    return 0;
}
