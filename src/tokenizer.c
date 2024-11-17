#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c) {
    return c == ' ' || c == '\t';
}

int non_space_char(char c){
  return !space_char(c);
}

char *token_start(char *str){
  while (*str && space_char(*str)){
    str++;
  }
  return (*str) ? str : NULL;
}

char *token_terminator(char *token){
  while (*token && non_space_char(*token)){
    token++;
  }
  return token;
}
