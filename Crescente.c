#include <stdio.h>

int main(){
    
    int vet[]={10,8,9,3,1,2,4,6,7,5};
    int tam=sizeof(vet) / sizeof(vet[0]);
    int aux;

    for(int i = 0; i <= (tam-1); i++){
        for(int k = 0; k<= (tam-2); k++){
            if(vet[k] > vet[k+1]){
                aux=vet[k];
                vet[k] = vet[k+1];
                vet[k+1]=aux;
            }
        }
    }
for(int j = 0; j <= (tam-1); j++){
    printf("%d ", vet[j]);
}
printf("\r\nFim");
}