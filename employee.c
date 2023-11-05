#include "employee.h"
#include <stdlib.h>
#include <string.h>

struct emp{
    char *name;
    char *role;
    int code;
    float salary;
};

/*

typedef struct el
{
    employee emp;
    struct employeeList *prox;

} employeeList;

employeeList* initEmployeeList(employeeList *list){

    employee *e;

    employeeList *aux = list;

    aux->prox = e;

    return list;
}

*/
employee *createEmployee(char *name, char *role, int code, float salary){
    employee *newEmployee = (employee*)malloc(sizeof(employee));
    newEmployee->name = name;
    newEmployee->role = role;
    newEmployee->code = code;
    newEmployee->salary = salary;

    return newEmployee;
}


