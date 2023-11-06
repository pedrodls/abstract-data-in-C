#include "employee.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Estrutura de atributos de um Funcionário
struct employee{
    char name[30];
    int isActive;
    char role[20];
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
int insertEmployee(employees* emp, char *name, char *role, float salary, int isActive){
    employees *newEmployee = emp;

    if(newEmployee -> length != 0){
        newEmployee -> length++;
        //aumentando o espaço para adicionar mais um funcionário
        newEmployee -> employee = (struct employee*)realloc(newEmployee->employee, (newEmployee -> length) * sizeof(newEmployee->employee));
    }

    if(newEmployee -> employee == NULL){ //primeiro funcionário
        newEmployee -> employee = (struct employee*)malloc(sizeof(struct employee));
        if(newEmployee ->employee != NULL) 
            newEmployee -> length = 1;
        else
            return -1;     

    }

    strcpy(newEmployee -> employee[newEmployee -> length - 1].name, name);
    strcpy(newEmployee -> employee[newEmployee -> length - 1].role, role);
    newEmployee -> employee[newEmployee -> length - 1].code = newEmployee -> length;
    newEmployee -> employee[newEmployee -> length - 1].salary = salary;
    newEmployee -> employee[newEmployee -> length - 1].isActive = isActive;

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
        printf("-----------------------------------------\n\n");
    }
}

void findEmployee(employees* emp, int code){ //encontra um funcionário pelo código
    int result = 0;
        for(int i = 0; i < emp->length; i++){
            if(emp->employee[i].code == code){
                printf("Nome do Funcionário (%d): %s\n", (i+1),emp->employee[i].name);
                printf("Cargo: %s\n", emp->employee[i].role);
                printf("Código: %d\n", emp->employee[i].code);
                printf("Salário: %.2f\n", emp->employee[i].salary);
                printf("Estado: %s\n", (emp->employee[i].isActive) == 1 ? "Activo": "Bloqueado");
                result = 1;
                break;
            }
        }
    if(!result)
        printf("Funcionário Não Existe!\n");

    printf("-----------------------------------------\n\n");

} 

//guarda a quantidade de funcionários
int length(employees* emp){
    return emp -> length;
}
//Métodos Get da Função
char* getName(employees *emp, int index){ //retorna o nome do funcionário
    return emp->employee[index].name;
}
char* getRole(employees *emp, int index){ //retorna o cargo do funcionário
    return emp->employee[index].role;
}
float getSalary(employees *emp, int index){//retorna o salario do funcionário
    return emp->employee[index].salary;
}
int getCode(employees *emp, int index){ //retorna o codigo do funcionário
    return emp->employee[index].code;
}
int getIsActive(employees *emp, int index){ //retorna o estado do funcionário
    return emp->employee[index].isActive;
}

//actualiza os dados de um funcionário específico
int updateEmployee(employees *emp, int code, char *name, char *role, float salary, int isActive){
        for(int i = 0; i < emp->length; i++){
            if(emp->employee[i].code == code){
                strcpy(emp->employee[i].name, name);
                strcpy(emp->employee[i].role, role);
                emp->employee[i].salary = salary;
                emp->employee[i].isActive = 1;
                return 1; //sucesso
            }
        }
    return 0; //falha
}

int getIndex(employees *emp, int code){ //retorna o índice do funcionário do código enviado
        for(int i = 0; i < emp->length; i++){
            if(emp->employee[i].code == code)
                return i;            
        }
    return -1;
} 

int block(employees *emp, int code){//inactiva um funcionário
    int index = getIndex(emp, code);
    if(index == -1) return 0;
    emp -> employee[index].isActive = 0;
    return 1;
} 
int enable(employees *emp, int code){ //activa um funcionário
    int index = getIndex(emp, code);
    if(index == -1) return 0;
    emp -> employee[index].isActive = 1;
    return 1;
}
//Desaloca a memória no fim da execução do programa
void destroy(employees **emp){
    employees *EmployeeList = *emp;

    free(EmployeeList-> employee);
    *emp = NULL;
}

