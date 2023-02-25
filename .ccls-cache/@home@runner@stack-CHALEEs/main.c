#include "node.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  int i, j, temp, temp2;
  Stack s;
  s.top = NULL;
  s.size = 0;
  /*for(i = 1 ;i < argc;i++){
      pushs(&s,atoi(argv[i]));
  }
  pop_all(&s);
*/

  printf("Checking the parentheses in argv arguments\n");
  for (i = 1; i < argc; i++) {
    temp = 0;
    temp2 = 0;
    // printf("%d", argc);
    for (j = 0; j < strlen(argv[i]); j++) {
      // Use stack to help with the parentheses
      switch (argv[i][j]) {
      case '{':
        // pushs(&s, argv[i][j]);
        // break;
      case '[':
        push(&s, argv[i][j]);
        break;
      case ']':
        if (s.size == 0)
          temp2 = 1;
        else if(pop(&s) != '[')
          temp = 1;
        break;
      case '}':
        if (s.size == 0)
          temp2 = 1;
        if(pop(&s) != '{')
          temp = 1;
        break;
      }
      if (temp == 1 || temp2 == 1)
        break;
    }
    if(temp2 == 1){
      printf("argv %d incorrect: too many close parenthesis\n",i);
    }
    else if(temp == 1){
      printf("argv %d incorrect: mismatch\n", i);
    }
    else if (s.size > 0) {
      printf("argv %d incorrect: too many open parenthesis\n", i);
      pop_all(&s);
    }
    else {
      printf("argv %d correct\n", i);
    }
  }

  return 0;

}