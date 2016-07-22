#include <stdlib.h>
#include <check.h>
#include <paphics/paphics.h>

START_TEST(test_event_create) {

    Event input;
    
    event_create(&input);
    
    fail_if(input.quit, "sould be false");
    fail_unless(input.arrows.x == 0, "should be == 0");
    fail_unless(input.arrows.y == 0, "should be == 0");
    fail_if(input.space, "sould be false");
}
END_TEST

Suite* suite_event_create(void) {

    Suite* s;
    TCase* tc_core;
    
    s = suite_create("suite_event_create");
    
    /* Core test case */
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_event_create);
    suite_add_tcase(s, tc_core);
    
    return s;
}

int main(void) {

    int number_failed = 0;
    
    Suite* s;
    SRunner* sr;
    
    s = suite_event_create();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
