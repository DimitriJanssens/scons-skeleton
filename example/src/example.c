#include "example.h"

Status_e example_function(uint64_t attribute)
{
  Status_e rc = STATUS_FAILURE;
  /* do something and change rc accordingly*/

  (void) attribute;
  rc = STATUS_SUCCESS;

  return rc;
}
