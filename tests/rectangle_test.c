#include <stdlib.h>
#include <check.h>
#include <paphics/paphics.h>

Suite* suite_rectangle_contains_point(void) {

    Suite* s;
    TCase* tc_core;
    
    s = suite_create("suite_rectangle_contains_point");
    
    /* Core test case */
    tc_core = tcase_create("Core");
    
    // tcase_add_test(tc_core, test_rectangle_contains_point);
    suite_add_tcase(s, tc_core);
    
    return s;
}

int main(void) {

    int number_failed = 0;
    
    Suite* s;
    SRunner* sr;
    
    s = suite_rectangle_contains_point();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
