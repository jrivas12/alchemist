#include <stdio.h>

void sortNums(int *a, int cnt);

int main(void)
{
    FILE *fptr = fopen("test.txt", "r");
    FILE *fp2 = fopen("sorted.txt", "w");

    if (fptr == NULL) {
        printf("Error: cannot open test.txt for reading.\n");
        return 1;
    }
    if (fp2 == NULL) {
        printf("Error: cannot open sorted.txt for writing.\n");
        fclose(fptr);
        return 1;
    }

    int a[100];
    int cnt = 0;

    // Read integers from test.txt
    while (fscanf(fptr, "%d", &a[cnt]) == 1) {
        cnt++;
    }
    fclose(fptr);

    // Sort the array
    sortNums(a, cnt);

    // Write sorted integers to sorted.txt
    for (int i = 0; i < cnt; i++) {
        fprintf(fp2, "%d\n", a[i]);
    }
    fclose(fp2);

    printf("Sorting complete. Output written to sorted.txt\n");
    return 0;
}

void sortNums(int *a, int cnt)
{
    int i, j, tmp;
    for (i = 1; i < cnt; i++) {
        tmp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > tmp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
}
