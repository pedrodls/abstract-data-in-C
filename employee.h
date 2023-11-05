typedef struct Employees employees;

//employeeList* initEmployeeList(employeeList *list);
//employeeList* findAll();

employees* create();
employees* insertEmployee(employees * emp, char *name, char *role, int code, float salary);
employees* findEmployee(int code);
char* getDescription(int code, char *prop);
char* showAllDescription();
int updateEmployee(int code, char *prop, char *description);
short block(int code);
short enable(int code);
void destroy(employees **emp);
