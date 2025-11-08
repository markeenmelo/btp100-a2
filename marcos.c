#include <stdio.h>
#define MAX_EMPLOYEES 10

struct Employee {
    int id;
    char name[50];
    char gender[20];
    char ethnicity[20];
    float salary;
};


float calculateAverageSalary(struct Employee *employees, const char *targetGender, const char *targetEthnicity);
void displayComparison(struct Employee *employees);
int areStringsEqual(const char *str1, const char *str2);

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
    displayComparison(employees);
    return 0;
}

int areStringsEqual(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) return 0;
        i++;
    }
    return 1;
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