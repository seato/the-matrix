#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>
#include<string.h>

#ifndef _DEBUG_H
#define _DEBUG_H

#define DEFAULT "\033[0m"
#define BLACK "\033[22;30m"
#define RED "\033[22;31m"
#define GREEN "\033[22;32m"
#define BROWN "\033[22;33m"
#define BLUE "\033[22;34m"
#define MAGENTA "\033[22;35m"
#define CYAN "\033[22;36m"
#define GRAY "\033[22;37m"
#define DARK_GRAY "\033[01;30m"
#define LIGHT_RED "\033[01;31m"
#define LIGHT_GREEN "\033[01;32m"
#define YELLOW "\033[01;33m"
#define LIGHT_BLUE "\033[01;34m"
#define LIGHT_MAGENTA "\033[01;35m"
#define LIGHT_CYAN "\033[01;36m"
#define WHITE "\033[01;37m"

void changeColor(char * color);

#endif
