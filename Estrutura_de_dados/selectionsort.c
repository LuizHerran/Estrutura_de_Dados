#include <stdio.h>

int main(){

    int vet[]={10,5,1,3,7,2,4,6,8,9};
    int min, max, aux;
    int tam = sizeof(vet) / sizeof(vet[0]);

    printf("Valores originais: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\r=================================================\n");

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
printf("Valores crescentes: ");
for(int i = 0; i < tam; i++){
    printf("%d ", vet[i]);
}
printf("\r=================================================");
printf("\rValores decrescentes: ");

for(int i = 0; i < tam-1; i++){
    max=i;
    for(int j = i+1; j < tam; j++){
        if(vet[j] > vet[max]){
            max=j;
        }
    }
    if(max != i){
        aux=vet[i];
        vet[i]=vet[max];
        vet[max]=aux;
        }

}
for(int i = 0; i < tam; i++){
    printf("%d ", vet[i]);
}
printf("\r=================================================");
}
