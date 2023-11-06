typedef struct Employees employees;

//employeeList* initEmployeeList(employeeList *list);


employees* create(); //cria a estrutura
int insertEmployee(employees *emp, char *name, char *role, float salary); //insere um funcionário
void findAll(employees* emp); //mostra todos os funcionários
void findEmployee(employees* emp,int code); //encontra um funcionário pelo código
int updateEmployee(employees *emp, int code, char *name, char *role, float salary, short isActive); //actualiza dado de um funcionário pelo código. Retorna 0 (falha). 1 (sucesso)
char* showAllDescription(); //mostra todos os atributos requeridos pelo funcionário

//Métodos Get da Função
int length(employees *emp); //tamanho de funcionários existentes
char* getName(employees *emp, int index); //retorna o nome do funcionário
char* getRole(employees *emp, int index); //retorna o cargo do funcionário
float getSalary(employees *emp, int index); //retorna o salario do funcionário
int getCode(employees *emp, int index); //retorna o codigo do funcionário
short getIsActive(employees *emp, int index); //retorna o estado do funcionário
int getIndex(employees *emp, int code); //retorna o índice do funcionário do código enviado

//Métodos Set
short block(int code); //inactiva um funcionário
short enable(int code); //activa um funcionário

void destroy(employees **emp); //no fim do programa ele desaloca a memória