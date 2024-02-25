/* 1 */
// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     int n, m, *x, i, j;
//     scanf("%d", &n);
//     x = (int *) malloc(sizeof(int) * n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &x[i]);
//     }
//     scanf("%d", &m);
//     for (i = 0; i < m; i++) {
//         int a, b, tmp;
//         scanf("%d %d", &a, &b);
//         for (j = 0; j <= (b - a) / 2; j++) {
//             tmp = x[a + j];
//             x[a + j] = x[b - j];
//             x[b - j] = tmp;
//         }
//     }
//     for (i = 0; i < n; i++) {
//         printf(" %d", x[i]);
//     }
//     free(x);
//     return 0;
// }


/* 2 */
// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     int n, m, *x, i, j, *change, tmp;
//     scanf("%d", &n);
//     x = (int *) malloc(sizeof(int) * n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &x[i]);
//     }
//     scanf("%d", &m);
//     change = (int *) malloc(sizeof(int) * m);
//     for (i = 0; i < m; i++) {
//         scanf("%d", &change[i]);
//     }
//     if (m > 2) {
//     for (i = m - 2; i >= 0; i--) {
//         if (i == m - 2) tmp = x[change[i]];
//         else {
//             x[change[i + 1]] = x[change[i]];
//         }
//     }
//         x[change[0]] = tmp;
//     }
//     for (i = 0; i < n; i++) {
//         printf(" %d", x[i]);
//     }
//     free(x);
//     free(change);
//     return 0;
// }


/* 2 다른 풀이 */
// #include <stdio.h>
// int main() {
//     int x[100], idx, n, m, i, tmp1, tmp2;
//     scanf("%d", &n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &x[i]);
//     }
//     scanf("%d", &m);
//     for (i = 0; i < m; i++) {
//         scanf("%d", &idx);
//         tmp1 = x[idx];
//         if (i != 0) {
//             x[idx] = tmp2;
//         }
//         tmp2 = tmp1;
//     }
//     for (i = 0; i < n; i++) {
//         printf(" %d", x[i]);
//     }
// }


/* 3 */
// #include <stdio.h>
// int main() {
//     int n, x[100][100], i, j, num;
//     scanf("%d", &n);
//     for (i = 0, num = 1; i < n; i++) {
//         if (i % 2) {
//             for (j = n - 1; j >= 0; j--) {
//                 x[i][j] = num++;
//             }
//         }
//         else {
//             for (j = 0; j < n; j++) {
//                 x[i][j] = num++;
//             }
//         }
//     }
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < n; j++) {
//             printf(" %d", x[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }


/* 4 */
// #include <stdio.h>
// int main() {
//     int n, m, arr[100][100] = { 0, };
//     scanf("%d %d", &n, &m);

//     int i = 0, j = -1, k, row = n - 1, col = m, flag = 1, num = 1;
//     while(1) {
//         for (k = 0; k < col; k++) {
//             j += flag;
//             arr[i][j] = num++;
//         }
//         if (row < 1 || col < 1) break;
//         for (k = 0; k < row; k++) {
//             i += flag;
//             arr[i][j] = num++;
//         }
//         flag *= -1;
//         row--, col--;
//     }
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < m; j++) {
//             printf(" %3d", arr[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }


/* 5 */
// #include <stdio.h>
// int main() {
//     int n, m, arr[100][100] = { 0, }, num = 1;
//     scanf("%d %d", &n, &m);

//     int x = 0, y = 0, row = n, col = m, i, j, k;
//     for (k = 0; k < n + m; k++) {
//         for (i = 0; i < n; i++) {
//             int j = k - i;
//             if (0 <= j && j < m) {
//                 arr[i][j] = num++;
//             }
//         }
//     }
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < m; j++) {
//             printf(" %d", arr[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }