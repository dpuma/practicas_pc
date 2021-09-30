#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string simbolos;
    stack<char> pila;
    int casos;
    cin >> casos;

    for(int j = 0; j < casos; j++)
    {
        cin >> simbolos;
        bool flag = true;

        for(int i = 0; i < simbolos.size(); i++)
        {
            if(simbolos[i]=='(' || simbolos[i]=='[')
                pila.push(simbolos[i]);
            if(simbolos[i]==')')
            {
                if (pila.top() == '(' && !pila.empty()) {
                    pila.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
            else if (simbolos[i]==']')
            {
                if(pila.top() == '[' && !pila.empty()) {
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
    }

    return 0;
}
