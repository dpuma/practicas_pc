// 11687 - Digits

// entrada: numeros hasta ingresar END
// ejemplo           : 32 12 5 END

// salida: i positiva más pequeña tal que xi = xi-1
// salida del ejemplo: 3 3 2

#include <iostream>
#include <vector>
using namespace std;

void print(vector<string> vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    string num;
    vector<string> numeros;
    while(cin >> num)
    {
        if(num == "END")
            break;
        numeros.push_back(num);
    }

    int cont;
    string tmp;
    for(int i = 0; i < numeros.size(); i++)
    {
        cont = 1;
        num = numeros[i];
        while(true)
        {
            tmp = num;
            num = to_string(num.size());
            if (num == tmp)
                break;
            cont++;
        }
        cout << cont << endl;
    }
    return 0;
}
