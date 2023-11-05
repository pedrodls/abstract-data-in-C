#include "employee.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Estrutura de atributos de um Funcionário
struct employee{
    char *name;
    short isActive;
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
int insertEmployee(employees* emp, char *name, char *role, float salary){
    employees *newEmployee = emp;

    if(newEmployee -> length != 0){
        newEmployee -> length++;
        //aumentando o espaço para adicionar mais um funcionário
        newEmployee -> employee = (struct employee*)realloc(newEmployee -> employee, (newEmployee -> length) * sizeof(struct employee));
    }

    if(newEmployee -> employee == NULL){ //primeiro funcionário
        newEmployee -> employee = (struct employee*)malloc(sizeof(struct employee));
        if(newEmployee ->employee != NULL) 
            newEmployee -> length = 1;
        else
            return -1;     
    }

    strcpy(newEmployee -> employee[newEmployee -> length - 1].name,name);
    strcpy(newEmployee -> employee[newEmployee -> length - 1].role,role);
    newEmployee -> employee[newEmployee -> length - 1].code = newEmployee -> length;
    newEmployee -> employee[newEmployee -> length - 1].salary = salary;
    newEmployee -> employee[newEmployee -> length - 1].isActive = 1;

    return newEmployee -> length;
}

void findAll(employees* emp){
    printf("-----------------------------------------\n");
    if(emp->length == 0)
        printf("Não Existe Funcionário\n");
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
}

void findEmployee(employees* emp, int code){ //encontra um funcionário pelo código
    short result = 0;
        for(int i = 0; i < emp->length; i++){
            if(emp->employee[i].code == code){
                printf("Nome do Funcionário (%d): %s\n", (i+1),emp->employee[i].name);
                printf("Cargo: %s\n", emp->employee[i].role);
                printf("Código: %d\n", emp->employee[i].code);
                printf("Salário: %.2f\n", emp->employee[i].salary);
                printf("Estado: %s\n", emp->employee[i].isActive ? "Activo": "Bloqueado");
                result = 1;
                break;
            }
        }
    if(!result)
        printf("Funcionário Não Existe!\n");
} 

int length(employees* emp){
    return emp -> length;
}

int updateEmployee(employees *emp, int code, char *name, char *role, float salary, int isActive){
        for(int i = 0; i < emp->length; i++){
            if(emp->employee[i].code == code){
                strcpy(emp->employee[i].name, name);
                strcpy(emp->employee[i].role, role);
                emp->employee[i].salary = salary;
                emp->employee[i].isActive = isActive;
                return 1;
            }
        }
    return 0;
}

//Desaloca a memória no fim da execução do programa
void destroy(employees **emp){
    employees *EmployeeList = *emp;

    free(EmployeeList-> employee);
    *emp = NULL;
}

