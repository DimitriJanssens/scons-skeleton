#include <example/exampleIntf.h>

#include "example.h"

static ExampleIntf_t intf =
{
  #ifndef UNITTESTS
  .function = example_function,
  #else
  .function = NULL,
  #endif
};

ExampleIntf_t * getExampleIntf(void)
{
  return &intf;
}
