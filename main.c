// include standard input/output library for printf and scanf functions
#include <stdio.h>
// include string library for strcmp and strcpy functions
#include <string.h>

// define the maximum number of employees that can be stored in the system
#define MAX_EMPLOYEES 50

// define the employee structure that contains employee information
struct Employee {
    int id;                    // unique identifier for each employee
    char name[50];            // employee's full name (max 49 characters)
    char gender[50];          // employee's gender (max 49 characters)
    char ethnicity[50];       // employee's ethnicity (max 49 characters)
    float salary;             // employee's salary in dollars
};

// we broke down the parts by function and grouped then together once finished
// function prototypes for main operations on employee data
void addEmployee(struct Employee* employees, int* count);               // TYLER
void deleteEmployee(struct Employee* employees, int* count);            // TYLER
void displayEmployees(struct Employee* employees, int count);           // MAX
void searchEmployeeByID(struct Employee* employees, int count);         // MAX
void calculateAverageSalary(struct Employee *employees, int count);     // MARCOS
void displayComparison(struct Employee *employees, int count);          // MARCOS

// function prototypes for helper functions (user input and menu display)
void displayMenu(void);                 // MARCOS
char* selectGender(void);               // MARCOS
char* selectEthnicity(void);            // MARCOS
char* selectGenderWithAny(void);        // MARCOS
char* selectEthnicityWithAny(void);     // MARCOS

// main function: entry point of the program
// creates a menu-driven interface for the pay scale comparison system
int main(void) {
    // create an array of employee structures to store up to max_employees records
    struct Employee employees[MAX_EMPLOYEES];
    // initialize employee count to 0 (no employees added yet)
    int employeeCount = 0;
    // variable to store user's menu choice
    int choice;

    // display the title of the application
    printf("=== Pay Scale Comparison System ===\n");

    // do-while loop: display menu and process user choice until user selects exit (0)
    do {
        // display the menu options to the user
        displayMenu();
        // prompt user to enter their choice
        printf("Enter your choice (1-7): ");
        // read the user's choice from standard input
        scanf("%d", &choice);

        // switch statement to handle different menu options
        switch (choice) {
            // case 1: add a new employee
            case 1:
                // call addEmployee function with pointer to array and pointer to count
                addEmployee(employees, &employeeCount);
                break;
            // case 2: delete an employee
            case 2:
                // call deleteEmployee function with pointer to array and pointer to count
                deleteEmployee(employees, &employeeCount);
                break;
            // case 3: display employees based on criteria
            case 3:
                // call displayEmployees function with array and employee count
                displayEmployees(employees, employeeCount);
                break;
            // case 4: search for an employee by id
            case 4:
                // call searchEmployeeByID function with array and employee count
                searchEmployeeByID(employees, employeeCount);
                break;
            // case 5: calculate average salary
            case 5:
                // call calculateAverageSalary function with array and employee count
                calculateAverageSalary(employees, employeeCount);
                break;
            // case 6: display comparison results
            case 6:
                // call displayComparison function with array and employee count
                displayComparison(employees, employeeCount);
                break;
            // case 0: exit the program
            case 0:
                // print exit message
                printf("Exiting program. Thank you!\n");
                break;
            // default case: invalid choice
            default:
                // print error message for invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
        }
        // print a blank line for readability
        printf("\n");
    // continue looping while choice is not 0 (exit)
    } while (choice != 0);

    // return 0 to indicate successful program completion
    return 0;
}

// function to display the main menu with available options
// takes no parameters
void displayMenu(void) {
    // print menu header
    printf("\n--- Menu ---\n");
    // print all menu options available to the user
    printf("1. Add a new employee\n");
    printf("2. Delete an employee\n");
    printf("3. Display employees\n");
    printf("4. Search employee by ID\n");
    printf("5. Calculate average salaries\n");
    printf("6. Display comparison results\n");
    printf("0. Exit\n");
}

// helper function to select gender from predefined options during employee addition
// returns a pointer to a string representing the selected gender
char* selectGender(void) {
    // display the gender selection menu
    printf("\nSelect gender:\n");
    printf("1. male\n");
    printf("2. female\n");
    printf("3. non-binary\n");
    // prompt user to enter their choice
    printf("Enter your choice (1-3): ");

    // declare a variable to store the user's menu choice
    int choice;
    // read the user's choice from standard input
    scanf("%d", &choice);

    // switch statement to return the selected gender based on user's choice
    switch (choice) {
        // case 1: user selected male
        case 1:
            // return the string "male"
            return "male";
        // case 2: user selected female
        case 2:
            // return the string "female"
            return "female";
        // case 3: user selected non-binary
        case 3:
            // return the string "non-binary"
            return "non-binary";
        // default case: invalid choice
        default:
            // print error message
            printf("Invalid choice. Please try again.\n");
            // recursively call this function to allow user to try again
            // I know we didn't learn recursion yet and even myself struggle with it sometimes
            // but seemed simple enough for this use case
            return selectGender();
    }
}

// helper function to select ethnicity from predefined options during employee addition
// returns a pointer to a string representing the selected ethnicity
char* selectEthnicity(void) {
    // display the ethnicity selection menu
    printf("\nSelect ethnicity:\n");
    printf("1. black\n");
    printf("2. indigenous\n");
    printf("3. people of color\n");
    // prompt user to enter their choice
    printf("Enter your choice (1-3): ");

    // declare a variable to store the user's menu choice
    int choice;
    // read the user's choice from standard input
    scanf("%d", &choice);

    // switch statement to return the selected ethnicity based on user's choice
    switch (choice) {
        // case 1: user selected black
        case 1:
            // return the string "black"
            return "black";
        // case 2: user selected indigenous
        case 2:
            // return the string "indigenous"
            return "indigenous";
        // case 3: user selected people of color
        case 3:
            // return the string "people of color"
            return "people of color";
        // default case: invalid choice
        default:
            // print error message
            printf("Invalid choice. Please try again.\n");
            // recursively call this function to allow user to try again
            // I know we didn't learn recursion yet and even myself struggle with it sometimes
            // but seemed simple enough for this use case
            return selectEthnicity();
    }
}

// helper function to select gender including "any" option for filtering/comparison
// the "any" option allows viewing data across all genders
// returns a pointer to a string representing the selected gender or "any"
char* selectGenderWithAny(void) {
    // display the gender selection menu with "any" option
    printf("\nSelect gender:\n");
    printf("1. male\n");
    printf("2. female\n");
    printf("3. non-binary\n");
    printf("4. any\n");
    // prompt user to enter their choice
    printf("Enter your choice (1-4): ");

    // declare a variable to store the user's menu choice
    int choice;
    // read the user's choice from standard input
    scanf("%d", &choice);

    // switch statement to return the selected gender or "any" based on user's choice
    switch (choice) {
        // case 1: user selected male
        case 1:
            // return the string "male"
            return "male";
        // case 2: user selected female
        case 2:
            // return the string "female"
            return "female";
        // case 3: user selected non-binary
        case 3:
            // return the string "non-binary"
            return "non-binary";
        // case 4: user selected any (to include all genders)
        case 4:
            // return the string "any"
            return "any";
        // default case: invalid choice
        default:
            // print error message
            printf("Invalid choice. Please try again.\n");
            // recursively call this function to allow user to try again
            // I know we didn't learn recursion yet and even myself struggle with it sometimes
            // but seemed simple enough for this use case
            return selectGenderWithAny();
    }
}

// helper function to select ethnicity including "any" option for filtering/comparison
// the "any" option allows viewing data across all ethnicities
// returns a pointer to a string representing the selected ethnicity or "any"
char* selectEthnicityWithAny(void) {
    // display the ethnicity selection menu with "any" option
    printf("\nSelect ethnicity:\n");
    printf("1. black\n");
    printf("2. indigenous\n");
    printf("3. people of color\n");
    printf("4. any\n");
    // prompt user to enter their choice
    printf("Enter your choice (1-4): ");

    // declare a variable to store the user's menu choice
    int choice;
    // read the user's choice from standard input
    scanf("%d", &choice);

    // switch statement to return the selected ethnicity or "any" based on user's choice
    switch (choice) {
        // case 1: user selected black
        case 1:
            // return the string "black"
            return "black";
        // case 2: user selected indigenous
        case 2:
            // return the string "indigenous"
            return "indigenous";
        // case 3: user selected people of color
        case 3:
            // return the string "people of color"
            return "people of color";
        // case 4: user selected any (to include all ethnicities)
        case 4:
            // return the string "any"
            return "any";
        // default case: invalid choice
        default:
            // print error message
            printf("Invalid choice. Please try again.\n");
            // recursively call this function to allow user to try again
            // I know we didn't learn recursion yet and even myself struggle with it sometimes
            // but seemed simple enough for this use case
            return selectEthnicityWithAny();
    }
}

// function to add a new employee to the employee array
// parameters: employees - pointer to the employee array, count - pointer to the number of employees
// this function uses pointer arithmetic to access array elements
void addEmployee(struct Employee* employees, int* count) {
    // check if the employee array is at maximum capacity
    if (*count >= MAX_EMPLOYEES) {
        // print error message if capacity is reached
        printf("Cannot add more employees. Maximum capacity reached.\n");
    }

    // declare a variable to store the new employee's id
    int id;
    // print section header
    printf("--- Add New Employee ---\n");
    // prompt user to enter employee id
    printf("Employee ID: ");
    // read the employee id from standard input
    scanf("%d", &id);

    // set current pointer to point to the first employee in the array
    struct Employee* current = employees;
    // set end pointer to point to one position past the last employee
    struct Employee* end = employees + *count;
    // initialize flag to check if employee id already exists
    int exists = 0;

    // loop through all existing employees using pointer arithmetic
    while (current < end) {
        // check if the current employee's id matches the new id
        if (current->id == id) {
            // print error message indicating id already exists
            printf("Employee with ID %d already exists.\n", id);
            // set flag to indicate employee id exists
            exists = 1;
            // exit the loop early since we found a duplicate
            break;
        }
        // move pointer to the next employee in the array
        current++;
    }

    // check if the id does not already exist in the system
    if (!exists) {
        // create pointer to the position where the new employee will be added
        struct Employee* newEmployee = employees + *count;
        // set the id of the new employee
        newEmployee->id = id;

        // prompt user to enter employee name
        printf("Name: ");
        // read the employee name from standard input
        scanf("%s", newEmployee->name);

        // call function to select gender and copy it to the new employee's record
        strcpy(newEmployee->gender, selectGender());
        // call function to select ethnicity and copy it to the new employee's record
        strcpy(newEmployee->ethnicity, selectEthnicity());

        // prompt user to enter employee salary
        printf("Salary: $");
        // read the employee salary from standard input
        scanf("%f", &newEmployee->salary);

        // increment the employee count to reflect the newly added employee
        (*count)++;
        // print success message
        printf("Employee added successfully!\n");
    }
}

// function to delete an employee from the employee array by their ID
// parameters: employees - pointer to the employee array, count - pointer to the number of employees
// uses pointer arithmetic to locate and shift array elements
void deleteEmployee(struct Employee* employees, int* count) {
    // declare a variable to store the ID of the employee to delete
    int id;
    // print section header
    printf("--- Delete Employee ---\n");
    // prompt user to enter the ID of the employee to delete
    printf("Enter Employee ID to delete: ");
    // read the employee ID from standard input
    scanf("%d", &id);

    // set current pointer to point to the first employee in the array
    struct Employee* current = employees;
    // set end pointer to point to one position past the last employee
    struct Employee* end = employees + *count;
    // initialize flag to check if employee was found
    int found = 0;

    // loop through all employees to find the one with matching ID
    while (current < end) {
        // check if the current employee's ID matches the search ID
        if (current->id == id) {
            // set flag to indicate employee was found
            found = 1;
            // exit the loop since we found the employee
            break;
        }
        // move pointer to the next employee in the array
        current++;
    }

    // check if the employee with the given ID was found
    if (found) {
        // shift all employees after the deleted one one position to the left
        while (current < end - 1) {
            // copy the next employee's data to the current position (shift left)
            *current = *(current + 1);
            // move pointer to the next position
            current++;
        }
        // decrement the employee count since one employee was deleted
        (*count)--;
        // print success message
        printf("Employee deleted successfully!\n");
    } else {
        // print error message if employee ID was not found
        printf("Employee ID does not exist\n");
    }
}

// function to display employees based on user-selected criteria
// parameters: employees - pointer to the employee array, count - the number of employees
// allows display of all employees or filtered by gender, ethnicity, or both
void displayEmployees(struct Employee* employees, int count) {
    // print section header
    printf("--- Display Employees ---\n");
    // print display filter options
    printf("1. Display all employees\n");
    printf("2. Display by gender\n");
    printf("3. Display by ethnicity\n");
    printf("4. Display by gender and ethnicity\n");
    // prompt user to select filter option
    printf("Enter your choice (1-4): ");

    // declare a variable to store the user's filter choice
    int choice;
    // read the user's choice from standard input
    scanf("%d", &choice);

    // switch statement to handle different display options
    switch (choice) {
        // case 1: Display all employees in the system
        case 1: {
            // print display header
            printf("\n--- All Employees ---\n");
            // check if there are no employees in the system
            if (count == 0) {
                // print message indicating no employees exist
                printf("No employees in the system.\n");
            }

            // set current pointer to point to the first employee in the array
            struct Employee* current = employees;
            // set end pointer to point to one position past the last employee
            struct Employee* end = employees + count;

            // loop through all employees using pointer arithmetic
            while (current < end) {
                // print employee information using pointer dereference (->)
                printf("ID: %d, Name: %s, Gender: %s, Ethnicity: %s, Salary: $%.2f\n",
                       current->id,
                       current->name,
                       current->gender,
                       current->ethnicity,
                       current->salary);
                // move pointer to the next employee in the array
                current++;
            }
            // exit the switch statement
            break;
        }
        // case 2: Display employees filtered by gender
        case 2: {
            // call function to allow user to select a gender (including "any" option)
            char *gender = selectGenderWithAny();
            // initialize flag to track if any matching employees were found
            int found = 0;

            // set current pointer to point to the first employee in the array
            struct Employee* current = employees;
            // set end pointer to point to one position past the last employee
            struct Employee* end = employees + count;

            // loop through all employees to find those matching the selected gender
            while (current < end) {
                // check if gender matches: either "any" was selected or gender matches current employee
                int genderMatch = strcmp(gender, "any") == 0 || strcmp(current->gender, gender) == 0;
                // if gender matches, display the employee
                if (genderMatch) {
                    // print employee information using pointer dereference
                    printf("ID: %d, Name: %s, Gender: %s, Ethnicity: %s, Salary: $%.2f\n",
                           current->id,
                           current->name,
                           current->gender,
                           current->ethnicity,
                           current->salary);
                    // set flag to indicate at least one matching employee was found
                    found = 1;
                }
                // move pointer to the next employee in the array
                current++;
            }

            // check if no matching employees were found
            if (!found) {
                // print message indicating no employees match the selected gender
                printf("No employees found with gender: %s\n", gender);
            }
            // exit the switch statement
            break;
        }
        // case 3: Display employees filtered by ethnicity
        case 3: {
            // call function to allow user to select an ethnicity (including "any" option)
            char *ethnicity = selectEthnicityWithAny();
            // initialize flag to track if any matching employees were found
            int found = 0;

            // set current pointer to point to the first employee in the array
            struct Employee* current = employees;
            // set end pointer to point to one position past the last employee
            struct Employee* end = employees + count;

            // loop through all employees to find those matching the selected ethnicity
            while (current < end) {
                // check if ethnicity matches: either "any" was selected or ethnicity matches current employee
                int ethnicityMatch = strcmp(ethnicity, "any") == 0 || strcmp(current->ethnicity, ethnicity) == 0;
                // if ethnicity matches, display the employee
                if (ethnicityMatch) {
                    // print employee information using pointer dereference
                    printf("ID: %d, Name: %s, Gender: %s, Ethnicity: %s, Salary: $%.2f\n",
                           current->id,
                           current->name,
                           current->gender,
                           current->ethnicity,
                           current->salary);
                    // set flag to indicate at least one matching employee was found
                    found = 1;
                }
                // move pointer to the next employee in the array
                current++;
            }

            // check if no matching employees were found
            if (!found) {
                // print message indicating no employees match the selected ethnicity
                printf("No employees found with ethnicity: %s\n", ethnicity);
            }
            // exit the switch statement
            break;
        }
        // case 4: Display employees filtered by both gender and ethnicity
        case 4: {
            // call function to allow user to select a gender (including "any" option)
            char *gender = selectGenderWithAny();
            // call function to allow user to select an ethnicity (including "any" option)
            char *ethnicity = selectEthnicityWithAny();
            // initialize flag to track if any matching employees were found
            int found = 0;

            // set current pointer to point to the first employee in the array
            struct Employee* current = employees;
            // set end pointer to point to one position past the last employee
            struct Employee* end = employees + count;

            // loop through all employees to find those matching both criteria
            while (current < end) {
                // check if gender matches: either "any" was selected or gender matches current employee
                int genderMatch = strcmp(gender, "any") == 0 || strcmp(current->gender, gender) == 0;
                // check if ethnicity matches: either "any" was selected or ethnicity matches current employee
                int ethnicityMatch = strcmp(ethnicity, "any") == 0 || strcmp(current->ethnicity, ethnicity) == 0;

                // if both gender and ethnicity match, display the employee
                if (genderMatch && ethnicityMatch) {
                    // print employee information using pointer dereference
                    printf("ID: %d, Name: %s, Gender: %s, Ethnicity: %s, Salary: $%.2f\n",
                           current->id,
                           current->name,
                           current->gender,
                           current->ethnicity,
                           current->salary);
                    // set flag to indicate at least one matching employee was found
                    found = 1;
                }
                // move pointer to the next employee in the array
                current++;
            }

            // check if no matching employees were found
            if (!found) {
                // print message indicating no employees match both criteria
                printf("No employees found with gender: %s and ethnicity: %s\n", gender, ethnicity);
            }
            // exit the switch statement
            break;
        }
        // default case: Invalid choice
        default:
            // print error message for invalid choice
            printf("Invalid choice.\n");
    }
}

// function to search for and display an employee by their ID
// parameters: employees - pointer to the employee array, count - the number of employees
// uses pointer arithmetic to iterate through the array
void searchEmployeeByID(struct Employee* employees, int count) {
    // declare a variable to store the ID to search for
    int id;
    // print section header
    printf("--- Search Employee by ID ---\n");
    // prompt user to enter the employee ID to search for
    printf("Enter Employee ID: ");
    // read the employee ID from standard input
    scanf("%d", &id);

    // set current pointer to point to the first employee in the array
    struct Employee* current = employees;
    // set end pointer to point to one position past the last employee
    struct Employee* end = employees + count;
    // initialize flag to track if the employee was found
    int found = 0;

    // loop through all employees to find the one with matching ID
    while (current < end) {
        // check if the current employee's ID matches the search ID
        if (current->id == id) {
            // print the found employee's information using pointer dereference
            printf("ID: %d, Name: %s, Gender: %s, Ethnicity: %s, Salary: $%.2f\n",
                   current->id,
                   current->name,
                   current->gender,
                   current->ethnicity,
                   current->salary);
            // set flag to indicate employee was found
            found = 1;
            // exit the loop early since we found the employee
            break;
        }
        // move pointer to the next employee in the array
        current++;
    }
    // check if the employee was not found
    if (!found) {
        // print message indicating the employee ID was not found
        printf("Employee with ID %d not found.\n", id);
    }
}

// function to calculate and display the average salary based on selected gender and/or ethnicity
// parameters: employees - pointer to the employee array, count - the number of employees
// supports selecting "any" for gender and/or ethnicity to aggregate across all values
void calculateAverageSalary(struct Employee *employees, int count) {
    // print section header
    printf("--- Calculate Average Salary ---\n");

    // call function to allow user to select a gender (including "any" option)
    char *gender = selectGenderWithAny();
    // call function to allow user to select an ethnicity (including "any" option)
    char *ethnicity = selectEthnicityWithAny();

    // initialize sum to 0.0 for calculating the total salary
    float salarySum = 0.0;
    // initialize counter to 0 for counting matching employees
    int employeeCount = 0;

    // set current pointer to point to the first employee in the array
    struct Employee* current = employees;
    // set end pointer to point to one position past the last employee
    struct Employee* end = employees + count;

    // loop through all employees to find those matching the criteria
    while (current < end) {
        // check if gender matches: either "any" was selected or gender matches current employee
        int genderMatch = strcmp(gender, "any") == 0 || strcmp(current->gender, gender) == 0;
        // check if ethnicity matches: either "any" was selected or ethnicity matches current employee
        int ethnicityMatch = strcmp(ethnicity, "any") == 0 || strcmp(current->ethnicity, ethnicity) == 0;

        // if both criteria match, add the employee's salary to the sum
        if (genderMatch && ethnicityMatch) {
            // add current employee's salary to the running total
            salarySum += current->salary;
            // increment the count of matching employees
            employeeCount++;
        }
        // move pointer to the next employee in the array
        current++;
    }

    // check if at least one matching employee was found
    if (employeeCount > 0)
        // print the average salary and employee count
        printf("Average salary for %s and %s: $%.2f (Count: %d)\n", gender, ethnicity, salarySum / employeeCount,
               employeeCount);
    else
        // print message indicating no employees match the criteria
        printf("No employees found for %s and %s\n", gender, ethnicity);
}

// helper function to calculate average salary for specific gender and ethnicity criteria
// parameters: employees - pointer to the employee array, count - the number of employees
//             selGender - selected gender (can be "any"), selEthnicity - selected ethnicity (can be "any")
// returns: the calculated average salary, or 0.0 if no employees match
float calculateAverage(struct Employee *employees, int count, char* selGender, char* selEthnicity) {
    // initialize sum to 0.0 for calculating the total salary
    float salarySum = 0.0;
    // initialize counter to 0 for counting matching employees
    int employeeCount = 0;

    // set current pointer to point to the first employee in the array
    struct Employee* current = employees;
    // set end pointer to point to one position past the last employee
    struct Employee* end = employees + count;

    // loop through all employees to find those matching the criteria
    while (current < end) {
        // check if gender matches: either "any" was selected or gender matches current employee
        int genderMatch = strcmp(selGender, "any") == 0 || strcmp(current->gender, selGender) == 0;
        // check if ethnicity matches: either "any" was selected or ethnicity matches current employee
        int ethnicityMatch = strcmp(selEthnicity, "any") == 0 || strcmp(current->ethnicity, selEthnicity) == 0;

        // if both criteria match, add the employee's salary to the sum
        if (genderMatch && ethnicityMatch) {
            // add current employee's salary to the running total
            salarySum += current->salary;
            // increment the count of matching employees
            employeeCount++;
        }
        // move pointer to the next employee in the array
        current++;
    }

    // return the calculated average (or 0.0 if no employees match)
    return employeeCount > 0 ? salarySum / employeeCount : 0.0;
}

// function to display comparison results showing average salaries based on criteria
// parameters: employees - pointer to the employee array, count - the number of employees
// when "any" is selected for gender and/or ethnicity, it combines data across those categories
// this supports equity analysis by allowing comparison across demographic groups
void displayComparison(struct Employee *employees, int count) {
    // print section header
    printf("--- Comparison Results ---\n");

    // call function to allow user to select a gender (including "any" option)
    char *gender = selectGenderWithAny();
    // call function to allow user to select an ethnicity (including "any" option)
    char *ethnicity = selectEthnicityWithAny();

    // check if both gender and ethnicity are set to "any" (overall average needed)
    if (strcmp(gender, "any") == 0 && strcmp(ethnicity, "any") == 0) {
        // call helper function to calculate average across all employees
        float avg = calculateAverage(employees, count, "any", "any");
        // print overall average salary and total employee count
        printf("Overall average salary: $%.2f (Count: %d)\n", avg, count);
    } 
    // check if gender is "any" but ethnicity is specific (compare across all genders)
    else if (strcmp(gender, "any") == 0) {
        // call helper function to calculate average for all genders with selected ethnicity
        float avg = calculateAverage(employees, count, "any", ethnicity);
        // initialize counter for employees matching the ethnicity
        int empCount = 0;
        // set current pointer to point to the first employee in the array
        struct Employee* current = employees;
        // set end pointer to point to one position past the last employee
        struct Employee* end = employees + count;
        // loop through all employees to count those matching the selected ethnicity
        while (current < end) {
            // check if ethnicity matches the selected criteria
            if (strcmp(ethnicity, "any") == 0 || strcmp(current->ethnicity, ethnicity) == 0) {
                // increment the matching employee count
                empCount++;
            }
            // move pointer to the next employee in the array
            current++;
        }
        // print the average salary combining all genders with selected ethnicity
        printf("Average salary for all genders and %s: $%.2f (Count: %d)\n", ethnicity, avg, empCount);
    } 
    // check if ethnicity is "any" but gender is specific (compare across all ethnicities)
    else if (strcmp(ethnicity, "any") == 0) {
        // call helper function to calculate average for selected gender with all ethnicities
        float avg = calculateAverage(employees, count, gender, "any");
        // initialize counter for employees matching the gender
        int empCount = 0;
        // set current pointer to point to the first employee in the array
        struct Employee* current = employees;
        // set end pointer to point to one position past the last employee
        struct Employee* end = employees + count;
        // loop through all employees to count those matching the selected gender
        while (current < end) {
            // check if gender matches the selected criteria
            if (strcmp(gender, "any") == 0 || strcmp(current->gender, gender) == 0) {
                // increment the matching employee count
                empCount++;
            }
            // move pointer to the next employee in the array
            current++;
        }
        // print the average salary combining selected gender with all ethnicities
        printf("Average salary for %s and all ethnicities: $%.2f (Count: %d)\n", gender, avg, empCount);
    } 
    // both gender and ethnicity are specific (single group comparison)
    else {
        // call helper function to calculate average for specific gender and ethnicity
        float avg = calculateAverage(employees, count, gender, ethnicity);
        // initialize counter for employees matching both criteria
        int empCount = 0;
        // set current pointer to point to the first employee in the array
        struct Employee* current = employees;
        // set end pointer to point to one position past the last employee
        struct Employee* end = employees + count;
        // loop through all employees to count those matching both criteria
        while (current < end) {
            // check if both gender and ethnicity match the selected criteria
            if ((strcmp(gender, "any") == 0 || strcmp(current->gender, gender) == 0) &&
                (strcmp(ethnicity, "any") == 0 || strcmp(current->ethnicity, ethnicity) == 0)) {
                // increment the matching employee count
                empCount++;
            }
            // move pointer to the next employee in the array
            current++;
        }
        // check if any employees match both criteria
        if (empCount > 0) {
            // print the average salary for the selected gender and ethnicity
            printf("Average salary for %s and %s: $%.2f (Count: %d)\n", gender, ethnicity, avg, empCount);
        } else {
            // print message indicating no employees match the criteria
            printf("No employees found for %s and %s\n", gender, ethnicity);
        }
    }
}
