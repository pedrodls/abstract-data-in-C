typedef struct Employees employees;

//employeeList* initEmployeeList(employeeList *list);


employees* create(); //cria a estrutura
int insertEmployee(employees *emp, char *name, char *role, int code, float salary); //insere um funcionário
void findAll(employees* emp); //mostra todos os funcionários
employees* findEmployee(int code); //encontra um funcionário pelo código
int length(employees *emp); //tamanho de funcionários existentes
char* getDescription(int code, char *prop); //atribuito específico de um funcionário pelo código
char* showAllDescription(); //mostra todos os atributos requeridos pelo funcionário
int updateEmployee(int code, char *prop, char *description); //actualiza um dado específico de um funcionário
short block(int code); //inactiva um funcionário
short enable(int code); //activa um funcionário
void destroy(employees **emp); //no fim do programa ele desaloca a memória
