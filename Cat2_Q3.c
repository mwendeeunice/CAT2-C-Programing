/*
Name :Eunice Mwende
reg:CT100/G/26231/25
*/
#include <stdio.h>
#include <stdlib.h>

void write_integers(const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Error: cannot open %s for writing.\n", filename);
        return;
    }

    int num;
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num);
        fprintf(f, "%d\n", num);
    }

    fclose(f);
}

void compute_and_write_results(const char *input_file, const char *output_file) {
    FILE *fin = fopen(input_file, "r");
    FILE *fout = fopen(output_file, "w");
    if (!fin || !fout) {
        printf("File error.\n");
        if (fin) fclose(fin);
        if (fout) fclose(fout);
        return;
    }

    int sum = 0, num, count = 0;
    while (fscanf(fin, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    double avg = count ? (double)sum / count : 0;
    fprintf(fout, "Sum: %d\nAverage: %.2f\n", sum, avg);

    fclose(fin);
    fclose(fout);
}

void display_files(const char *input_file, const char *output_file) {
    char line[100];
    FILE *f;

    printf("\nContents of %s:\n", input_file);
    f = fopen(input_file, "r");
    while (f && fgets(line, sizeof(line), f))
        printf("%s", line);
    if (f) fclose(f);

    printf("\nContents of %s:\n", output_file);
    f = fopen(output_file, "r");
    while (f && fgets(line, sizeof(line), f))
        printf("%s", line);
    if (f) fclose(f);
}

int main() {
    write_integers("input.txt");
    compute_and_write_results("input.txt", "output.txt");
    display_files("input.txt", "output.txt");
    return 0;
}
