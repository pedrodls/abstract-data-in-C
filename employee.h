typedef struct Employees employees;

//employeeList* initEmployeeList(employeeList *list);


employees* create(); //cria a estrutura
int insertEmployee(employees *emp, char *name, char *role, float salary); //insere um funcionário
void findAll(employees* emp); //mostra todos os funcionários
void findEmployee(employees* emp,int code); //encontra um funcionário pelo código
int length(employees *emp); //tamanho de funcionários existentes
int updateEmployee(employees *emp, int code, char *name, char *role, float salary, int isActive); //actualiza dado de um funcionário pelo código. Retorna 0 (falha). 1 (sucesso)
char* getDescription(int code, char *prop); //atribuito específico de um funcionário pelo código
char* showAllDescription(); //mostra todos os atributos requeridos pelo funcionário
short block(int code); //inactiva um funcionário
short enable(int code); //activa um funcionário
void destroy(employees **emp); //no fim do programa ele desaloca a memória
