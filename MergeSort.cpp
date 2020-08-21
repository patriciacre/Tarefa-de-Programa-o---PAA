#include <iostream>
#include <clocale>

using namespace std;

void Merge (int vetA[], int p, int q, int r){
    int n1, n2, i, j,k;

    n1 = q - p + 1; //cálculo para comprimento do subarranjo L (esquerda)
    n2 = r - q;     //cálculo para comprimento do subarranjo R (direita)

    int vetL[n1], vetR[n2]; //novos vetores esquerda e direita

    for (i=0; i<n1; i++){
        vetL[i] = vetA[p+i]; //armazenando os valores no subarranjo da esquerda
    }
    for (j=0; j<n2; j++){
        vetR[j] = vetA[q+1+j]; //armazenando os valores no subarranjo da direita
    }
    i = 0; //início do subarranjo da esquerda
    j = 0; //início do subarranjo da direita
    k = p; //início do vetor A a ser ordenado
    while (i<n1 && j<n2){ //preenchendo e ordenando os vetores da esquerda e da direita
        if(vetL[i]<=vetR[j]){
            vetA[k] = vetL[i];
            i++;
        }else{
            vetA[k] = vetR[j];
            j++;
        }
        k++;
    }
    //no caso de o subarranjo não tiver sido todo preenchido
    //esquerda
    while (i < n1){
        vetA[k] = vetL[i];
        i++;
        k++;
    }
    //direita
    while (j < n2){
        vetA[k] = vetR[j];
        j++;
        k++;
    }
}

void mergeSort(int vetA[],int p, int r){ //p é a posição inicial do vetor e r é a posição final
    int q;
    if (p<r){
        q = (p+(r-1))/2; //encontrando o pivô
        mergeSort(vetA,p,q); //recursiva esquerda
        mergeSort(vetA,q+1,r); //recursiva direita
        Merge(vetA,p,q,r);
    }
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    int vetA[15] = {9 , 10 , -1, 3, 6, 2, 1, -3, 1, 0, -2, 15, 8, -7, 0};
    mergeSort(vetA, 0, 14);
    cout << "A= [";
    for (int a=0; a<15;a++){
        if (a == 14){
            cout<< vetA[a];
        }else{
            cout << vetA[a]<<", ";
        }
    }
    cout<< "]" << endl;

    return 0;
}
