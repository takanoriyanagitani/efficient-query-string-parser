#pragma once

#include "bytes.h"
#include "skip_eq.h"
#include "skip_amp.h"

int eparser_get_value_c(bytes_t query_string, char c, bytes_t* value, size_t* offset){
  static int match = 0;
  static int found = 0;
  if(NULL == query_string.data) return 0;
  if(query_string.size < 1)     return 0;
  for(; *offset < query_string.size; (*offset)++){
    match = c == query_string.data[*offset];
    found = match ? eparser_skip_eq(query_string, offset) : eparser_skip_amp(query_string, offset);
    if(! found) return 0;
    switch(match){
      default: break;
      case 1:
        value->data = query_string.data + (1 + *offset);
        eparser_skip_amp(query_string, offset);
        value->size = (query_string.data + (1+*offset)) - value->data - 1;
        return 1;
    }
  }
  return 0;
}
