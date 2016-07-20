#include <stdlib.h>
#include <check.h>
#include <paphics/paphics.h>

START_TEST(test_equals) {

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

START_TEST(test_not_equals) {

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

Suite* suite_are_equals(void) {

    Suite* s;
    TCase* tc_core;
    
    s = suite_create("suite_are_equals");
    
    /* Core test case */
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_equals);
    tcase_add_test(tc_core, test_not_equals);
    suite_add_tcase(s, tc_core);
    
    return s;
}

START_TEST(test_distance) {

    int i;
    
    Point a;
    Point b;
    
    a.x = 342;
    a.y = 2421;
    
    b = a;
    
    fail_unless(point_distance(a, b) == 0, "must be == 0");
    fail_unless(point_distance(b, a) == 0, "must be == 0");
    
    a.x = 1;
    a.y = 1;
    
    b.x = 1;
    b.y = 2;
    
    fail_unless(point_distance(a, b) == 1, "must be == 1");
    fail_unless(point_distance(b, a) == 1, "must be == 1");
    
    b.x = 0;
    b.y = 0;
    
    fail_unless(point_distance(a, b) == 1, "must be == 1");
    fail_unless(point_distance(b, a) == 1, "must be == 1");
    
    a.x = 3;
    a.y = 4;
    
    fail_unless(point_distance(a, b) == 5, "must be == 5");
    fail_unless(point_distance(b, a) == 5, "must be == 5");
    
    for (i = 0; i < 1000; i++) {
    
        a.x = calc_alea_int(-999, 999);
        a.y = calc_alea_int(-999, 999);
        b.x = calc_alea_int(-999, 999);
        b.y = calc_alea_int(-999, 999);
        
        fail_if(point_distance(a, b) < 0, "must be >= 0");
        fail_if(point_distance(b, a) < 0, "must be >= 0");
        
    }
    
}
END_TEST

Suite* suite_distance(void) {

    Suite* s;
    TCase* tc_core;
    
    s = suite_create("suite_distance");
    
    /* Core test case */
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_distance);
    suite_add_tcase(s, tc_core);
    
    return s;
}

START_TEST(test_max_x) {

    Point a;
    Point b;
    
    a.x = 0;
    a.y = 0;
    b.x = 0;
    b.y = 0;
    
    fail_unless(point_are_equals(point_max_x(a, b), b), "must be equals");
    fail_unless(point_are_equals(point_max_x(b, a), b), "must be equals");
    fail_unless(point_are_equals(point_max_x(a, b), a), "must be equals");
    fail_unless(point_are_equals(point_max_x(b, a), a), "must be equals");
    
    a.x = 1;
    
    fail_unless(point_are_equals(point_max_x(a, b), a), "must be equals");
    fail_unless(point_are_equals(point_max_x(b, a), a), "must be equals");
    
    a.y = -3453;
    
    fail_unless(point_are_equals(point_max_x(a, b), a), "must be equals");
    fail_unless(point_are_equals(point_max_x(b, a), a), "must be equals");
    
    a.y = 4554;
    
    fail_unless(point_are_equals(point_max_x(a, b), a), "must be equals");
    fail_unless(point_are_equals(point_max_x(b, a), a), "must be equals");
    
    b.x = a.x + 1;
    
    fail_unless(point_are_equals(point_max_x(a, b), b), "must be equals");
    fail_unless(point_are_equals(point_max_x(b, a), b), "must be equals");
}

END_TEST

START_TEST(test_max_y) {

    Point a;
    Point b;
    
    a.x = 0;
    a.y = 0;
    b.x = 0;
    b.y = 0;
    
    fail_unless(point_are_equals(point_max_y(a, b), b), "must be equals");
    fail_unless(point_are_equals(point_max_y(b, a), b), "must be equals");
    fail_unless(point_are_equals(point_max_y(a, b), a), "must be equals");
    fail_unless(point_are_equals(point_max_y(b, a), a), "must be equals");
    
    a.y = 1;
    
    fail_unless(point_are_equals(point_max_y(a, b), a), "must be equals");
    fail_unless(point_are_equals(point_max_y(b, a), a), "must be equals");
    
    a.x = -3453;
    
    fail_unless(point_are_equals(point_max_y(a, b), a), "must be equals");
    fail_unless(point_are_equals(point_max_y(b, a), a), "must be equals");
    
    a.x = 4554;
    
    fail_unless(point_are_equals(point_max_y(a, b), a), "must be equals");
    fail_unless(point_are_equals(point_max_y(b, a), a), "must be equals");
    
    b.y = a.y + 1;
    
    fail_unless(point_are_equals(point_max_y(a, b), b), "must be equals");
    fail_unless(point_are_equals(point_max_y(b, a), b), "must be equals");
}
END_TEST

START_TEST(test_min_x) {

    Point a;
    Point b;
    
    a.x = 0;
    a.y = 0;
    b.x = 0;
    b.y = 0;
    
    fail_unless(point_are_equals(point_min_x(a, b), a), "must be equals");
    fail_unless(point_are_equals(point_min_x(b, a), a), "must be equals");
    fail_unless(point_are_equals(point_min_x(a, b), b), "must be equals");
    fail_unless(point_are_equals(point_min_x(b, a), b), "must be equals");
    
    a.x = 1;
    
    fail_unless(point_are_equals(point_min_x(a, b), b), "must be equals");
    fail_unless(point_are_equals(point_min_x(b, a), b), "must be equals");
    
    a.y = -3453;
    
    fail_unless(point_are_equals(point_min_x(a, b), b), "must be equals");
    fail_unless(point_are_equals(point_min_x(b, a), b), "must be equals");
    
    a.y = 4554;
    
    fail_unless(point_are_equals(point_min_x(a, b), b), "must be equals");
    fail_unless(point_are_equals(point_min_x(b, a), b), "must be equals");
    
    b.x = a.x + 1;
    
    fail_unless(point_are_equals(point_min_x(a, b), a), "must be equals");
    fail_unless(point_are_equals(point_min_x(b, a), a), "must be equals");
}
END_TEST

START_TEST(test_min_y) {

    Point a;
    Point b;
    
    a.x = 0;
    a.y = 0;
    b.x = 0;
    b.y = 0;
    
    fail_unless(point_are_equals(point_min_y(a, b), a), "must be equals");
    fail_unless(point_are_equals(point_min_y(b, a), a), "must be equals");
    fail_unless(point_are_equals(point_min_y(a, b), b), "must be equals");
    fail_unless(point_are_equals(point_min_y(b, a), b), "must be equals");
    
    a.y = 1;
    
    fail_unless(point_are_equals(point_min_y(a, b), b), "must be equals");
    fail_unless(point_are_equals(point_min_y(b, a), b), "must be equals");
    
    a.x = -3453;
    
    fail_unless(point_are_equals(point_min_y(a, b), b), "must be equals");
    fail_unless(point_are_equals(point_min_y(b, a), b), "must be equals");
    
    a.x = 4554;
    
    fail_unless(point_are_equals(point_min_y(a, b), b), "must be equals");
    fail_unless(point_are_equals(point_min_y(b, a), b), "must be equals");
    
    b.y = a.y + 1;
    
    fail_unless(point_are_equals(point_min_y(a, b), a), "must be equals");
    fail_unless(point_are_equals(point_min_y(b, a), a), "must be equals");
}
END_TEST

Suite* suite_extremum(void) {

    Suite* s;
    TCase* tc_core;
    
    s = suite_create("suite_extremum");
    
    /* Core test case */
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_max_x);
    tcase_add_test(tc_core, test_max_y);
    tcase_add_test(tc_core, test_min_x);
    tcase_add_test(tc_core, test_min_y);
    suite_add_tcase(s, tc_core);
    
    return s;
}

int main(void) {

    int number_failed = 0;
    
    Suite* s;
    SRunner* sr;
    
    s = suite_are_equals();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    
    s = suite_distance();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    
    s = suite_extremum();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
