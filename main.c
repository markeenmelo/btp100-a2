#include <stdio.h>
#include <string.h>
#define MAX_EMPLOYEES 50
// declares the max number of employees

struct Employee { // Tyler: struct for employee data type that will store id, name, gender, ethnicity and salary
    int id; 
    char name[50]; 
    char gender[50]; 
    char ethnicity[50]; 
    float salary;
};

int areStringsEqual(const char *str1, const char *str2);


struct Employee addEmployee(struct Employee *employees, int size); // Tyler: declaring the add employee function that has the data type employee and will receive 2 variables employees as a pointer and size variable
void deleteEmployee(int ID, struct Employee *employees, int* size); // Tyler: declaring the delete employee function that will receive ID, employee as a pointer and size as a pointer to directly change the values of them
void findEmployee(struct Employee *employees, int targetId);
void displayEmployees(struct Employee *employees, int count);
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

    int choice = 1, i = 0; // Tyler: choice and i variable for interation and which option the user selects
    int ID; // 

    // Max: simple program title banner
    printf("==============================================\n");
    printf(" Pay Scale Comparison for Equity and Inclusion\n");
    printf("==============================================\n");
    do {
        printf("\nMenu:\n");                                       // Max: label for the menu block
        printf("1. Add employee\n");                               // Max: option to add a new employee
        printf("2. Remove employee\n");                            // Max: option to delete an employee
        printf("3. Display employees (with filters)\n");           // Max: option to view employee list
        printf("4. Search employee by ID\n");                      // Max: option to find one employee
        printf("5. Salary comparison & averages\n");               // Max: option to run equity analysis
        printf("0. Exit\n");                                       // Max: option to quit the program
        scanf("%d", &choice);

        switch(choice) { // Tyler: switch with the choice variable, checks choice variable to see what the user inputs
            case 1: // Tyler: add a new employee
                employees[i] = addEmployee(employees, i); // Tyler: assigns the added employee to the employees array with the result of the add employee function
                i++; // adds 1 to the size after adding an employee
                break; 
            case 2:
                if (i == 0) { // scenario for when the user wants to delete when there's no employees
                    printf("No employees to remove.\n"); 
                } else { // Tyler: runs when theres 1 or more employees
                    printf("Enter employee ID to remove: ");
                    scanf("%d", &ID); // Tyler: scans the users input for the id they want to delete
                    deleteEmployee(ID, employees, &i); // Tyler: calls the delete employee function with the ID, employees array and &i variable. Because i is the size so it needs pass by address to change the size after deleting an employee
                }
                break; 
            case 6: // Tyler: case for when user wants to exit the program
                printf("Thank you for using our program!\n");
                choice = 6; // changes the choice variable to 6 so the do while loop is invalid and it ends
                break;
            default:
                printf("Invalid choice, try again\n"); // Tyler: default case for when user inputs a value not in the menu
                break; 
        }
    } while (choice != 6); // condition that ends the do while loop when the user chooses exit option

    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int idCheck(int ID, struct Employee employeeList[], int size) { // Tyler: id check function used in delete employee fucntion to see if id exists
    for (int i = 0; i < size; i++) { // Tyler: for loop that checks the whole employee list's IDs for duplicates
        if (employeeList[i].id == ID) { // Tyler: condition for finding a duplicate
            return 1; // Tyler: value returned when the duplicate is found
        }
    }
    return 0; // Tyler: value returned when there are no duplicates
}

struct Employee addEmployee(struct Employee *employees, int size) { // Tyler: declares the add employee function as an employee data type
    struct Employee list; // Tyler: declares list as an employee data type 
    int sanity = 0; // Tyler: variable for sanity check
    do { // Tyler: do while loop that ensures the users input is valid
        printf("Enter new employee ID: "); // Tyler: ask the user to input an ID
        scanf("%d", &list.id); // Tyler: scans the users input for the ID
        if (list.id <= 0) { // Tyler: happens when user enters a non positive number
            printf("Id must be a positive number\n");
        } else if (idCheck(list.id, employees, size) == 1) { // Tyler: employeeList is a pointer passed into idCheck
            printf("This id already exists, please enter a different number\n\n");
        } else { // Tyler: happens when the user enters a valid value and doesn't get flagged for errors
            sanity = 0; // Tyler: sanity will be 0 and ends the do/while 
        }
    } while (sanity == 1); // Tyler: condition for do while loop, runs when user enters a wrong or invalid value

    printf("Enter employee name: ");
    scanf("%49s", list.name); // Tyler: scans users input for employee name
    printf("Enter employee gender: ");
    scanf("%49s", list.gender); // Tyler: scans users input for employee gender
    printf("Enter employee ethnicity: ");
    scanf("%49s", list.ethnicity); // Tyler: scans users input for employee etnicity

    do { // Tyler: do while loop for sanity checking the salary input
        sanity = 0; // Tyler: resets the sanity value
        printf("Enter employee salary: "); 
        scanf("%f", &list.salary); // Tyler: scans the users input for salary
        if (list.salary <= 0) { // Tyler: flags if user input is a non positive number
            printf("Salary must be a positive number!\n"); 
            sanity = 1; // Tyler: changes the value of sanity so that the loop reruns and asks the salary input from user again 
        }
    } while (sanity == 1); // Tyler: condition to run the loop when the user types a non valid value

    return list; // Tyler: returns the value of the list
}


void deleteEmployee(int ID, struct Employee employees[], int* size) { // Tyler: declares the delete employee funciton as a void funciton and takes varaibles ID, employee list, and size variable as a pass by adddress so it can change the size after deleting a
    int found = 0; // Tyler: declares the found variable for flagging the id when found
    int i = 0; // Tyler: loop iterator

    do { // Tyler: do while loop for checking for ID
        if (ID == (*(employees + i)).id) { // Tyler: logical expression to check if the input id is the same as any of the other ids
            found = 1; // Tyler: changes the found variable value for when the same id is found
        } else { // Tyler: happens when the user input id is not the same as the current id being checked
            i++; // Tyler: adds 1 to the iteration so it checks the next ID value
        }
    } while (found == 0 && i < *size); // Tyler: condition to stop the search when the id typed is found or it has reached the end

    if (found == 1) { // Tyler: condition when the id user typed is found
        while (i < *size - 1) { // Tyler: while loop to replace the current id with the values after it, size -1 so that it doesn't replace the last variable with an empty value 
            *(employees + i) = *(employees + i + 1); // Tyler: replacing current i with the one after it
            i++; // Tyler: increases the i value by 1 to keep going
        }
        (*size)--; // Tyler: decreases the value by 1 after removing 1 employee
    } else { // Tyler: happens when the id user inputted is not found 
        printf("User id does not exist\n"); 
    }
}

void displayEmployees(struct Employee *employees, int count) {
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
    struct Employee *p = employees;

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
