#include <stdio.h>
#include "employee.h"
#include <string.h>

int main()
{
   
    employees *myEmployees = create();

   if (myEmployees  == NULL){
     printf("Falha na alocação de memória!");
     return 0;
   }

    printf("Erros\n");


    destroy(&myEmployees);
    return 0;
}

/*
char *errors(int code)
{
}
*/
