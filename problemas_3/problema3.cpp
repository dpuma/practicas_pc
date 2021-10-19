#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    vector<string> vecSimbolos;
    string simbolos;
    stack<char> pila;
    int casos;
    cin >> casos;

    getchar();
    for(int j = 0; j < casos; j++)
    {
        getline(cin, simbolos);
        vecSimbolos.push_back(simbolos);
    }

    for(int i = 0; i < casos; i++)
    {
        simbolos = vecSimbolos[i];
        bool flag = true;

        for(int i = 0; i < simbolos.size(); i++)
        {
            if(simbolos[i]=='(' || simbolos[i]=='[')
                pila.push(simbolos[i]);

            else if (simbolos[i]==')')
            {
                if (!pila.empty() && pila.top() == '(') {
                    pila.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
            else if (simbolos[i]==']')
            {
                if(!pila.empty() && pila.top() == '[') {
                    pila.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        if(flag == true && pila.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

        while(!pila.empty())
            pila.pop();
    }
    return 0;
}
