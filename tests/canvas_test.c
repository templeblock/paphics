#include <stdlib.h>
#include <check.h>
#include <paphics/paphics.h>

START_TEST(test_canvas_collision_canvas) {

    Canvas c1;
    Canvas c2;
    
    c1.size.x = 100;
    c1.size.y = 10;
    
    c2.size.x = 20;
    c2.size.y = 200;
    
    c1.origin.x = 1000;
    c1.origin.y = 1000;
    
    c2.origin.x = 0;
    c2.origin.y = 0;
    
    fail_if(canvas_collision_canvas(&c1, &c2), "should not collide");
    fail_if(canvas_collision_canvas(&c2, &c1), "should not collide");
    
    c2.origin.x = 1000;
    
    fail_if(canvas_collision_canvas(&c1, &c2), "should not collide");
    fail_if(canvas_collision_canvas(&c2, &c1), "should not collide");
    
    c2.origin.x = 0;
    c2.origin.y = 1000;
    
    fail_if(canvas_collision_canvas(&c1, &c2), "should not collide");
    fail_if(canvas_collision_canvas(&c2, &c1), "should not collide");
    
    c2.origin.x = 2000;
    c2.origin.y = 0;
    
    fail_if(canvas_collision_canvas(&c1, &c2), "should not collide");
    fail_if(canvas_collision_canvas(&c2, &c1), "should not collide");
    
    c2.origin.y = 1000;
    
    fail_if(canvas_collision_canvas(&c1, &c2), "should not collide");
    fail_if(canvas_collision_canvas(&c2, &c1), "should not collide");
    
    c2.origin.y = 2000;
    
    fail_if(canvas_collision_canvas(&c1, &c2), "should not collide");
    fail_if(canvas_collision_canvas(&c2, &c1), "should not collide");
    
    c2.origin.x = 1000;
    
    fail_if(canvas_collision_canvas(&c1, &c2), "should not collide");
    fail_if(canvas_collision_canvas(&c2, &c1), "should not collide");
    
    c2.origin.x = 0;
    
    fail_if(canvas_collision_canvas(&c1, &c2), "should not collide");
    fail_if(canvas_collision_canvas(&c2, &c1), "should not collide");
    
    c2.origin.x = 980;
    c2.origin.y = 800;
    
    fail_if(canvas_collision_canvas(&c1, &c2), "should not collide");
    fail_if(canvas_collision_canvas(&c2, &c1), "should not collide");
    
    c2.origin.x = 981;
    
    fail_if(canvas_collision_canvas(&c1, &c2), "should not collide");
    fail_if(canvas_collision_canvas(&c2, &c1), "should not collide");
    
    c2.origin.x = 980;
    c2.origin.y = 801;
    
    fail_if(canvas_collision_canvas(&c1, &c2), "should not collide");
    fail_if(canvas_collision_canvas(&c2, &c1), "should not collide");
    
    c2.origin.x = 981;
    
    fail_unless(canvas_collision_canvas(&c1, &c2), "should collide");
    fail_unless(canvas_collision_canvas(&c2, &c1), "should collide");
    
    c2.origin.x = 981;
    c2.origin.y = 1009;
    
    fail_unless(canvas_collision_canvas(&c1, &c2), "should collide");
    fail_unless(canvas_collision_canvas(&c2, &c1), "should collide");
    
    c2.origin.x = 1099;
    c2.origin.y = 801;
    
    fail_unless(canvas_collision_canvas(&c1, &c2), "should collide");
    fail_unless(canvas_collision_canvas(&c2, &c1), "should collide");
    
    c2.origin.x = 1099;
    c2.origin.y = 1009;
    
    fail_unless(canvas_collision_canvas(&c1, &c2), "should collide");
    fail_unless(canvas_collision_canvas(&c2, &c1), "should collide");
}
END_TEST

Suite* suite_canvas_collision_canvas(void) {

    Suite* s;
    TCase* tc_core;
    
    s = suite_create("suite_canvas_collision_canvas");
    
    /* Core test case */
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_canvas_collision_canvas);
    suite_add_tcase(s, tc_core);
    
    return s;
}

int main(void) {

    int number_failed = 0;
    
    Suite* s;
    SRunner* sr;
    
    s = suite_canvas_collision_canvas();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
