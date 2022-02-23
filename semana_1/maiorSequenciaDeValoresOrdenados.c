#include <stdio.h>

int main () {
  int sizeOfArray, maxCount = 1, currentCount = 1, firstIndex, lastIndex;
  scanf("%d", &sizeOfArray);

  int array[sizeOfArray];

  for (int i = 0; i < sizeOfArray; i++) {
    scanf("%d", &array[i]);
  }

  for (int i = 0; i < sizeOfArray - 1; i++) {
    if (array[i] <= array [i + 1]) {
      currentCount++;
    } else {
      if (currentCount > maxCount) {
        maxCount = currentCount;
        lastIndex = i;
        firstIndex = i + 1 - maxCount;
      }
      currentCount = 1;
    }
  }

  //caso a ultima sequencia seja a maior
  if (currentCount > maxCount) {
    lastIndex = sizeOfArray - 1;
    firstIndex = sizeOfArray - currentCount;
  }

  for (int i = firstIndex; i <= lastIndex; i++) {
    printf("%d ", array[i]);
  }
    printf("\n");

  return 0;
}