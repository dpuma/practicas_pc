
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<vector<int>> estudiantes;


void imprimirMat(vector<vector<int>> mat)
{
    for(int i = 0; i < mat.size(); i++)
    {
        for(int j = 0; j < mat[i].size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void imprimirVec(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

vector<int> grupos_del_estudiante(int target)
{
    vector<int> grupos;
    for(int i = 0; i < estudiantes.size(); i++) {
        for(int j = 0; j < estudiantes[i].size(); j++) {
            if(estudiantes[i][j] == target) {
                grupos.push_back(i);
                break;
            }
        }
    }
    return grupos;
}

void marcar_grupos(vector<int>&est_sospechosos, int estudiante)
{
    vector<int> grupos = grupos_del_estudiante(estudiante);
    for(int i = 0; i < grupos.size(); i++)
    {
        vector<int> grupo_actual = estudiantes[grupos[i]];
        for(int j = 0; j < grupo_actual.size(); j++)
        {
            int est = grupo_actual[j];
            if(est_sospechosos[est] == 0)
            {
                est_sospechosos[est] = 1;
            }
        }
    }

}

int main()
{
    while(true)
    {

        int cant_est, grupos;
        cin >> cant_est >> grupos;

        if(cant_est == 0 && grupos == 0)
            break;

        // inicializando matriz de estudiantes
        for(int i = 0; i < grupos; i++)
        {
            vector<int> g;
            estudiantes.push_back(g);
        }

        // ingresando datos en matriz estudiantes
        for(int i = 0; i < grupos; i++)
        {
            int n, est;
            cin >> n;
            for(int j = 0; j < n; j++)
            {
                cin >> est;
                estudiantes[i].push_back(est);
            }
        }

        // analisis de sospechosos
        vector<int> est_sospechosos(cant_est,0);
        est_sospechosos[0] = 1;

        bool flag = true;
        while(flag)
        {
            flag = true;
            for(int i = 0; i < est_sospechosos.size(); i++)
            {
                if(est_sospechosos[i] == 1)
                {
                    marcar_grupos(est_sospechosos, i);
                    est_sospechosos[i] = 2;
                    flag = false;
                }
            }
        }

        // contar sospechosos
        long acum = 0;
        for(int i = 0; i < est_sospechosos.size(); i++)
        {
            if(est_sospechosos[i]== 2)
            {
                acum++;
            }
        }
        cout << acum << endl;

        vector<vector<int>> vacio;
        estudiantes = vacio;
    }
}
