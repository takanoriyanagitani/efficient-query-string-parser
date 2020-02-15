#pragma once

#include "bytes.h"

int eparser_skip_amp(bytes_t query_string, size_t* offset){
  if(NULL == query_string.data) return 0;
  if(query_string.size < 1)     return 0;
  for(; *offset < query_string.size; (*offset)++){
    switch(query_string.data[*offset]){
      default: continue;
      case '&': return 1;
    }
  }
  return 0;
}
