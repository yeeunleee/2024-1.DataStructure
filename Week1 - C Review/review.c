// 1
// #include <stdio.h>
// int sum (int n) {
//     int result = 0;
//     for (int i = 1; i <= n; i++) {
//         result += i;
//     }
//     return result;
// }
// int main() {
//     int x, result = 0;
//     scanf("%d", &x);
//     for (int i = 1; i <= x; i++) {
//         result += sum(i);
//     }
//     printf("%d\n", result);
//     return 0;
// }


// 2
// #include <stdio.h>
// void ABC(int *x, int k) {
//     int max = x[k], maxidx = k;
//     for (int i = k; i < 10; i++) {
//         if (x[i] > max) {
//             max = x[i];
//             maxidx = i;
//         }
//     }
//     int tmp = x[maxidx];
//     x[maxidx] = x[k];
//     x[k] = tmp;
// }
// int main() {
//     int x[10];
//     for (int i = 0; i < 10; i++) {
//         scanf("%d", &x[i]);
//     }
//     for (int k = 0; k < 9; k++) {
//         ABC(x, k);
//     }
//     for (int i = 0; i < 10; i++) {
//         printf(" %d", x[i]);
//     }
//     return 0
// }


// 3
// #include <stdio.h>
// void swap(int *a, int *b) {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }
// int main() {
//     int n, i, x[50], a, b;
//     scanf("%d", &n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &x[i]);
//     }
//     scanf("%d %d", &a, &b);
//     swap(x + a, x + b);
//     for (i = 0; i < n; i++) {
//         printf(" %d", x[i]);
//     }
//     return 0;
// }

// 4
// #include <stdio.h>
// #include <string.h>
// int main() {
//     char str[101];
//     scanf("%s", str);
//     int len = strlen(str);
//     for (int i = 0; i < len; i++) {
//         printf("%s\n", str);

//         char tmp = str[0];
//         for (int j = 0; j < len - 1; j++) {
//             str[j] = str[j + 1];
//         }
//         str[len - 1] = tmp;
//     }
//     return 0;
// }


// 5
// #include <stdio.h>
// typedef struct {
//     int h, m, s;
// } TIME;
// int main() {
//     TIME a, b;
//     int secondA, secondB, result, h, m, s;
//     scanf("%d %d %d", &a.h, &a.m, &a.s);
//     scanf("%d %d %d", &b.h, &b.m, &b.s);
//     secondA = a.h * 60 * 60 + a.m * 60 + a.s;
//     secondB = b.h * 60 * 60 + b.m * 60 + b.s;
//     result = secondB - secondA;
//     h = result / 3600;
//     m = result % 3600 / 60;
//     s = result % 3600 % 60;
//     printf("%d %d %d\n", h, m, s);
//     return 0;
// }


// 6
// #include <stdio.h>
// typedef struct {
//     char name[10];
//     double score;
// } ST;
// int main() {
//     ST st[5];
//     double avg = 0;
//     for (int i = 0; i < 5; i++) {
//         scanf("%s %lf", st[i].name, &st[i].score);
//         avg += st[i].score;
//     }
//     avg /= 5;
//     for (int i = 0; i < 5; i++) {
//         if (st[i].score <= avg) {
//             printf("%s\n", st[i].name);
//         }
//     }
//     return 0;
// }


// 7
// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     int n, *a, *b;
//     scanf("%d", &n);
//     a = (int *) malloc(sizeof(int) * n);
//     b = (int *) malloc(sizeof(int) * n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &b[i]);
//     }
//     for (int i = 0; i < n; i++) {
//         a[i] += b[n - i - 1];
//     } 
//     for (int i = 0; i < n; i++) {
//         printf(" %d", a[i]);
//     }
//     free(a);
//     free(b);
//     return 0;
// }


// 9
// #include <stdio.h>
// #include <stdlib.h>
// typedef struct {
//     char name[8];
//     int k, e, m;
//     double avg;
// } ST;
// int main() {
//     int n;
//     scanf("%d", &n);
//     ST *st = (ST *) malloc(sizeof(ST) * n);
//     for (int i = 0; i < n; i++) {
//         scanf("%s %d %d %d", st[i].name, &st[i].k, &st[i].e, &st[i].m);
//         st[i].avg = (double)(st[i].k + st[i].e + st[i].m) / 3.0;
//     }
//     for (int i = 0; i < n; i++) {
//         printf("%s %.1lf ", st[i].name, st[i].avg);
//         if (st[i].k >= 90 || st[i].e >= 90 || st[i].m >= 90) {
//             printf("GREAT ");
//         }
//         if (st[i].k < 70 || st[i].e < 70 || st[i].m < 70) {
//             printf("BAD ");
//         }
//         printf("\n");
//     }
//     free(st);
//     return 0;
// }