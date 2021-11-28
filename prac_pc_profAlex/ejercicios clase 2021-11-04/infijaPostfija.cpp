#include<bits/stdc++.h>
using namespace std;

int operadores(char c) {
    if(c == '^') return 3;
    else if(c == '/' || c=='*') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

void conversion(string s) {

    stack<char> pila;
    string salida;

    for(int i = 0; i < s.length(); i++) {
        char c = s[i];

        if((c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9'))
            salida += c;

        else if(c == '(')
            pila.push('(');
        else if(c == ')') {
            while(pila.top() != '(')
            {
                salida += pila.top();
                pila.pop();
            }
            pila.pop();
        }

        else {
            while(!pila.empty() &&
                  operadores(s[i]) <= operadores(pila.top())) {
                salida += pila.top();
                pila.pop();
            }
            pila.push(c);
        }
    }

    while(!pila.empty()) {
        salida += pila.top();
        pila.pop();
    }

    cout << salida << endl;
}

int main() {
    int casos;
    string expresion;
    cin >> casos;
    while(casos--)
    {
        cin >> expresion;
        conversion(expresion);
    }
    return 0;
}
