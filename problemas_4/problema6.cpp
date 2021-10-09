#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;

int prioridad(char c)
{
   if(c == '*' || c == '/') return 1;
   else if(c == '+' || c == '-') return 0;
}

string crearPostfija(string infija)
{
    string postfija;
    stack<char> pila;

    pila.push('(');

    for(int i = 0; i < infija.size(); i++)
    {
        if(isdigit(infija[i]))
            postfija.push_back(infija[i]);
        else {
            if (infija[i] == '(')
                pila.push('(');
            else if(infija[i] == ')')
            {
                while(pila.top() != '(')
                {
                    postfija.push_back(pila.top());
                    pila.pop();
                }
                pila.pop();
            }
            else // es un operador
            {
                if(pila.top() == '(' )
                    pila.push(infija[i]);
                else if(prioridad(infija[i]) <= prioridad(pila.top()))
                {
                    postfija.push_back(pila.top());
                    pila.pop();
                    pila.push(infija[i]);
                }
                else
                    pila.push(infija[i]);
            }
        }
    }
    while(pila.top() != '(')
    {
        postfija.push_back(pila.top());
        pila.pop();
    }
    return postfija;
}

int main()
{
    int n;
    cin >> n;
    cout << endl;
    getchar();

    vector<string> respuestas;
    while(n)
    {
        char c[4];
        string infija;
        while(true)
        {
            gets(c);
            if(strlen(c))
                infija.push_back(c[0]);
            else
                break;
        }
        string postfija = crearPostfija(infija);

        respuestas.push_back(postfija);
        n--;
    }

    int i;
    for(i = 0; i < respuestas.size()-1; i++)
        cout << respuestas[i] << " ";
    cout << respuestas[i];

    return 0;
}
