#include <stdio.h>
#include "employee.h"
#include <string.h>

void menu();

int main()
{
   int answer = 1;
   
   employees *myEmployees = create();
   if (myEmployees  == NULL){
     printf("Falha na alocação de memória!\nFechamento do Programa");
     return 0;
   }

    while(answer){

    }
    int x = insertEmployee(myEmployees, "bruno", "programador", 1, 2000);
    printf("%d\n", x);

    findAll(myEmployees);

    destroy(&myEmployees);
    return 0;
}

void menu(){
    int option;
    printf("Bem-Vindo ao Serviço de Controlo de Funcionários\n\n");
    scanf("%d",&option);
}
/*
char *errors(int code)
{
}
*/
