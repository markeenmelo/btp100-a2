// Max: function prototypes for other parts of the program (Tyler/Marcos can implement these)
void clearInputBuffer(void);  // Max: used to safely clear leftover input
void addEmployee(struct employee *list, int *count);            // Max: adds a new employee
void removeEmployee(struct employee *list, int *count);         // Max: removes an employee by ID
void displayEmployees(struct employee *list, int count);        // Max: shows employees (with filters)
void searchEmployeeByID(struct employee *list, int count);      // Max: finds and prints one employee
void computeAverages(struct employee *list, int count,          // Max: calculates average salaries
                     float *maleAvg, float *femaleAvg,
                     float *bipocAvg, float *nonBipocAvg);
void salaryAnalysis(float maleAvg, float femaleAvg,             // Max: prints comparison results
                    float bipocAvg, float nonBipocAvg);

// Max: your own helper to print the menu options
void printMenu(void);  // Max: just prints the text menu on screen

// Max: main function that controls the entire program and menu flow
int main(void) {
    struct employee employees[50];  // Max: array to store up to 50 employees in memory
    int count = 0;                  // Max: tracks how many employees are currently in the list
    int choice;                     // Max: stores the user’s menu selection

    // Max: simple program title banner
    printf("==============================================\n");
    printf(" Pay Scale Comparison for Equity and Inclusion\n");
    printf("==============================================\n");

    // Max: main loop keeps running until user chooses 0 (Exit)
    do {
        printMenu();                // Max: show the menu options each time

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {  // Max: validate that input is an integer
            clearInputBuffer();           // Max: clear invalid input from buffer
            printf("Invalid input. Please enter a number.\n");
            continue;                     // Max: go back to top of loop without doing anything else
        }
        clearInputBuffer();               // Max: clear any leftover characters (like newline)

        // Max: handle different menu choices using switch
        switch (choice) {
            case 1:
                // Max: let teammate function add a new employee
                addEmployee(employees, &count);
                break;

            case 2:
                // Max: let teammate function remove an employee by ID
                removeEmployee(employees, &count);
                break;

            case 3:
                // Max: show employees (all or filtered) using the display function
                displayEmployees(employees, count);
                break;

            case 4:
                // Max: search for a single employee by ID
                searchEmployeeByID(employees, count);
                break;

            case 5: {
                // Max: calculate averages and pass them into the analysis function
                float maleAvg = 0.0f;
                float femaleAvg = 0.0f;
                float bipocAvg = 0.0f;
                float nonBipocAvg = 0.0f;

                // Max: call computeAverages to fill in the four average values
                computeAverages(employees, count,
                                &maleAvg, &femaleAvg,
                                &bipocAvg, &nonBipocAvg);

                // Max: call salaryAnalysis to compare and print messages about pay gaps
                salaryAnalysis(maleAvg, femaleAvg, bipocAvg, nonBipocAvg);
                break;
            }
            case 0:
                // Max: exit option
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                // Max: handles any number that is not 0–5
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);  // Max: repeat until user chooses 0

    return 0;               // Max: signal that program ended successfully
}
// Max: helper function that prints the menu options
void printMenu(void) {
    printf("\nMenu:\n");                                       // Max: label for the menu block
    printf("1. Add employee\n");                               // Max: option to add a new employee
    printf("2. Remove employee\n");                            // Max: option to delete an employee
    printf("3. Display employees (with filters)\n");           // Max: option to view employee list
    printf("4. Search employee by ID\n");                      // Max: option to find one employee
    printf("5. Salary comparison & averages\n");               // Max: option to run equity analysis
    printf("0. Exit\n");                                       // Max: option to quit the program
}
