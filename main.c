#include <stdio.h>
#include "employee.h"
#include <string.h>

int main()
{
    //employeeList *myEmployess;
    employee *funcionario = createEmployee("bruno","título",2,200.0);

    //myEmployess = initEmployeeList(myEmployess);

   if (funcionario  == NULL)
     printf("Erro de assinatura!");

    printf("Erros\n");
    return 0;
}
/*
char *errors(int code)
{
}
*/
