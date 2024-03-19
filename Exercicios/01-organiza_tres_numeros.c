//Faca um programa em C que leia tres numeros inteiros e exiba-os em ordem crescente. Suponha que os numeros sao distintos

#include <stdio.h>

int main(){
    int a, b, c, x;
    printf("Insira tres numeros ");
    scanf("%d %d %d", &a, &b, &c);
    
    /*Recebemos 3 numeros do teclado, devemos organiza-los em ordem crescente. 
    Para isso, faremos a troca do valor das variaveis. Sera utilizada uma variavel
    auxiliar x que vai armazenar o valor de uma das variaveis(a, b ou c). Dessa forma,
    evitamos a perda de valores que aconteceriam na atribuiçao direta. O valor de x nao
    sera relevante, visto que essa variavel apenas guarda um valor para ser atribuido
    na outra variavel. As variaveis originais receberam os valores umas das outras de
    modo que, ao fim do programa a, b e c tenham valores crescentes.*/ 
    
    if(a > c){  //Caso a > c: 
        x = c;  //x recebe o valor de c, que sera colocado em a;
        c = a;  //c recebe o valor de a, perdendo seu valor original;
        a = x;  //a recebe o valor original de c, guardado em x;
    }           //Agora os valores de a e c foram trocados.
    
    if(a > b){  //Caso a > c:
        x = b;  //x recebe o valor de b, que sera colocado em a;
        b = a;  //b recebe o valor de a, perdendo seu valor original;
        a = x;  //a recebe o valor original de b, guardado em x;
    }           //Agora os valores de a e b foram trocados.
    
    if(b > c){  //Caso b > c:
        x = c;  //x recebe o valor de c, que sera colocado em b;
        c = b;  //c recebe o valor b, perdendo seu valor original;
        b = x;  //b recebe o valor original de c, guardado em x;
    }           //Agora os valores de b e c foram trocados.
    
    //Imprimimos as variaveis a, b, c que agora possuem seus valores em ordem crescente!
    
    printf("%d %d %d", a, b, c);
    return 0;
}

