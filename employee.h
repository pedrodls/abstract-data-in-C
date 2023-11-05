typedef struct Employee employee;

//typedef struct el employeeList;

//employeeList* initEmployeeList(employeeList *list);
employee* createEmployee(char *name, char *role, int code, float salary);
employee* findEmployee(int code);
//employeeList* findAll();
char* getDescription(int code, char *prop);
char* showAllDescriptio();
int updateEmployee(int code, char *prop, char *description);
short block(int code);
short enable(int code);
void destroy(employee **emp);
