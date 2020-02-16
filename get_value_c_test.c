#include <stdio.h>

#include <string.h>

#include "get_value_c.h"

int test(const char c, const char* query_string, const char* expected){
  char buf[1024] = {0};
  if(NULL != query_string) strncpy(buf, query_string, 1023);
  bytes_t s = {0};
  s.size = strlen(buf);
  s.data = (uint8_t*)buf;

  size_t offset = 0;
  bytes_t v = {0};
  int rc = eparser_get_value_c(s, c, &v, &offset);
  char tbuf[1024] = {0};
  snprintf(tbuf, 1024, "rc:%d,offset:%ld,size:%ld,val:%.*s", rc, offset, v.size, (int)v.size, v.data);
  return 0 == strncmp(tbuf, expected, 1023) ? 0 : 0 < fprintf(stdout, "actual:%s != expected: %s\n", tbuf, expected);
}

int main(int argc, char** argv){
  switch(argc){
    default: return test('\0',       NULL,    "rc:0,offset:0,size:0,val:");
    case  4: return test(argv[1][0], argv[2], argv[3]);
  }
}
