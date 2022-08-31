#include <stdio.h> 
#include <math.h> 

int fact(int n){
  int a=1,c=1;
  while (a != n+1){
    c *= a;
    a ++;
  }return c;
     }

int main() { 
  double a = 0.0, b = 1.0, x = a, step, sum, d, e = 1.0, podstep, stepen; 
  int n, l; 
  while (1 + e / 2 > 1) 
    e /= 2; 
  printf("Машинное эпсилон = %.20f\n\n", e); 
  printf("Введите число разбиений отрезка [%1.1f, %1.1f]: ", a, b); 
  scanf("%d", &l); 
  step = (b - a) / l; 
  printf("\n==========================================================\n"); 
  printf("  l   x     сумма ряда sin(x)    функция sin(x)     итераций  \n"); 
   printf("\n==========================================================\n");  
  for (int i = 0; i <= l; i++) { 
    sum = 0; 
    n = 0; 
    podstep = x; 
    do { 
      stepen = ((n > 0) ? stepen * podstep * podstep * (-1) : podstep); 
      d = stepen / fact(2 * n + 1); 
      sum += d; 
      n++; 
    } while ((d > e || d < -e) && n < 100); 
    printf(" %2d %.2f %.18f %.18f %2d \n", i, x, sum, sin(x), n); 
    x += step; 
  } 
  printf("==========================================================\n"); 
}
