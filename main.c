#include <stdio.h>
#include "employee.h"
#include <string.h>
#include <stdlib.h>

int menu(employees *emp);

int main()
{
   int answer = 1, option;
   
   employees *myEmployees = create();
   if (myEmployees  == NULL){
     printf("Falha na alocação de memória!\nFechamento do Programa");
     return 0;
   }

    while(answer){
        option = menu(myEmployees);
        switch(option){
            case 0: answer = 0;
        }
    }
    //int x = insertEmployee(myEmployees, "bruno", "programador", 1, 2000);

    destroy(&myEmployees);
    return 0;
}


int menu(employees *emp){
    int option;
    system("cls");
    printf("Bem-Vindo ao Serviço de Controlo de Funcionários\n\n");
     printf("oooooooooooooooooooooooooooooooooooooooooooooooo\n");
	 printf(" Quantidade de Funcionários: %d\n\n",length(emp));
	 printf("|1 - Ver Funcionários                          |\n");
     printf("|2 - Inserir Funcionários                      |\n");
     printf("|3 - Propriedades de Funcionários              |\n");
     printf("|4 - Actualizar Funcionário                    |\n");
     printf("|5 - Bloquear Funcionário                      |\n");
     printf("|6 - Desbloquear Funcionário                   |\n");
     printf("|0 - Sair                                      |\n");
	 printf("\n00000000000000000000000000000000000000000oo00000\n");
    scanf("%d",&option);
    return option;
}


