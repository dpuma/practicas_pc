#include <iostream>
#include <vector>

using namespace std;

bool pertenece(vector<int> vec, int elemento)
{
    for(int i=0; i<vec.size(); i++){
        if(elemento == vec[i])
            return true;
    }
    return false;
}

int mayor(vector<int> personas){
    vector<int> grupos;
    for(int i=1; i<personas.size(); i++){
        if(!pertenece(grupos, personas[i])){
            grupos.push_back(personas[i]);
        }
    }

    vector<int> aux(grupos.size(),0);
    for(int i=0; i<grupos.size(); i++){
        for(int j=1; j<personas.size(); j++){
            if(grupos[i]==personas[j]){
                aux[i]=aux[i]+1;
            }
        }
    }

    int maxi=0;
    for(int i=0; i<aux.size(); i++){
        if(aux[i]>maxi){
            maxi=aux[i];
        }
    }
    return maxi;
}

int main()
{
    int casos;
    cin>>casos;

    while (casos--)
    {
        int N, M, A, B;
        cin>>N>>M;
        if(M==0){
            if(N==0)
                cout << 0 << endl;
            else
                cout << 1 << endl;
            continue;
        }
        vector<int> personas(N+1,-1);
        int cont = 1;

        for(int i=0; i<M; i++)
        {
            cin>>A>>B;
            if(personas[A] == -1){ //A no tiene
                if(personas[B] == -1){  //B no tiene
                    personas[A]=cont;
                    personas[B]=cont;
                    cont++;
                }else{  // B tiene
                    personas[A]=personas[B];//A marca con B
                }
            }else{  // A tiene
                if(personas[B]==-1){ // B no tiene
                    personas[B] = personas[A];
                }else{//B tiene
                    if(personas[A] != personas[B]){  // son distintos
                        for(int j=1; j<=personas.size(); j++){
                            if(personas[j] == personas[B]){
                                personas[j] = personas[A];
                            }
                        }
                    }
                }
            }
        }
        cout<<mayor(personas)<<endl;
    }
    return 0;
}
