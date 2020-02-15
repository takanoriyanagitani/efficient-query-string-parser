#include <stdio.h>

#include <string.h>

#include "skip_eq.h"

int test(const char* query_string, const char* expected){
  char buf[1024] = {0};
  if(NULL != query_string) strncpy(buf, query_string, 1023);
  bytes_t s = {0};
  s.size = strlen(buf);
  s.data = (uint8_t*)buf;

  size_t offset = 0;
  int rc = eparser_skip_eq(s, &offset);
  snprintf(buf, 1024, "rc:%d,offset:%ld", rc, offset);
  return 0 == strncmp(buf, expected, 1023) ? 0 : 0 < fprintf(stdout, "actual:%s != expected: %s\n", buf, expected);
}

int main(int argc, char** argv){
  switch(argc){
    default: return test(NULL,    "rc:0,offset:0");
    case  3: return test(argv[1], argv[2]);
  }
}
