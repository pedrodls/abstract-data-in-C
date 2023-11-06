#include <stdio.h>
#include "employee.h"
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int menu(employees *emp);
int insert(employees *emp);
int update(employees *emp, int code, int index);

int main()
{
   int answer = 1, option;
   setlocale(LC_ALL, "pt-br");
   employees *myEmployees = create();
   if (myEmployees  == NULL){
     printf("Falha na alocação de memória!\nFechamento do Programa");
     return 0;
   }

    while(answer){
        option = menu(myEmployees);
        switch(option){
            case 0: answer = 0; break;
            case 1: 
                findAll(myEmployees);
            break;
            case 2:
                insert(myEmployees) == -1 ? printf("Falha ao Inserir Funcionário\n") : printf("Funcionário de código %d inserido\n!", answer);
            break;
            case 3:
                int code_3;
                printf("Código: ");
                scanf("%d",&code_3);
                findEmployee(myEmployees, code_3);
            ;break;
            case 4:
                int code_4;
                printf("Código: ");
                scanf("%d",&code_4);
                int index = getIndex(myEmployees,code_4);
                if(index == -1) printf("Funcionário não Encontrado!\n");
                else 
                    update(myEmployees, code_4, index) ? printf("Funcionário (%d) Actualizado!\n",code_4) : printf("Falha ao Actualizar!\n");
            ;break;
            default:
                printf("Opção Inválida");
            ;break;
        }
    }
    //int x = insertEmployee(myEmployees, "bruno", "programador", 1, 2000);

    destroy(&myEmployees);
    return 0;
}


int menu(employees *emp){
    int option;
     printf("Bem-Vindo ao Serviço de Controlo de Funcionários\n\n");
     printf("oooooooooooooooooooooooooooooooooooooooooooooooo\n");
	 printf(" Quantidade de Funcionários: %d\n\n",length(emp));
	 printf("|1 - Ver Funcionários                          |\n");
     printf("|2 - Inserir Funcionários                      |\n");
     printf("|3 - Localizar Funcionário                     |\n");
     printf("|4 - Actualizar Funcionário                    |\n");
     printf("|5 - Bloquear Funcionário                      |\n");
     printf("|6 - Desbloquear Funcionário                   |\n");
     printf("|0 - Sair                                      |\n");
	 printf("\n00000000000000000000000000000000000000000oo00000\n\nOpção: ");
    scanf("%d",&option);
    return option;
}

int insert(employees *emp){
    char name[30], role[20];
    float salary;
    printf("Nome: ");
    scanf("%s",name);
    printf("Cargo: ");
    scanf("%s",role);
    printf("Salário: ");
    scanf("%f",&salary);   
    return insertEmployee(emp,name,role,salary);
}
//getDescription(emp,1,"name")
int update(employees *emp, int code, int index){
    char name[30], role[20];
    float salary;
    printf("Nome (%s): ", getName(emp,index));
    scanf("%s",name);
    printf("Cargo (%s): ", getRole(emp,index));
    scanf("%s",role);
    printf("Salário (%.2f): ", getSalary(emp,index));
    scanf("%f",&salary);   
    return updateEmployee(emp, code, name, role, salary, 1);
}


