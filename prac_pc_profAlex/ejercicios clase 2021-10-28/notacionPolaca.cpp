#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<vector>
#include<stack>
using namespace std;

int evalRPN(vector<string>& tokens)
{
    stack<int> pila;
    int op1, op2, sol;
    for(int i = 0; i < tokens.size(); i++)
    {
        if(isdigit(tokens[i][0]) || tokens[i].size() > 1)
            pila.push( atoi(tokens[i].c_str()) );
        else
        {
            op1 = pila.top();
            pila.pop();
            op2 = pila.top();
            pila.pop();
            if(tokens[i][0] == '+')
                sol = op2 + op1;
            else if(tokens[i][0] == '-')
                sol = op2 - op1;
            else if(tokens[i][0] == '*')
                sol = op2 * op1;
            else if(tokens[i][0] == '/')
                sol = op2 / op1;
            pila.push(sol);
        }
    }
    return pila.top();
}

int main()
{
    vector<string> tokens;
//    tokens = {"2","1","+","3","*"};
//    tokens = {"4","13","5","/","+"};
    tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << evalRPN(tokens);
    return 0;
}
