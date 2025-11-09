#include <stdio.h>
#include <string.h>
#define MAX_EMPLOYEES 50

struct Employee {
    int id;
    char name[50];
    char gender[50];
    char ethnicity[50];
    float salary;
};

int areStringsEqual(const char *str1, const char *str2);


struct Employee addEmployee(struct Employee employees[], int size);
void deleteEmployee(int ID, struct Employee employees[], int* size);
void findEmployee(struct Employee *employees, int targetId);
void displayEmployees(struct Employee *list, int count);
float calculateAverageSalary(struct Employee *employees, const char *targetGender, const char *targetEthnicity);
void displayComparison(struct Employee *employees);

int main() {

    struct Employee employees[MAX_EMPLOYEES] = {
        {101, "John Doe", "male", "black", 45000.50},
        {102, "Diego Rivera", "male", "indigineous", 52000.75},
        {103, "Marcus Lee", "male", "people of color", 51000.80},
        {104, "Mary Johnson", "female", "black", 48000.25},
        {105, "Nora Jones", "female", "indigineous", 55000.00},
        {106, "Sarah Wilson", "female", "people of color", 53000.00},
        {107, "Taylor Morgan", "non-binary", "black", 47000.00},
        {108, "Alex Redbird", "non-binary", "indigineous", 46000.00},
        {109, "Casey Rivera", "non-binary", "people of color", 49500.00}
    };

    int choice = 1, i = 0;
    int ID;

    printf("Welcome to the company's data management program\n");
    do {
        printf("Options:\n");
        printf("1. Add employee\n");
        printf("2. Remove employee\n");
        printf("3. Display employees\n");
        printf("4. Salary analysis\n");
        printf("5. Display comparison\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                employees[i] = addEmployee(employees, i);
                i++;
                break;
            case 2:
                if (i == 0) {
                    printf("No employees to remove.\n");
                } else {
                    printf("Enter employee ID to remove: ");
                    scanf("%d", &ID);
                    deleteEmployee(ID, employees, &i);
                }
                break;
            default:
                printf("Invalid choice, try again\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int idCheck(int ID, struct Employee employeeList[], int size) {
    for (int i = 0; i < size; i++) {
        if (employeeList[i].id == ID) {
            return 1;
        }
    }
    return 0;
}

struct Employee addEmployee(struct Employee employeeList[], int size) {
    struct Employee list;
    int sanity = 0;
    do {
        printf("Enter new employee ID: ");
        scanf("%d", &list.id);
        if (list.id <= 0) {
            printf("Id must be a positive number\n");
        } else if (idCheck(list.id, employeeList, size) == 1) {
            printf("This id already exists, please enter a different number\n\n");
        } else {
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
            printf("Salary must be a positive number!\n");
            sanity = 1;
        }
    } while (sanity == 1);
    return list;
}

void deleteEmployee(int ID, struct Employee employeeList[], int* size) {
    int found = 0;
    int i = 0;
    do {
        if (ID == employeeList[i].id) {
            found = 1;
        } else {
            i++;
        }
    } while (found == 0 && i < *size);

    if (found == 1) {
        while(i < *size - 1) {
            employeeList[i] = employeeList[i + 1];
            i++;
        }
        (*size)--;
    } else {
        printf("User id does not exist\n");
    }
}

void displayEmployees(struct Employee *list, int count) {
    if (count == 0) {
        printf("\nNo employees to display.\n");
        return;
    }

    int option;
    char gender[20];
    char ethnicity[30];

    printf("\n--- Display Employees ---\n");
    printf("1. All employees\n");
    printf("2. Filter by gender\n");
    printf("3. Filter by ethnicity\n");
    printf("4. Filter by gender AND ethnicity\n");
    printf("Choose an option: ");
    scanf("%d", &option);
    clearInputBuffer();

    if (option == 2 || option == 4) {
        printf("Enter gender to filter by: ");
        scanf("%19s", gender);
        clearInputBuffer();
    }

    if (option == 3 || option == 4) {
        printf("Enter ethnicity to filter by: ");
        scanf("%29[^\n]", ethnicity);
        clearInputBuffer();
    }

    int found = 0;
    struct Employee *p = list;

    for (int i = 0; i < count; i++, p++) {
        int match = 1;

        if (option == 2 && strcmp(p->gender, gender) != 0)
            match = 0;
        if (option == 3 && strcmp(p->ethnicity, ethnicity) != 0)
            match = 0;
        if (option == 4 &&
            (strcmp(p->gender, gender) != 0 ||
             strcmp(p->ethnicity, ethnicity) != 0))
            match = 0;

        if (option == 1 || match) {
            printf("ID: %d, Name: %s, Gender: %s, Ethnicity: %s, Salary: %.2f\n",
                   p->id, p->name, p->gender, p->ethnicity, p->salary);
            found = 1;
        }
    }

    if (!found && option != 1) {
        printf("No employees match your filters.\n");
    }
}

int areStringsEqual(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) return 0;
        i++;
    }
    return 1;
}

void findEmployee(struct Employee *employees, int targetId) {
    int found = 0;
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        if (employees[i].id == targetId) {
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Gender: %s\n", employees[i].gender);
            printf("Ethnicity: %s\n", employees[i].ethnicity);
            printf("Salary: $%.2f\n", employees[i].salary);
            found = 1;
            break;
        }
    }
    if (!found) printf("Employee with ID %d not found\n", targetId);
}

float calculateAverageSalary(struct Employee *employees, const char *targetGender, const char *targetEthnicity) {
    float salarySum = 0.0;
    int count = 0;
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        int genderMatch = targetGender == NULL ? 1 : areStringsEqual(employees[i].gender, targetGender);
        int ethnicityMatch = targetEthnicity == NULL ? 1 : areStringsEqual(employees[i].ethnicity, targetEthnicity);
        if (genderMatch && ethnicityMatch) {
            salarySum += employees[i].salary;
            count++;
        }
    }
    if (count == 0) return salarySum;
    return salarySum / count;
}

void displayComparison(struct Employee *employees) {
    const char *genders[] = {"male", "female", "non-binary", "any"};
    const char *ethnicities[] = {"black", "indigineous", "people of color", "any"};
    int gendersCount = sizeof(genders) / sizeof(genders[0]);
    int ethnicitiesCount = sizeof(ethnicities) / sizeof(ethnicities[0]);
    for (int i = 0; i < gendersCount; i++) {
        for (int j = 0; j < ethnicitiesCount; j++) {
            const char *genderParam = areStringsEqual(genders[i], "any") ? NULL : genders[i];
            const char *ethnicityParam = areStringsEqual(ethnicities[j], "any") ? NULL : ethnicities[j];

            float averageSalary = calculateAverageSalary(employees, genderParam, ethnicityParam);
            const char *genderLabel = areStringsEqual(genders[i], "any") ? "any gender" : genders[i];
            const char *ethnicityLabel = areStringsEqual(ethnicities[j], "any") ? "any ethnicity" : ethnicities[j];

            printf("Average salary for %s and %s => $%.2f\n", genderLabel, ethnicityLabel, averageSalary);
        }
    }
}