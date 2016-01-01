#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
Problem 5
Author: Nick Keirstead
*/

typedef struct EmployeeList {
  char* name;
  char* surname;
  int phone;
  int salary;
  struct EmployeeList *next;
} EmployeeList;

EmployeeList* addEmp(char *name, char *surname, int phone, int salary, EmployeeList *list) {
	
	EmployeeList *e = malloc(sizeof(EmployeeList));
  	e->name = strdup(name);
  	e->surname = strdup(surname);
  	e->phone = phone;
  	e->salary = salary;
  	e->next = list;
  	return e;
}

void printEmp(EmployeeList *e) {
	printf("Name: %s || Surname: %s || Phone: %d || Salary: %dK\n", e->name, e->surname, e->phone, e->salary);
}

void printEmpAll(EmployeeList *list) {
	if (list == NULL) {
		printf("No Employees In Database\n");
	}
	else {
		EmployeeList *e;
		for (e = list; e != NULL; e = e->next) {
			printEmp(e);
		}
	}
}

void searchEmp(char *name, EmployeeList *list) {
	EmployeeList *e = NULL;
	for (e = list; e != NULL; e = e->next) {
		if (strcmp(e->name, name) == 0) {
			printEmp(e);
			return;
		}
	}
	printf("Employee %s Not Found\n", name);
}


EmployeeList* deleteEmp(char *name, EmployeeList *list) {
	EmployeeList *curr = NULL;
	EmployeeList *prev = NULL;
	for (curr = list; curr != NULL; curr = curr->next) {
		if (strcmp(curr->name, name) == 0) {
			if (prev != NULL) {
				prev->next = curr->next; //skip over curr, which will be "deleted"
				return list;
			}
			else {
				return curr->next;
			}
			break;
		}
		prev = curr;
	}
	printf("Employee %s Not Found\n", name);
	return NULL;
}

void printChoices() {
	printf("(1) Add Employee\n");
	printf("(2) Print All Employees\n");
	printf("(3) Search Employee By First Name\n");
	printf("(4) Delete Employee By First Name\n");
	printf("(5) Save All Employees To Database\n");
}

bool validChoice(int c) {
	return c >= 1 && c <=5;
}

EmployeeList* readFromFile(FILE *f, EmployeeList *list) {
	char name[30];
	char surname[30];
	int phone;
	int salary;
	int err;
	
	while (true) {
		err = fscanf(f, "%s %s %d %d", name, surname, &phone, &salary);
		if (err == EOF)
			break;
		list = addEmp(name,surname,phone,salary,list);
	}
	return list;
}

void saveToFile(FILE *f, EmployeeList *list) {
	EmployeeList *e = NULL;
	for (e = list; e != NULL; e = e->next) {
		fprintf(f, "%s %s %d %d\n", e->name, e->surname, e->phone, e->salary);
	}
}


int main (void) {
	FILE *staff = fopen("staff.txt","r");
	
	//call up staff info from database and put it in linked list
 	EmployeeList *list = readFromFile(staff,list);
	fclose(staff);
  	
	char name[100], surname[100];
  	int phone, salary;

  	bool again = false;
  	do {
    
    	int choice;
    	do {
    		printChoices();
    		scanf("%d", &choice);
    	} while (!validChoice(choice));

    	if (choice == 1) {
    		printf("Enter Name and Surname: ");
      		scanf("%s %s", name, surname);
      		printf("Enter Phone Extension (####): ");
      		scanf("%d", &phone);
      		printf("Enter Salary: ");
      		scanf("%d", &salary);
      		list = addEmp(name, surname, phone, salary, list);
      		printf("%s %s Temporarily Added To System.\n", list->name, list->surname);
    	}
    	else if (choice == 2) {
    		printEmpAll(list);
   		}
		else if (choice != 5) {
			char n[20];
			printf("Enter First Name: ");
			scanf("%s", n);
			if (choice == 3) searchEmp(n,list);
			if (choice == 4) list = deleteEmp(n, list);
		}
		else {
			staff = fopen("staff.txt", "w");
			saveToFile(staff, list);
			fclose(staff);
			//write contents of list back into file
			//overwrites file's previous content
		}
	
    	printf("Continue? (y/n): ");
    	char response;
    	scanf(" %c", &response);
    	response == 'y' ? (again = true) : (again = false);
		if (again) printf("\n");
  	}
  	while (again);

	fclose(staff);

	return 0;
}
