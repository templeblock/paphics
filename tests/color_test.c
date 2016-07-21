#include <stdlib.h>
#include <check.h>
#include <paphics/paphics.h>

START_TEST(test_color_get_red) {

    Color col;
    
    col.rgb = 0x000000;
    
    fail_if(color_get_red(&col) != 0x00, "must be 0x00");
    
    col.rgb = (Uint32) 0xFFFFFF;
    
    fail_if(color_get_red(&col) != 0xFF, "must be 0xFF");
    
    col.rgb = 0x123456;
    
    fail_if(color_get_red(&col) != 0x12, "must be 0x12");
    
    col.rgb = 0xF4D94C;
    
    fail_if(color_get_red(&col) != 0xF4, "must be 0xF4");
    
}
END_TEST

START_TEST(test_color_get_green) {

    Color col;
    
    col.rgb = 0x000000;
    
    fail_if(color_get_green(&col) != 0x00, "must be 0x00");
    
    col.rgb = 0xFFFFFF;
    
    fail_if(color_get_green(&col) != 0xFF, "must be 0xFF");
    
    col.rgb = 0x123456;
    
    fail_if(color_get_green(&col) != 0x34, "must be 0x34");
    
    col.rgb = 0xF4D94C;
    
    fail_if(color_get_green(&col) != 0xD9, "must be 0xD9");
    
}
END_TEST

START_TEST(test_color_get_blue) {

    Color col;
    
    col.rgb = 0x000000;
    
    fail_if(color_get_blue(&col) != 0x00, "must be 0x00");
    
    col.rgb = 0xFFFFFF;
    
    fail_if(color_get_blue(&col) != 0xFF, "must be 0xFF");
    
    col.rgb = 0x123456;
    
    fail_if(color_get_blue(&col) != 0x56, "must be 0x56");
    
    col.rgb = 0xF4D94C;
    
    fail_if(color_get_blue(&col) != 0x4C, "must be 0x4C");
    
}
END_TEST

Suite* suite_color_get_rgb(void) {

    Suite* s;
    TCase* tc_core;
    
    s = suite_create("suite_color_get_rgb");
    
    /* Core test case */
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_color_get_red);
    tcase_add_test(tc_core, test_color_get_green);
    tcase_add_test(tc_core, test_color_get_blue);
    
    suite_add_tcase(s, tc_core);
    
    return s;
}

int main(void) {

    int number_failed = 0;
    
    Suite* s;
    SRunner* sr;
    
    s = suite_color_get_rgb();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
