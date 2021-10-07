#include<iostream>
#include<vector>
using namespace std;

void imprimir(vector<vector<int>> registros)
{
    for(int i = 0; i < registros.size(); i++)
        cout << registros[i][0] << endl;
}

void insertionSort(vector<vector<int>> &vec)
{
    int n = vec.size();
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = vec[i][0];
        j = i - 1;

        while (j >= 0 && vec[j][0] > key)
        {
            vec[j + 1][0] = vec[j][0];
            j = j - 1;
        }
        vec[j + 1][0] = key;
    }
}

int main()
{
    string str_pal, str_Q, str_P;
    int K, clock = 1;
    vector<vector<int>> registros;

    while(true)
    {
        cin >> str_pal;
        if(str_pal == "#")
            break;
        cin >> str_Q;
        cin >> str_P;

        vector<int> reg;
        reg.push_back(atoi(str_Q.c_str()));
        reg.push_back(atoi(str_P.c_str()));
        registros.push_back(reg);
    }

    cin >> K;

    vector<vector<int>> solucion;
    vector<vector<int>> aux;

    while(true)
    {
        for(int i = 0; i < registros.size(); i++)
            if(clock % registros[i][1] ==  0)
                aux.push_back(registros[i]);

        if (!aux.empty())
        {
            if(aux.size() > 1)
                insertionSort(aux);
            solucion.insert(solucion.end(), aux.begin(), aux.end());
            aux.clear();
        }

        if(solucion.size() >= K){
            break;
        }
        clock++;
    }

    imprimir(solucion);
    return 0;
}
