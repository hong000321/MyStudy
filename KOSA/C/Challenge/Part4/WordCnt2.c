#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
  int a_cnt = 0, p_cnt = 0;
  char str[BUFSIZ];
  bool isFirst = true; 
  FILE* fp;

  if(argc < 1) {
    fprintf(stderr, "Usage : %s filename\n", argv[0]);
    return -1;
  }

  fp = fopen(argv[1], "rt");
  
  while(!feof(fp)) {
    str[0] = '\0';
    fgets(str, BUFSIZ, fp);
    for(int i = 0; i < strlen(str); i++) {
      char ch = str[i];
      if(isFirst) { 
        if (ch == 'A' || ch == 'a')
          a_cnt++;
        else if (ch == 'P' || ch == 'p') 
          p_cnt++;
        isFirst = false;
      }

      if(ch == ' ' || ch == '\t' || ch == '\n')
        isFirst = true;
      printf("%c", ch);
    }
  }

  printf("Count of words with A start: %d\n", a_cnt);
  printf("Count of words with P start: %d\n", p_cnt);

  fclose(fp);

  return 0;
}