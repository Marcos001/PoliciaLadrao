#include <iostream>
#define n 5

using namespace std;

typedef struct vetor{
    int matriz[n][n];
}array;

bool seguro(array vez[], int indice, int linha, int coluna){

    return vez[indice].matriz[linha][coluna] == 0;
}

bool movimento_policia(array vez[], int indice, int linha, int coluna){

    if (vez[indice].matriz[4][4] == 1){ // chegou onde esta os bandidos
            return true;
    }

    for (int i = linha; i < n; ++i) {
        for (int j = coluna; j < n; ++j) {
            if (seguro(vez, indice,i, j)){
                //cout << "seguro movimento em ["<<i<<"]["<<j << "] = " << vez[indice].matriz[i][j] << endl;
                vez[indice].matriz[i][j] = 1;
                bool sucesso = movimento_policia(vez, indice, i,j);
                if(sucesso)
                    return true;
                else
                    return movimento_policia(vez, indice, i, j);
            }
        }
    }

    return false;
}


int main() {

    int T = 0;
    array v[10];

    cin>>T;
    int indice = 0;

    while (indice < T){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>v[indice].matriz[i][j];
            }
        }
        indice +=1;
    }
    //cout << "matirz "<< indice <<" preencida" << endl;
    /**
     * 0 0 0 0 1
       1 1 0 0 1
       0 1 0 0 0
       0 0 0 1 1
       1 1 0 0 0
     *
     * */

    for (int k = 0; k < indice; ++k) {
        if (movimento_policia(v, indice, 0, 0))
            cout << "COPS" << endl;
        else
            cout << "ROBBERS" << endl;
    }


    return 0;
}