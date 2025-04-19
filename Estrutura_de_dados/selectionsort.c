#include <stdio.h>

int main(){

    int vet[]={10,5,1,3,7,2,4,6,8,9};
    int min, aux;
    int tam = sizeof(vet) / sizeof(vet[0]);

    for(int i = 0; i < tam-1; i++){
        min=i;
        for(int j = i+1; j < tam; j++){
            if(vet[j] < vet[min]){
                min=j;
            }
        }
        if(min != i){
            aux=vet[i];
            vet[i]=vet[min];
            vet[min]=aux;
            }

    }
for(int i = 0; i < tam; i++){
    printf("%d ", vet[i]);
}
}