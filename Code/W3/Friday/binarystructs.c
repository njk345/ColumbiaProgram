#include <stdio.h>
#include <assert.h>

typedef struct Employee {
	int id;
	char firstname[20];
	char lastname[20];
	float salary;
} E;

void printEmp(E *e) {
	printf("ID: %d || First Name: %s || Last Name: %s || Salary: %.2f K\n", e->id, e->firstname, e->lastname, e->salary);
}


int main(void) {
	FILE *staff = fopen("EmployeesDB.dat", "w");
	assert(staff != NULL);
	
	E emp1;
	E emp2;
	E emp3;
	
	E emps[3] = {emp1, emp2, emp3};
	E restoredEmps[3];
	
	int i;
	for (i = 0; i < 3; i++) {
		printf("Enter Id (###): ");
		scanf("%d", &emps[i].id);
		printf("Enter First Name and Last Name: ");
		scanf("%s %s", &emps[i].firstname, &emps[i].lastname);
		printf("Enter Salary In Thousands: ");
		scanf("%f", &emps[i].salary);
	}
	
	fwrite(emps, sizeof(E), 3, staff);
	fclose(staff);
	
	staff = fopen("EmployeesDB.dat", "r");
	assert(staff != NULL);
	
	fread(restoredEmps, sizeof(E), 3, staff);
	
	printf("\nContents Of Staff Database:\n");
	for (i = 0; i < 3; i++) {
		printEmp(&restoredEmps[i]);
	}
	return 0;
}