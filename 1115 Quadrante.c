#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]){
    int X, Y;
    while(scanf("%d %d", &X, &Y)){
        if(X>0 && Y>0){
            printf("primeiro\n");
        } else if( X<0 && Y>0){
            printf("segundo\n");
        } else if( X<0 && Y<0){
            printf("terceiro\n");
        } else if( X>0 && Y<0){
            printf("quarto\n");
        } else if( X==0 || Y==0){
            return 0;
        }
    }
}