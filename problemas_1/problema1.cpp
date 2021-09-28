#include<iostream>
using namespace std;

int main()
{
    int pos = 0;
    string frase;
    while(getline(cin,frase))
    {
        for(int i = 0; i < frase.size(); i++)
        {
            if(frase[i]=='"')
            {
                frase.erase(i,1);
                if (pos == 0)
                {
                    frase.insert(i,"``");
                    pos++;
                }
                else if(pos == 1)
                {
                    frase.insert(i,"''");
                    pos--;
                }
                i++;
            }
        }
        cout << frase << endl;
    }
    return 0;
}
