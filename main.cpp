#include <iostream>
using namespace std;

class matrix{
    private:
        int nodos;
        int **adjunto;
        bool *visita;
    public:
        matrix(int nodos){
            this->nodos = nodos;
            visita = new bool [nodos];
            adjunto = new int* [nodos];
            for (int i = 0; i < nodos; i++){
                adjunto[i] = new int [nodos];
                for(int j = 0; j < nodos; j++){
                    adjunto[i][j] = 0;
                }
            }
        }

        void anadir_arista(int inicio, int finall){
            if( inicio > nodos || finall > nodos || inicio < 0 || finall < 0)
                cout<<"no valido!\n";
            else{
                adjunto[inicio - 1][finall - 1] = 1;
            }
        }

        void imprimir(){
            int i,j;
            for(i = 0;i < nodos;i++){
                for(j = 0; j < nodos; j++)
                    cout<<adjunto[i][j]<<"  ";
                cout<<endl;
            }
        }
};

int main()
{
    int nodos, max_aristas, parar1, parar2;
    nodos=5;
    matrix grafito(nodos);
    max_aristas = nodos * (nodos - 1);
    for (int i = 0; i < max_aristas; i++){
        cout<<"ingrese arista : ";
        cin>>parar1>>parar2;
        if((parar1 == -1) && (parar2 == -1))
            break;
        grafito.anadir_arista(parar1, parar2);
    }
    cout<<endl;
    grafito.imprimir();
    return 0;
}
