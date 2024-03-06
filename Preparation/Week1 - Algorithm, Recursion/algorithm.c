/* 1 */ 
// #include <stdio.h>
// int modulo(int, int);
// int main() {
//     int a, b;
//     scanf("%d %d", &a, &b);
//     printf("%d", modulo(a, b));
//     return 0;
// }
// int modulo(int a, int b) {
//     while (a >= b) {
//         a -= b;
//     }
//     return a;
// }


/* 2 */
// #include <stdio.h>
// int mostones(int [][100], int);
// int main() {
//     int n, a[100][100];
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             scanf("%d", &a[i][j]);
//         }
//     }
//     printf("%d", mostones(a, n));
//     return 0;
// }
// int mostones(int a[][100], int n) {
//     int i = 0, j = 0, row = 0;
//     while (i < n && j < n) {
//         if (a[i][j]) {
//             row = i;
//             j++;
//         }
//         else {
//             i++;
//         }
//     }
//     return row;
// }


/* 3 */
// #include <stdio.h>
// #include <stdlib.h>
// int *prefixAverages1(int *, int);
// int *prefixAverages2(int *, int);
// int main() {
//     int n;
//     scanf("%d", &n);
//     int *x = malloc(sizeof(int) * n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", x + i);
//     }
//     int *a = prefixAverages1(x, n);
//     for (int i = 0; i < n; i++) {
//         printf("%d ", a[i]);
//     }
//     printf("\n");
//     a = prefixAverages2(x, n);
//     for (int i = 0; i < n; i++) {
//         printf("%d ", a[i]);
//     }
//     free(x);
//     free(a);
//     return 0;
// }
// int *prefixAverages1(int *x, int n) {
//     int *a = malloc(sizeof(int) * n);
//     for (int i = 0; i < n; i++) {
//         double sum = 0;
//         for (int j = 0; j <= i; j++) {
//             sum += x[j];
//         }
//         a[i] = (int) (sum / (i + 1) + 0.5);
//     }
//     return a;
// }
// int *prefixAverages2(int *x, int n) {
//     int *a = malloc(sizeof(int) * n);
//     double sum = 0;
//     for (int i = 0; i < n; i++) {
//         sum += x[i];
//         a[i] = (int) (sum / (i + 1) + 0.5);
//     }
//     return a;
// }