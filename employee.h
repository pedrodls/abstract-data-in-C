typedef struct e employee;

typedef struct el employeeList;

employeeList* initEmployeeList(employeeList *list);

employee* createEmployee(employee emp);

employee* findEmployee(int code);

employeeList* findAll();

char* getDescription(int code, char* prop);

char* showAllDescriptio();

int updateEmployee(int code, char* prop, char* description);

short block(int code, float newBadge);

short enable(int code);
