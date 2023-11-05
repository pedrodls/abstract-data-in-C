#include "employee.h"
#include <stdlib.h>
#include <string.h>

//definição da struc Employee (atributos)
struct Employee{
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

//Método para criação de um Funcionário
employee *createEmployee(char *name, char *role, int code, float salary){
    employee *newEmployee = (employee*)malloc(sizeof(employee));
    newEmployee->name = name;
    newEmployee->role = role;
    newEmployee->code = code;
    newEmployee->salary = salary;

    return newEmployee;
}

void destroy(employee **emp){
    employee *dataEmployee = *emp;

    free(dataEmployee);
    *emp = NULL;
}

