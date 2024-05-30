#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int priority(char c) {
    if (c == '(' || c == ')')
        return 0;
    else if (c == '*' || c == '/' || c == '%')
        return 1;
    else if (c == '+' || c == '-')
        return 2;
    else if (strchr("<>=", c) != NULL)
        return 3;
    else if (strchr("==!", c) != NULL)
        return 4;
    else if (c == '&')
        return 5;
    else if (c == '^')
        return 6;
    else if (c == '|')
        return 7;
    else
        return -1;
}

int isOperator(char c) {
    return (strchr("^*|/+%&|!<>=", c) != NULL);
}

void infixToPostfix(char* infix) {
    char stack[100];
    int top = -1;
    char postfix[100];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == ' ')
            continue;

        if (((infix[i] >= '0' && infix[i] <= '9') || (infix[i] >= 'a' && infix[i] <= 'z'))) {
            postfix[j] = infix[i];
            j++;
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j] = stack[top];
                j++;
                top--;
            }
            top--;
        } else if (isOperator(infix[i])) {
            while (top != -1 && priority(infix[i]) <= priority(stack[top])) {
                postfix[j] = stack[top];
                j++;
                top--;
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) {
        postfix[j] = stack[top];
        j++;
        top--;
    }

    postfix[j] = '\0';
    printf("%s\n", postfix);
}

int main() {
    char infix[100];
    printf("Input infix expression: ");
    fgets(infix, 100, stdin);
    infixToPostfix(infix);
    return 0;
}
