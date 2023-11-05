typedef struct Employees employees;

//employeeList* initEmployeeList(employeeList *list);


employees* create();
int insertEmployee(employees * emp, char *name, char *role, int code, float salary);
void findAll(employees* emp);
employees* findEmployee(int code);
char* getDescription(int code, char *prop);
char* showAllDescription();
int updateEmployee(int code, char *prop, char *description);
short block(int code);
short enable(int code);
void destroy(employees **emp);
