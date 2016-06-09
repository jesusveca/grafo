#include <iostream>
using namespace std;
#define MAX 20

class matrix{
    private:
        int n;
        int **adjunto;
        bool *visita;
    public:
        matrix(int n){
            this->n = n;
            visita = new bool [n];
            adjunto = new int* [n];
            for (int i = 0; i < n; i++){
                adjunto[i] = new int [n];
                for(int j = 0; j < n; j++){
                    adjunto[i][j] = 0;
                }
            }
        }

        void anadir_arista(int inicio, int finall){
            if( inicio > n || finall > n || inicio < 0 || finall < 0)
                cout<<"no valido!\n";
            else{
                adjunto[inicio - 1][finall - 1] = 1;
            }
        }

        void imprimir(){
            int i,j;
            for(i = 0;i < n;i++){
                for(j = 0; j < n; j++)
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
