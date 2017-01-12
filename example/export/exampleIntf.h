#ifndef EXAMPLEINTF_H
#define EXAMPLEINTF_H

#include <common/commontypes.h>

typedef struct
{
  /* function pointers will point to implementations */
  /* make functions testable: return SUCCESS or FAILURE */
  Status_e (*function)(uint64_t attribute);
} ExampleIntf_t;

ExampleIntf_t * getExampleIntf(void);

#endif
