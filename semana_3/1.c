#include <stdio.h>

typedef struct Fracao Fracao;
struct Fracao {
  int denominador;
  int numerador;
};

int gcd(int n, int m) {
    int gcd, aux;

    while (n != 0)
    {
        aux = m % n;
        m = n;
        n = aux;
    }

    gcd = m;

    return gcd;
}

Fracao somar(Fracao f1, Fracao f2) {
    int numerador, denominador;
    Fracao result;

    result.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
    result.denominador = f1.denominador * f2.denominador;

    int number = gcd(result.numerador, result.denominador);

    result.denominador = result.denominador / number;
    result.numerador = result.numerador / number;

    return result;
}

Fracao somar_vetor(Fracao f[], int n_fracoes) {
    Fracao result;

    result.numerador = f[0].numerador * f[1].denominador + f[1].numerador * f[0].denominador;
    result.denominador = f[0].denominador * f[1].denominador;

    for (int i = 2; i < n_fracoes; i++) {
      result.numerador = result.numerador * f[i].denominador + f[i].numerador * result.denominador;
      result.denominador = result.denominador * f[i].denominador;
    }

    int number = gcd(result.numerador, result.denominador);

    result.denominador = result.denominador / number;
    result.numerador = result.numerador / number;

    return result;
}

Fracao multiplicar(Fracao f1, Fracao f2) {
    int numerador, denominador;
    Fracao result;

    result.numerador = f1.numerador * f2.numerador;
    result.denominador = f1.denominador * f2.denominador;

    int number = gcd(result.numerador, result.denominador);

    result.denominador = result.denominador / number;
    result.numerador = result.numerador / number;

    return result;
}

Fracao multiplicar_vetor(Fracao f[], int n_fracoes) {
    Fracao result = {f[0].numerador, f[0].denominador};

    for (int i = 1; i < n_fracoes; i++) {
      result.numerador = f[i].numerador * result.numerador;
      result.denominador = f[i].denominador * result.denominador;
    }

    int number = gcd(result.numerador, result.denominador);

    result.denominador = result.denominador / number;
    result.numerador = result.numerador / number;

    return result;
}



int main () {
  Fracao f1[3] = {{1,2},{3,5},{7,4}};
  Fracao result;
  result = somar_vetor(f1,3);
  printf("%d/%d\n", result.numerador, result.denominador);
}