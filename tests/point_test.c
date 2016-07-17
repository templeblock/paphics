#include <stdlib.h>
#include <check.h>
#include <paphics/paphics.h>
#include <limits.h>

START_TEST(equals) {

    Point a;
    Point b;
    
    a.x = 3;
    a.y = 7;
    b.x = 3;
    b.y = 7;
    
    fail_unless(point_are_equals(a, b), "must be equals");
    
    b.y = 3545;
    b.x = 2133;
    a = b;
    
    fail_unless(point_are_equals(a, b), "must be equals");
}
END_TEST

START_TEST(not_equals) {

    Point a;
    Point b;
    
    a.x = 24;
    a.y = 1232;
    b.y = 24;
    b.y = 2321;
    
    fail_if(point_are_equals(a, b), "must not be equals");
    
    a.y = b.y;
    a.x = 242432;
    
    fail_if(point_are_equals(a, b), "must not be equals");
    
    a.x = 242;
    a.y = 2490;
    b.x = 203493;
    b.y = 2938;
    
    fail_if(point_are_equals(a, b), "must not be equals");
}
END_TEST

Suite* are_equals(void) {

    Suite* s;
    TCase* tc_core;
    
    s = suite_create("point_are_equals");
    
    /* Core test case */
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, equals);
    tcase_add_test(tc_core, not_equals);
    suite_add_tcase(s, tc_core);
    
    return s;
}

int main(void) {

    int number_failed = 0;
    
    Suite* s;
    SRunner* sr;
    
    s = are_equals();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
