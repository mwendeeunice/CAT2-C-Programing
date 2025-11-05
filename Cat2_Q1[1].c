/*
Name :Eunice Mwende
reg:CT100/G/26231/25
*/

#include <stdio.h>

void write_to_input_file() {
    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Error opening input.txt for writing.\n");
        return;
    }
    int integers[10];
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &integers[i]);
        fprintf(file, "%d\n", integers[i]);
    }
    fclose(file);
}

void calculate_and_write_to_output() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input.txt for reading.\n");
        return;
    }
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output.txt for writing.\n");
        fclose(input_file);
        return;
    }
    int sum = 0, count = 0, num;
    while (fscanf(input_file, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    double average = count > 0 ? (double)sum / count : 0;
    fprintf(output_file, "Sum: %d\nAverage: %.2f\n", sum, average);
    fclose(input_file);
    fclose(output_file);
}

void display_contents() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input.txt for reading.\n");
        return;
    }
    FILE *output_file = fopen("output.txt", "r");
    if (output_file == NULL) {
        printf("Error opening output.txt for reading.\n");
        fclose(input_file);
        return;
    }
    printf("Contents of input.txt:\n");
    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        printf("%c", ch);
    }
    printf("\nContents of output.txt:\n");
    while ((ch = fgetc(output_file)) != EOF) {
        printf("%c", ch);
    }
    fclose(input_file);
    fclose(output_file);
}

int main() {
    write_to_input_file();
    calculate_and_write_to_output();
    display_contents();
    return 0;
}
