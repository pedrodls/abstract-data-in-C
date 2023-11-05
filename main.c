#include <stdio.h>
#include "employee.h"
#include <string.h>

int main()
{
    //employeeList *myEmployess;
    employee *myEmployee = createEmployee("bruno","título",2,200.0);

    //myEmployess = initEmployeeList(myEmployess);

   if (myEmployee  == NULL){
     printf("Falha na alocação de memória!");
     destroy(&myEmployee);
     exit(0);
   }

    printf("Erros\n");

    destroy(&myEmployee);
    return 0;
}
/*
char *errors(int code)
{
}
*/
