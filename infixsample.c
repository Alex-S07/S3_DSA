#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Stack for operators (char type)
char operatorStack[MAX];
int operatorTop = -1;  // Index for the top of the operator stack

// Stack for operands (int type)
int operandStack[MAX];
int operandTop = -1;  // Index for the top of the operand stack

// Function to check the precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to check if the character is an operand (digit)
int isOperand(char c) {
    return isdigit(c);
}

// Function to perform basic arithmetic operations
int applyOperator(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int)pow(a, b);
        default: return 0;
    }
}

// Function to push an item to the operator stack
void pushOperator(char value) {
    if (operatorTop < MAX - 1) {
        operatorStack[++operatorTop] = value;
    }
}

// Function to pop an item from the operator stack
char popOperator() {
    if (operatorTop >= 0) {
        return operatorStack[operatorTop--];
    }
    return -1; // Return -1 if the stack is empty
}

// Function to push an item to the operand stack
void pushOperand(int value) {
    if (operandTop < MAX - 1) {
        operandStack[++operandTop] = value;
    }
}

// Function to pop an item from the operand stack
int popOperand() {
    if (operandTop >= 0) {
        return operandStack[operandTop--];
    }
    return -1; // Return -1 if the stack is empty
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    int k = 0;  // Index for the postfix string

    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isOperand(token)) {  // If token is an operand, add it to postfix
            postfix[k++] = token;
        } else if (token == '(') {  // If token is '(', push to stack
            pushOperator(token);
        } else if (token == ')') {  // If token is ')', pop until '('
            while (operatorTop != -1 && operatorStack[operatorTop] != '(') {
                postfix[k++] = popOperator();
            }
            popOperator();  // Pop '(' from stack
        } else {  // If token is an operator, pop operators from stack with higher or equal precedence
            while (operatorTop != -1 && precedence(operatorStack[operatorTop]) >= precedence(token)) {
                postfix[k++] = popOperator();
            }
            pushOperator(token);
        }
    }

    // Pop all remaining operators from the stack
    while (operatorTop != -1) {
        postfix[k++] = popOperator();
    }

    postfix[k] = '\0';  // Null-terminate the postfix expression
}

// Function to evaluate the postfix expression
int evaluatePostfix(char* postfix) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];

        if (isOperand(token)) {  // If token is an operand, push it onto the operand stack
            pushOperand(token - '0');  // Convert char to integer
        } else {  // If token is an operator, pop two operands, apply operator, and push result
            int b = popOperand();
            int a = popOperand();
            int result = applyOperator(a, b, token);
            pushOperand(result);
        }
    }

    return popOperand();  // The result will be the only element left in the stack
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
