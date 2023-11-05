#include "employee.h"
#include <stdlib.h>
#include <stdio.h>


//Estrutura de atributos de um Funcionário
struct employee{
    char *name;
    short* isActive;
    char *role;
    int code;
    float salary;
};
//definição da struct Funcionários (atributos) - Vetor de Funcionários
struct Employees{
    int length;
    struct employee *employee;
};

//Método para Alocação da Memória da TAD de Funcionário
employees *create(){
    employees *newEmployeeList = (employees*)malloc(sizeof(employees));
    newEmployeeList->length = 0;
    newEmployeeList -> employee = NULL;

    return newEmployeeList;
}

//Método para inserção de um Funcionário
int insertEmployee(employees* emp, char *name, char *role, int code, float salary){
    employees *newEmployee = emp;

    if(newEmployee -> employee == NULL){ //primeiro funcionário
        newEmployee -> employee = (struct employee*)malloc(sizeof(struct employee));
        if(newEmployee ->employee != NULL) 
            newEmployee -> length = 1;
        else
        return -1;     
    }

    if(newEmployee -> length != 1){
        newEmployee -> length++;
        //aumentando o espaço para adicionar mais um funcionário
        newEmployee -> employee = (struct employee*)realloc(newEmployee -> employee, newEmployee -> length * sizeof(struct employee));
    }

    newEmployee -> employee[newEmployee -> length - 1].name = name;
    newEmployee -> employee[newEmployee -> length - 1].role = role;
    newEmployee -> employee[newEmployee -> length - 1].code = code;
    newEmployee -> employee[newEmployee -> length - 1].salary = salary;
    newEmployee -> employee[newEmployee -> length - 1].isActive = 1;


    return newEmployee -> length;
}

void findAll(employees* emp){
    for(int i = 0; i < emp->length; i++){
        if(emp->employee[i].isActive){
            printf("Nome do Funcionário (%d): %s\n", (i+1),emp->employee[i].name);
            printf("Cargo: %s\n", emp->employee[i].role);
            printf("Código: %d\n", emp->employee[i].code);
            printf("Salário: %.2f\n", emp->employee[i].salary);
        }else{
           printf("Código: %d (Bloqueado)\n", emp->employee[i].code);
        }
    }
    printf("-----------------------------------------\n");
}

int length(employees* emp){
    return emp -> length;
}
//Método para encontrar um funcionário apartir do seu código
/*employees* findEmployee(int code){

}*/

//Desaloca a memória no fim da execução do programa
void destroy(employees **emp){
    employees *EmployeeList = *emp;

    free(EmployeeList-> employee);
    *emp = NULL;
}

