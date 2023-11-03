#include "employee.h"

typedef struct e
{
    char *name;
    char *gender;
    short age;

} employee;

typedef struct el
{
    employee employee;
    struct employeeList *prox;

} employeeList;


