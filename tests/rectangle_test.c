#include <stdlib.h>
#include <check.h>
#include <paphics/paphics.h>

START_TEST(test_rectangle_contains_point) {

    Canvas root;
    Rectangle rect;
    Point p;
    
    root.size.x = 1000;
    root.size.y = 1000;
    
    rect.canvas = &root;
    rect.origin.x = 10;
    rect.origin.y = 10;
    rect.size.x = 10;
    rect.size.y = 10;
    
    p.x = 10;
    p.y = 10;
    
    fail_unless(rectangle_contains_point(&rect, &p), "should be true (1)");
    
    p.x = 19;
    p.y = 19;
    
    fail_unless(rectangle_contains_point(&rect, &p), "should be true (2)");
    
    p.x = 9;
    
    fail_if(rectangle_contains_point(&rect, &p), "should be false (3)");
    
    p.x = 10;
    p.y = 20;
    
    fail_if(rectangle_contains_point(&rect, &p), "should be false (4)");
}
END_TEST

Suite* suite_rectangle_contains_point(void) {

    Suite* s;
    TCase* tc_core;
    
    s = suite_create("suite_rectangle_contains_point");
    
    /* Core test case */
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_rectangle_contains_point);
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
