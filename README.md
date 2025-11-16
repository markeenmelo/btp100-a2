# BTP100- Introduction to Programming using C
## Assignment #2

### Assignment Topic: Pay Scale Comparison for Equity and Inclusion

The objective of this assignment is to create a program that collects a company's demographic data and pay scales, focusing on gender and BIPOC (Black, Indigenous, and People of Color) representation. This assignment will reinforce programming concepts such as functions, pointers, arrays, structs, iteration, selection, strings, and data types.

This assignment challenges you to apply your C programming skills to analyze and compare company data while bringing an awareness and fostering a deeper understanding of equity and inclusion issues in the workplace through quantitative analysis.

## Tasks

1. **Struct Definition:**
    - Define a `Employee` structure that includes the following fields:
        - Employee ID (integer)
        - Name (string)
        - Gender (string)
        - Ethnicity (string)
        - Salary (float)

    - Function Implementations:
        - Add a new employee - Implement a function to input employee data into an array of `Employee` structures.
        - Delete an employee - use employee ID.
        - Display employees - This can be based on gender and/or ethnicity or all employees in the company.
        - Search employee by ID.
        - Calculate average salaries based on gender and/or ethnicity for the company.
        - Display comparison results.

2. **Array of Employee Structures:**
    - Create an array of `Employee` structures to store multiple employee records.
    - Use pointer arithmetic to iterate through the array and access structure members.

3. **User Interface:**
    - Create a simple menu-driven interface using iterative constructs (loops) to allow users to input employee data, perform comparisons, and display the results.
    - Ensure user inputs are validated (e.g., gender input should be limited to "male", "female", "non-binary", etc.).

4. **Documentation and Reflection:**
    - Include comments in your code to explain each function and significant code block.
    - Write a short reflection (200 words) on the importance of equity, diversity, and inclusion in the workplace and how programming (software development) can contribute to analyzing and addressing these issues.
        - You may read Statistics Canada for more information: [The Daily — Intersectional Gender Wage Gap in Canada, 2007 to 2022](https://www.statcan.gc.ca)

## Submission Requirements

1. Work in groups of 3-4 people.
2. Submit your C source code file(s) (`.c` files) along with a document (`.docx`) containing your reflection.
3. Ensure your code is well-documented and adheres to C programming best practices.

## Grading Criteria

### Programming Component (80%)

1. **Functionality (60%)**
    - Meets all requirements stated.

2. **Code Quality (20%)**
    - Readability: Code is well-structured, with meaningful variable names and appropriate use of comments explaining major steps or calculations.
    - Error Handling: Handles potential errors gracefully.
    - Use appropriate programming concepts.
    - Critical thinking.

### Report Submission (20%)

1. **Cover Page (5%)**
    - Includes the names and student numbers of all group members.

2. **Reflection (10%)**
    - Importance of equity, diversity, and inclusion in the workplace.
    - How programming (software development) can contribute to analyzing and addressing these issues.

3. **Comments on Code Contribution (5%)**
    - Specifies which parts of the code each group member worked on, demonstrating collaboration and contribution from all members.

## Grading Scale

- **A (90-100%)**: Excellent implementation with accurate calculations, clear and well-commented code, and comprehensive report submission.
- **B (80-89%)**: Good implementation with minor errors or omissions in calculations or code quality, but overall meets functional requirements.
- **C (70-79%)**: Basic implementation that meets some functional requirements but lacks thoroughness in calculations, code quality, or report submission.
- **D (60-69%)**: Limited implementation with significant errors or omissions in calculations, code quality, or report submission.
- **F (Below 60%)**: Incomplete or incorrect implementation lacking essential components such as correct calculations, functioning code, or complete report submission.