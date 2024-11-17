#include <stdio.h>
#include <stdlib.h>  // Para free
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

int count_tokens(char *str){
  int count = 0;
  while ((str = token_start(str))){
    count++;
    str = token_terminator(str);
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char *copy = malloc((len + 1) * sizeof(char));
  if (!copy){
    return NULL;
  }
  strncpy(copy, inStr, len);
  copy[len] = '\0';
  return copy;
}
