#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int casos, vertices, aristas, posV1, posV2, contGrupos, tmp;
    char v1, v2;
    cin >> casos;
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    vector<int> grupos(alfabeto.size(), 0);

    for(int k = 0; k < casos; k++)
    {
        cin >> vertices >> aristas;
        contGrupos = 1;
        for(int i = 0; i < aristas; i++)
        {
            cin >> v1 >> v2;
            posV1 = alfabeto.find(v1);
            posV2 = alfabeto.find(v2);


            if(grupos[posV1] && !(grupos[posV2]))
                grupos[posV2] = grupos[posV1];
            else if(grupos[posV1] && grupos[posV2])
            {
                tmp = grupos[posV2];
                for(int j = 0; j < vertices; j++)
                {
                    if(grupos[j] == tmp)
                        grupos[j] = grupos[posV1];
                }
            }
            else if(!(grupos[posV1]) && grupos[posV2])
                grupos[posV1] = grupos[posV2];
            else if(!(grupos[posV1]) && !(grupos[posV2])) {
                grupos[posV1] = contGrupos;
                grupos[posV2] = contGrupos;
                contGrupos++;
            }
        }
        for(int i = 0; i < vertices; i++)
        {
            if(grupos[i] == 0)
            {
                grupos[i] = contGrupos;
                contGrupos++;
            }
        }

        cout << "Case #" << k+1 << ":" << endl;
        bool fin = true;
        int cont = 0;
        int actual = 0;
        while(true)
        {
            int i, j;
            for(i = 0; i < grupos.size(); i++)
            {
                if(actual == 0 && grupos[i] != 0)
                {
                    actual = grupos[i];
                    cout << alfabeto[i] << ",";
                    grupos[i] = 0;
                    cont++;
                    fin = false;
                    break;
                }
            }
            if(fin == true)
            {
                cout << cont << " connected components\n\n";
                break;
            }
            for(j = i; j < grupos.size(); j++)
            {
                if(grupos[j] == actual)
                {
                    cout << alfabeto[j] << ",";
                    grupos[j] = 0;
                }

            }
            cout << endl;
            fin = true;
            actual = 0;
        }
    }
    return 0;
}
