#include<iostream>
#include<vector>
using namespace std; 

void printMat(vector<string> matriz)
{
    for(int i = 0; i < matriz.size(); i++)
    {
        for(int j = 0; j < matriz[0].size(); j++)
        {
            cout << matriz[i][j];
        }
        cout << endl;
    }
}


int main()
{
    int fil, col; 
    int i, j, p, q;
    int acum = 0, cont = 1;

    while(true)
    {
    cin >> fil >> col;
    vector<string> matriz(fil,"");
    for(int i = 0; i < fil; i++)
        cin >> matriz[i];

    cout << "Field #" << cont++ << ":" << endl;

    for(i =0; i < matriz.size(); i++)
    {
        for(j = 0; j < matriz[0].size(); j++)
        {
            if (matriz[i][j] == '*') continue;
            for(p = i-1; p <=(i+1); p++)
            {
                if(p<0 || p >= matriz.size()) continue;
                for(q = j-1; q <=(j+1); q++)
                {
                    if(q<0 || q>=matriz[0].size()) continue;
                    if(matriz[p][q]=='*')
                        acum++;
                }
            }
            matriz[i][j]=acum+'0';
            acum = 0;
        }
    }
    printMat(matriz);
    }
    return 0;
}