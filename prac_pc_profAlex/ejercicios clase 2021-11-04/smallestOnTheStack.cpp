#include<iostream>
#include<stack>
using namespace std;

void printPila(stack<int> pila)
{
    while(!pila.empty())
    {
        cout << pila.top();
        pila.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> pila;
    string instruccion;
    int num, casos ;
    cin >> casos;
    while(casos--)
    {
        cin >> instruccion;
        if(instruccion == "PUSH")
        {
            cin >> num;
            pila.push(num);
        }
        else if(instruccion == "POP")
        {
            pila.pop();
        }
        else if(instruccion == "MIN")
        {
            stack<int> copia = pila;
            int minimo;
            if(!copia.empty())
            {
                minimo = copia.top();
                copia.pop();
            }
            else
            {
                cout << "EMPTY" << endl;
                continue;
            }
            while(!copia.empty())
            {
                if(copia.top() < minimo)
                {
                    minimo = copia.top();
                }
                copia.pop();
            }
            cout << minimo << endl;
        }
    }

    return 0;
}
