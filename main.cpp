/*============================================================
*           Algoritmo implementado por Guilherme Kollet
*           Graduando em Eng. da Computação
*
*           Algoritmo de pesquisa binária, procura por
*           um valor em um conjunto de elementos com
*           complexidade O(log n) .
* ============================================================*/

#include <iostream>
#include <array>
using namespace std;

bool buscaBinaria(int v, int vet[],int tam, bool log){

    int low = 0;
    int high = tam-1;
    int posicao = 0;

    cout << "\n  Valor a ser pesquisado: "<< v << endl;
    cout << "  Quantidade de itens no vetor: " << tam << endl << endl;

    while (low <= high){

        int m = (low+high)/2; //calculo cérebro
        //low é sempre o zero, enquanto ele for menor ou igual o valor encontrado

        if (log == true) cout << "  Index: " << m << endl;
        if (log == true) cout << "  O valor do vetor nessa posicao: " << vet[m] << endl << endl;

        ///if de validade
        if (v == vet[m]){

            posicao++;

            if ( log == true ){
                cout << " - Valor encontrado!" << endl << endl;
                cout << "  checked " << v << "  ==  " << vet[m] << endl << endl;
                }
                cout << "  \aQuantidade de buscas percorridas: " << posicao << endl;
                return true;

        ///if de modificação para validar

        } else if (v < vet[m]){ //se o valor for menor que o elemento

                if (log == true){
                    cout << "  checked " << v << " <  " << vet[m] << endl << endl;
                }

                high = m-1; //diminua o index do cálculo

        } else {
                if (log == true){
                    cout << "  checked " << v << "  >  " << vet[m] << endl << endl;
                }

            low = m+1;
        }
        posicao++;

    }
return false;
}

int main(){
///atributos disponíveis à modificação

int valor = 3; //pesquisar
bool log = true; //exibir texto
int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};

///atributos que não devem ser modificados

int tam = sizeof(A)/sizeof(int); //cálculo do tamanho do array (não mexer)
bool busca_return = buscaBinaria(valor, A, tam, log); //valor a ser pesquisado, vetor inteiro passado, tamanho do vetor calculado e comando de exibição de texto.

///tratamento do retorno da function
if (busca_return == true) {

    cout << "\n  Valor encontrado no Array" << endl;

} else {

    cout << "\n  Valor inexistente no Array" << endl;

    return 0;

    }
}
