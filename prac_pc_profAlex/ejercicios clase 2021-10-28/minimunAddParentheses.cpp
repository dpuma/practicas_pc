#include<iostream>
#include<stack>
using namespace std;

int minAddToMakeValid(string s)
{
    stack<int> pila;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
           pila.push('(');
        else if(s[i] == ')')
        {
            if(!pila.empty() && pila.top() == '(')
            {
                pila.pop();
            }
            else
                pila.push(')');
        }
    }
    int cont = 0;
    while(!pila.empty())
    {
        pila.pop();
        cont++;
    }
    return cont;
}

int main()
{
    string s;
//    s = "())";    // 1
//    s = "(()))("; // 2
//    s = "(((";    // 3
    s = "()))((";   // 4
    cout << minAddToMakeValid(s);
    return 0;
}
