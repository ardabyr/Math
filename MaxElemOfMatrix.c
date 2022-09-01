#include <stdio.h>    
#include <stdlib.h>    

int task(double znach[], int ind[], int t, int m, int n) {
    double maxi = -10000;
    int nomer_str, k = 0, j = 0;
    for (int i = 0; i < t; i++) {
        double d = znach[i];
        if (d < 0) {
            d = d * -1;
        }
        if (d > maxi) {
            maxi = d;
            j = i;
        }
    }
    int id = ind[j];
    nomer_str = id / m;
    for (int i = 0; i < t; i++) {
        if ((ind[i] / m) == nomer_str) {
            znach[i] = znach[i] / maxi;
        }
    }
    int n_m = nomer_str + 1;
    printf("%lf - максимальный элемент, %d - строка в которой он находится\n", maxi, n_m);
    for (int i = 0; i < m * n; i++) {
        if (k < t && i == ind[k]) {
            printf("%.4lf\t", znach[k]);
            k++;
        }
        else {
            printf("0\t");
        }
        if ((m + i) % m == (m - 1)) {
            printf("\n");
        }


    }
}

int main(int argc, char* argv[]) {
    FILE* f;
    int n, m = 0;
    f = fopen(argv[1], "r");
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &m);
    int ind[m * n];
    double znach[m * n];
    double q = 0;
    int t = 0;
    for (int i = 0; i < m * n; i++) {
        fscanf(f, "%lf", &q);
        if (q != 0.) {
            ind[t] = i;
            znach[t] = q;
            t++;
        }
    }
    int k = 0;
    int choose, g = 1;
    while (g) {
        printf("1.Print input matrix\t 2. Task\t 3. Exit \n");
        scanf("%d", &choose);
        switch (choose) {
        case 1: {
            for (int i = 0; i < m * n; i++) {
                if (k < t && i == ind[k]) {
                    printf("%.4lf\t", znach[k]);
                    k++;
                }
                else {
                    printf("0\t");
                }
                if ((m + i) % m == (m - 1)) {
                    printf("\n");
                }

            }
            printf("--------------------------------\n");
            break;
        }
        case 2: {
            task(znach, ind, t, m, n);
            break;
        }
        case 3: {
            g = 0;
            break;
        }
        default: {
            printf("Wrong input\n");
        }
        }
    }
    return 0;
}
