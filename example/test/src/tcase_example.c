#include "test_example.h"

#include "example.h"

START_TEST (test_function)
{
  const ExampleIntf_t * const intf = getExampleIntf();
  ck_assert(intf->function(3600) == STATUS_SUCCESS);
}
END_TEST

static void localSetup(void)
{
  getExampleIntf()->function = example_function;
}

static void localTeardown(void)
{
  getExampleIntf()->function = NULL;
}

TCase * tcase_example(void)
{
  TCase *tc = tcase_create("A name used for debugging/logging");
  tcase_set_timeout(tc, 10);
  tcase_add_valgrind_fixtures(tc);
  tcase_add_checked_fixture(tc, localSetup, localTeardown);

  tcase_add_test(tc, test_function);

  return tc;
}
