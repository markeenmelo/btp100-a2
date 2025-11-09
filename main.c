#define maxEmployee 50
#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char gender[50];
    char ethnicity[50];
    float salary;
};

struct employee addEmployee(struct employee employeeList[], int size);
void deleteEmployee(int ID, struct employee employeeList[], int* size);
void displayEmployees(struct Employee *list, int count);
void findEmployee(int id);
void salaryAnalysis(float maleAvg, float femaleAvg, float bipocAvg, float nonBipocAvg);
void displayComparison();

int main() {
    struct Employee employees[100];
    int main() {
	int choice = 1, i = 0;
	struct employee employeeList[50];
	int ID;
	char name[50], gender[50], ethnicity[50];
	float salary;

	printf("Welcome to the company's data management program\n");
	do {
		printf("Options:\n");
		printf("1. Add employee\n");
		printf("2. Remove employee\n");
		printf("3. Display employees\n");
		printf("4. Salary analysis\n");
		printf("5. Display comparison\n");
		printf("6. \n");
		scanf("%d", &choice);

		switch(choice){
		case 1: 
			employeeList[i] = addEmployee();
            i++;
			break;
		case 2:
			if (i == 0) {
				printf("No employees to remove.\n");
			}
			else {
				printf("Enter employee ID to remove: ");
				scanf("%d", &ID);
				deleteEmployee(&ID, employeeList, &i);
			}
			break;
		}
		default:
			printf("Invalid choice, try again");
			break;

		
	} while (choice != 0);

	return 0;
}
int idCheck(int ID, struct employee employeeList[], int size) {
	for (int i = 0; i < size; i++) {
		if (employeeList[i].ID == ID) {
			return 1;
		}
	}
	return 0; 
}

struct employee addEmployee(struct employee employeeList[], int size){
	struct employee list;
	int sanity = 0;
	do {
		printf("Enter new employee ID: ");
		scanf("%d", &list.ID);
		if (list.ID <= 0) {
			printf("Id must be a positive number");
		}
		else if (idCheck(list.ID, employeeList, size) == 1) {
			printf("This id already exists, please enther a different number\n\n");
		}
		else {
			sanity = 0;
		}
	} while (sanity == 1);

	printf("Enter employee name: ");
	scanf("%49s", list.name);
	printf("Enter employee gender: ");
	scanf("%49s", list.gender);
	printf("Enter employee ethnicity: ");
	scanf("%49s", list.ethnicity);
	do {
		sanity = 0;
		printf("Enter employee salary: ");
		scanf("%f", &list.salary);
		if (list.salary <= 0) {
			printf("salary must be a positive number!\n");
			sanity = 1;
		}
	} while (sanity == 1);
	return list;
}

void deleteEmployee(int ID, struct employee employeeList[], int* size) {
	int found = 0;
	int i = 0;
	do {
		if (ID == employeeList[i].ID) {
			found = 1;
			;
		}
		else {
			i++;
		}
	} while (found == 0 && i < *size);

	if (found == 1) {
		while(i < *size - 1) {
			employeeList[i] = employeeList[i + 1];
			i++;
		}
		(*size)--;
	}	
	else {
		printf("User id does not exist");
	}
}


// Max: function to display employees, with optional filters by gender/ethnicity
void displayEmployees(struct Employee *list, int count) {
    if (count == 0) {                // Max: check if there are employees in the system
        printf("\nNo employees to display.\n");
        return;
    }

    int option;                      // Max: store filter option
    char gender[20];                 // Max: gender filter text
    char ethnicity[30];              // Max: ethnicity filter text

    // Max: show display options
    printf("\n--- Display Employees ---\n");
    printf("1. All employees\n");
    printf("2. Filter by gender\n");
    printf("3. Filter by ethnicity\n");
    printf("4. Filter by gender AND ethnicity\n");
    printf("Choose an option: ");
    scanf("%d", &option);
    clearInputBuffer();              // Max: clear buffer to avoid leftover characters

    // Max: take gender input if needed
    if (option == 2 || option == 4) {
        printf("Enter gender to filter by: ");
        scanf("%19s", gender);
        clearInputBuffer();
    }

    // Max: take ethnicity input if needed
    if (option == 3 || option == 4) {
        printf("Enter ethnicity to filter by: ");
        scanf("%29[^\n]", ethnicity);
        clearInputBuffer();
    }

    int found = 0;                   // Max: track if any match found
    struct employee *p = list;       // Max: pointer to iterate employees

    // Max: loop using pointer arithmetic
    for (int i = 0; i < count; i++, p++) {
        int match = 1;               // Max: assume record matches

        if (option == 2 && strcmp(p->gender, gender) != 0)
            match = 0;               // Max: skip if gender mismatch
        if (option == 3 && strcmp(p->ethnicity, ethnicity) != 0)
            match = 0;               // Max: skip if ethnicity mismatch
        if (option == 4 &&
            (strcmp(p->gender, gender) != 0 ||
             strcmp(p->ethnicity, ethnicity) != 0))
            match = 0;               // Max: skip if both filters fail

        if (option == 1 || match) {  // Max: print if all or matching
            printEmployee(p);
            found = 1;
        }
    }

    if (!found && option != 1) {     // Max: no matches message
        printf("No employees match your filters.\n");
    }
};
void findEmployee(int id) {
    printf('%d Employee', id);
};
// Max: simplified salary comparison (Marcos handles calculations)
void salaryAnalysis(float maleAvg, float femaleAvg, float bipocAvg, float nonBipocAvg) {
    printf("\n--- Salary Comparison Report ---\n");

    // Max: gender comparison
    if (maleAvg > 0 && femaleAvg > 0) {
        float diff = maleAvg - femaleAvg;
        if (diff > 0)
            printf("Male employees earn %.2f more on average than female employees.\n", diff);
        else if (diff < 0)
            printf("Female employees earn %.2f more on average than male employees.\n", -diff);
        else
            printf("Male and female employees earn the same on average.\n");
    }

    // Max: ethnicity comparison
    if (bipocAvg > 0 && nonBipocAvg > 0) {
        float diff = nonBipocAvg - bipocAvg;
        if (diff > 0)
            printf("Non-BIPOC employees earn %.2f more on average than BIPOC employees.\n", diff);
        else if (diff < 0)
            printf("BIPOC employees earn %.2f more on average than Non-BIPOC employees.\n", -diff);
        else
            printf("BIPOC and Non-BIPOC employees earn the same on average.\n");
    }

    printf("\nEquity assessment complete.\n");
};
void displayComparison() {

};
