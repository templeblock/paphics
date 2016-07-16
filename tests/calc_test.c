#include <stdlib.h>
#include <check.h>
#include <paphics/paphics.h>

START_TEST(alea_float_range) {

    fail_if(calc_alea_float() < 0., "must be >= 0");
    fail_if(calc_alea_float() >= 1., "must be < 1");
}
END_TEST

START_TEST(alea_float_is_random) {

    fail_if(calc_alea_float() == calc_alea_float(), "doesn't seem random");
}
END_TEST

Suite* alea_float(void) {

    Suite* s;
    TCase* tc_core;

    s = suite_create("alea_float");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, alea_float_range);
    tcase_add_test(tc_core, alea_float_is_random);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {

    int number_failed;
    Suite* s;
    SRunner* sr;

    s = alea_float();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
