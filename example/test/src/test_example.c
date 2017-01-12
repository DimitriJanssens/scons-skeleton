#include "test_example.h"

int main(int argc, char const *argv[])
{
  (void) argc;
  (void) argv;

  Suite * s = suite_create("Suite Example");

  suite_add_tcase(s, tcase_example());

  suite_run("EXAMPLE", s);
  
  return 0;
}
