/********************************************************************************/
/*******************************  Debug.c  **************************************/
/********************************************************************************/

#include "../include/Debug.h"

void changeColor(char * color)
{
  if((NULL == color) || (0 == strcmp("", color)) ||
     (0 == strcmp("default", color)))
    printf(DEFAULT);
  else if((0 == strcmp("black", color)))
    printf(BLACK);
  else if((0 == strcmp("red", color)))
    printf(RED);
  else if((0 == strcmp("green", color)))
    printf(GREEN);
  else if((0 == strcmp("brown", color)))
    printf(BROWN);
  else if((0 == strcmp("blue", color)))
    printf(BLUE);
  else if((0 == strcmp("magenta", color)))
    printf(MAGENTA);
  else if((0 == strcmp("cyan", color)))
    printf(CYAN);
  else if((0 == strcmp("gray", color)))
    printf(GRAY);
  else if((0 == strcmp("dark_gray", color)))
    printf(DARK_GRAY);
  else if((0 == strcmp("light_red", color)))
    printf(LIGHT_RED);
  else if((0 == strcmp("light_green", color)))
    printf(LIGHT_GREEN);
  else if((0 == strcmp("yellow", color)))
    printf(YELLOW);
  else if((0 == strcmp("light_blue", color)))
    printf(LIGHT_BLUE);
  else if((0 == strcmp("light_magenta", color)))
    printf(LIGHT_MAGENTA);
  else if((0 == strcmp("light_cyan", color)))
    printf(LIGHT_CYAN);
  else if((0 == strcmp("white", color)))
    printf(WHITE);
  else
  {
    printf(RED);
    printf("Debug.c: %s ain't a valid color you buffoon.\n", color);
    printf(DEFAULT);
  }
}
