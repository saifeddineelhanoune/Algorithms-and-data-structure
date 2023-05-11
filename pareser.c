#include <stdio.h>
#include <string.h>
#include <math.h>

double evaluate(char* input, double z, double c) {
    // Remove any spaces from the input string
    char* p = input;
    char* q = input;
    while (*q != '\0') {
        if (*q != ' ') {
            *p++ = *q;
        }
        q++;
    }
    *p = '\0';

    // Find the position of the equals sign
    char* eq_pos = strchr(input, '=');
    if (eq_pos == NULL) {
        printf("Error: equals sign not found\n");
        return 0.0;
    }

    // Extract the function name and the expression
    char* func_name = strtok(input, "(");
    char* expr = eq_pos + 1;

    // Replace instances of the variable "z" with the provided value
    char* z_pos = strstr(expr, "z");
    while (z_pos != NULL) {
        char z_str[16];
        sprintf(z_str, "%.10g", z);
        int len_diff = strlen(z_str) - 1;
        memmove(z_pos + len_diff, z_pos + 1, strlen(z_pos));
        memcpy(z_pos, z_str, strlen(z_str));
        z_pos = strstr(z_pos + len_diff, "z");
    }

    // Replace instances of the constant "c" with the provided value
    char* c_pos = strstr(expr, "c");
    while (c_pos != NULL) {
        char c_str[16];
        sprintf(c_str, "%.10g", c);
        int len_diff = strlen(c_str) - 1;
        memmove(c_pos + len_diff, c_pos + 1, strlen(c_pos));
        memcpy(c_pos, c_str, strlen(c_str));
        c_pos = strstr(c_pos + len_diff, "c");
    }

    // Evaluate the expression using the math library
    double result = NAN;
    int status = sscanf(expr, "%lf", &result);
    if (status != 1) {
        printf("Error: invalid expression\n");
        return 0.0;
    }
    return result;
}

