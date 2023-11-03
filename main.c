#include <stdio.h>
#include "employee.h"
#include <string.h>

int main(int argc, char const *argv[])
{
    employeeList *myEmployess;

    myEmployess = initEmployeeList(myEmployess);

    if (myEmployess == NULL)
        printf("Erro de assinatura!");

    return 0;
}

char *errors(int code)
{
}
