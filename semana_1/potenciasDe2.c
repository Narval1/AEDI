#include <stdio.h>

int main() {
  int sequenceLength, number, counter = 0;
  scanf("%d", &sequenceLength);

  for (int index = 0; index < sequenceLength; index++) {
    scanf("%d", &number);
    if (number >= 2) {
      int temporary = 1;
      while (temporary < number) {
        temporary = temporary * 2;
        if (temporary == number) counter++;
      }
    }
  }

  printf("%d\n", counter);
  return 0;
}