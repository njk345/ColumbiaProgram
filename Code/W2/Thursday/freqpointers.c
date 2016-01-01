#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toLower (char* s) {
  char *sptr = s;
  while (*sptr != '\0') {
    if (*sptr >= 65 && *sptr <= 90) {
      *sptr += 32;
    }
    sptr++;
  }
}

int main (void) {
  char s[30];
  int words = 0;
  int chars = 0;
  int vowels = 0;
  int digits = 0;
  int spaces = 0;  

  printf("Enter String:  ");
  fgets(s,30,stdin);

  toLower(s);

  char *aptr = s;
  while (*aptr != '\n') {
    if (*aptr == ' ') {
      spaces++;
      if (chars != 0) {
        if (*(aptr-1) != ' ') {
          words++;
        }
      }
    }
    
    else {
      if (*aptr >= 48 && *aptr <= 57) {
        digits++;
      } 
      else {
        chars++;
        if (*aptr == 'a' || *aptr == 'e' || *aptr == 'i' || *aptr == 'o' || *aptr == 'u') {
          vowels++; 
        }
      }
    }
    aptr++; //move to next index
}

if (*(aptr-1) != ' ') words++;

printf("\n%d Words\n",words);
printf("%d Characters\n",chars);
printf("%d Vowels\n",vowels);
printf("%d Digits\n",digits);
printf("%d Spaces\n",spaces);
return 0;
}




