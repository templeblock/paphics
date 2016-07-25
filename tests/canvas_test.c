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

START_TEST(test_canvas_contains_point) {

    Canvas canvas;
    Point p;
    
    canvas.origin.x = 100;
    canvas.origin.y = 200;
    
    canvas.size.x = 200;
    canvas.size.y = 100;
    
    p.x = 0;
    p.y = 0;
    
    fail_if(canvas_contains_point(&canvas, p), "should be false");
    
    p.x = 99;
    p.y = 199;
    
    fail_if(canvas_contains_point(&canvas, p), "should be false");
    
    p.y = 200;
    
    fail_if(canvas_contains_point(&canvas, p), "should be false");
    
    p.x = 100;
    p.y = 199;
    
    fail_if(canvas_contains_point(&canvas, p), "should be false");
    
    p.x = 300;
    p.y = 300;
    
    fail_if(canvas_contains_point(&canvas, p), "should be false");
    
    p.x = 299;
    
    fail_if(canvas_contains_point(&canvas, p), "should be false");
    
    p.x = 300;
    p.y = 299;
    
    fail_if(canvas_contains_point(&canvas, p), "should be false");
    
    p.x = 99;
    
    fail_if(canvas_contains_point(&canvas, p), "should be false");
    
    p.x = 100;
    p.y = 200;
    
    fail_unless(canvas_contains_point(&canvas, p), "should be true");
    
    p.x = 299;
    p.y = 299;
    
    fail_unless(canvas_contains_point(&canvas, p), "should be true");
    
    p.x = 100;
    
    fail_unless(canvas_contains_point(&canvas, p), "should be true");
    
    p.x = 250;
    p.y = 250;
    
    fail_unless(canvas_contains_point(&canvas, p), "should be true");
    
}
END_TEST

Suite* suite_canvas_contains_point(void) {

    Suite* s;
    TCase* tc_core;
    
    s = suite_create("suite_canvas_contains_point");
    
    /* Core test case */
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_canvas_contains_point);
    suite_add_tcase(s, tc_core);
    
    return s;
}

START_TEST(test_canvas_is_out_of_parent_bottom) {

    Canvas root;
    Canvas child;
    
    root.origin.x = 100;
    root.origin.y = 100;
    root.size.x = 100;
    root.size.y = 100;
    
    child.parent = &root;
    
    child.size.x = 10;
    child.size.y = 10;
    
    child.origin.y = 0;
    
    fail_if(canvas_is_out_of_parent_bottom(&child), "should be in");
    
    child.origin.y = 249204;
    
    fail_if(canvas_is_out_of_parent_bottom(&child), "should be in");
    
    child.origin.y = -1;
    
    fail_unless(canvas_is_out_of_parent_bottom(&child), "should not be in");
}
END_TEST

START_TEST(test_canvas_is_out_of_parent_top) {

    Canvas root;
    Canvas child;
    
    root.origin.x = 100;
    root.origin.y = 100;
    root.size.x = 100;
    root.size.y = 100;
    
    child.parent = &root;
    
    child.size.x = 10;
    child.size.y = 10;
    
    child.origin.y = 0;
    
    fail_if(canvas_is_out_of_parent_top(&child), "should be in");
    
    child.origin.y = -28490;
    
    fail_if(canvas_is_out_of_parent_top(&child), "should be in");
    
    child.origin.y = 90;
    
    fail_if(canvas_is_out_of_parent_top(&child), "should be in");
    
    child.origin.y = 91;
    
    fail_unless(canvas_is_out_of_parent_top(&child), "should not be in");
    
    child.origin.y = 928420;
    
    fail_unless(canvas_is_out_of_parent_top(&child), "should not be in");
}
END_TEST

START_TEST(test_canvas_is_out_of_parent_left) {

    Canvas root;
    Canvas child;
    
    root.origin.x = 100;
    root.origin.y = 100;
    root.size.x = 100;
    root.size.y = 100;
    
    child.parent = &root;
    
    child.size.x = 10;
    child.size.y = 10;
    
    child.origin.x = 0;
    
    fail_if(canvas_is_out_of_parent_left(&child), "should be in");
    
    child.origin.x = 249204;
    
    fail_if(canvas_is_out_of_parent_left(&child), "should be in");
    
    child.origin.x = -1;
    
    fail_unless(canvas_is_out_of_parent_left(&child), "should not be in");
}
END_TEST

START_TEST(test_canvas_is_out_of_parent_right) {

    Canvas root;
    Canvas child;
    
    root.origin.x = 100;
    root.origin.y = 100;
    root.size.x = 100;
    root.size.y = 100;
    
    child.parent = &root;
    
    child.size.x = 10;
    child.size.y = 10;
    
    child.origin.x = 0;
    
    fail_if(canvas_is_out_of_parent_right(&child), "should be in");
    
    child.origin.x = -28490;
    
    fail_if(canvas_is_out_of_parent_right(&child), "should be in");
    
    child.origin.x = 90;
    
    fail_if(canvas_is_out_of_parent_right(&child), "should be in");
    
    child.origin.x = 91;
    
    fail_unless(canvas_is_out_of_parent_right(&child), "should not be in");
    
    child.origin.x = 928420;
    
    fail_unless(canvas_is_out_of_parent_right(&child), "should not be in");
}
END_TEST

START_TEST(test_canvas_is_out_of_parent_x) {

    Canvas root;
    Canvas child;
    
    root.origin.x = 100;
    root.origin.y = 100;
    root.size.x = 100;
    root.size.y = 100;
    
    child.parent = &root;
    
    child.size.x = 10;
    child.size.y = 10;
    
    child.origin.x = 0;
    
    fail_if(canvas_is_out_of_parent_x(&child), "should be in");
    
    child.origin.x = -28490;
    
    fail_unless(canvas_is_out_of_parent_x(&child), "should not be in");
    
    child.origin.x = 90;
    
    fail_if(canvas_is_out_of_parent_x(&child), "should be in");
    
    child.origin.x = 91;
    
    fail_unless(canvas_is_out_of_parent_x(&child), "should not be in");
    
    child.origin.x = 928420;
    
    fail_unless(canvas_is_out_of_parent_x(&child), "should not be in");
}
END_TEST

START_TEST(test_canvas_is_out_of_parent_y) {

    Canvas root;
    Canvas child;
    
    root.origin.x = 100;
    root.origin.y = 100;
    root.size.x = 100;
    root.size.y = 100;
    
    child.parent = &root;
    
    child.size.x = 10;
    child.size.y = 10;
    
    child.origin.y = 0;
    
    fail_if(canvas_is_out_of_parent_y(&child), "should be in");
    
    child.origin.y = -28490;
    
    fail_unless(canvas_is_out_of_parent_y(&child), "should not be in");
    
    child.origin.y = 90;
    
    fail_if(canvas_is_out_of_parent_y(&child), "should be in");
    
    child.origin.y = 91;
    
    fail_unless(canvas_is_out_of_parent_y(&child), "should not be in");
    
    child.origin.y = 928420;
    
    fail_unless(canvas_is_out_of_parent_y(&child), "should not be in");
}
END_TEST

Suite* suite_canvas_is_out_of_parent(void) {

    Suite* s;
    TCase* tc_core;
    
    s = suite_create("suite_canvas_is_out_of_parent");
    
    /* Core test case */
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_canvas_is_out_of_parent_bottom);
    tcase_add_test(tc_core, test_canvas_is_out_of_parent_top);
    tcase_add_test(tc_core, test_canvas_is_out_of_parent_left);
    tcase_add_test(tc_core, test_canvas_is_out_of_parent_right);
    tcase_add_test(tc_core, test_canvas_is_out_of_parent_x);
    tcase_add_test(tc_core, test_canvas_is_out_of_parent_y);
    
    suite_add_tcase(s, tc_core);
    
    return s;
}

START_TEST(test_canvas_will_be_out_of_parent_bottom) {

    Canvas root;
    Canvas child;
    Point move;
    
    root.origin.x = 100;
    root.origin.y = 100;
    root.size.x = 100;
    root.size.y = 100;
    
    child.parent = &root;
    
    child.size.x = 10;
    child.size.y = 10;
    
    child.origin.y = 0;
    
    move.y = 0;
    
    fail_if(canvas_will_be_out_of_parent_bottom(&child, &move), "should be in");
    
    move.y = 249204;
    
    fail_if(canvas_will_be_out_of_parent_bottom(&child, &move), "should be in");
    
    move.y = -1;
    
    fail_unless(canvas_will_be_out_of_parent_bottom(&child, &move), "should not be in");
}
END_TEST

START_TEST(test_canvas_will_be_out_of_parent_top) {

    Canvas root;
    Canvas child;
    
    Point move;
    
    root.origin.x = 100;
    root.origin.y = 100;
    
    root.size.x = 100;
    root.size.y = 100;
    
    child.parent = &root;
    
    child.size.x = 10;
    child.size.y = 10;
    
    child.origin.y = 0;
    
    move.y = 0;
    
    fail_if(canvas_will_be_out_of_parent_top(&child, &move), "should be in");
    
    move.y = -28490;
    
    fail_if(canvas_will_be_out_of_parent_top(&child, &move), "should be in");
    
    move.y = 90;
    
    fail_if(canvas_will_be_out_of_parent_top(&child, &move), "should be in");
    
    move.y = 91;
    
    fail_unless(canvas_will_be_out_of_parent_top(&child, &move), "should not be in");
    
    move.y = 928420;
    
    fail_unless(canvas_will_be_out_of_parent_top(&child, &move), "should not be in");
}
END_TEST

START_TEST(test_canvas_will_be_out_of_parent_left) {

    Canvas root;
    Canvas child;
    Point move;
    
    root.origin.x = 100;
    root.origin.y = 100;
    root.size.x = 100;
    root.size.y = 100;
    
    child.parent = &root;
    
    child.size.x = 10;
    child.size.y = 10;
    
    child.origin.x = 0;
    
    move.x = 0;
    
    fail_if(canvas_will_be_out_of_parent_left(&child, &move), "should be in");
    
    move.x = 249204;
    
    fail_if(canvas_will_be_out_of_parent_left(&child, &move), "should be in");
    
    move.x = -1;
    
    fail_unless(canvas_will_be_out_of_parent_left(&child, &move), "should not be in");
}
END_TEST

START_TEST(test_canvas_will_be_out_of_parent_right) {

    Canvas root;
    Canvas child;
    Point move;
    
    root.origin.x = 100;
    root.origin.y = 100;
    root.size.x = 100;
    root.size.y = 100;
    
    child.parent = &root;
    
    child.size.x = 10;
    child.size.y = 10;
    
    child.origin.x = 0;
    move.x = 0;
    
    fail_if(canvas_will_be_out_of_parent_right(&child, &move), "should be in");
    
    move.x = -28490;
    
    fail_if(canvas_will_be_out_of_parent_right(&child, &move), "should be in");
    
    move.x = 90;
    
    fail_if(canvas_will_be_out_of_parent_right(&child, &move), "should be in");
    
    move.x = 91;
    
    fail_unless(canvas_will_be_out_of_parent_right(&child, &move), "should not be in");
    
    move.x = 928420;
    
    fail_unless(canvas_will_be_out_of_parent_right(&child, &move), "should not be in");
}
END_TEST

START_TEST(test_canvas_will_be_out_of_parent_x) {

    Canvas root;
    Canvas child;
    Point move;
    
    root.origin.x = 100;
    root.origin.y = 100;
    root.size.x = 100;
    root.size.y = 100;
    
    child.parent = &root;
    
    child.size.x = 10;
    child.size.y = 10;
    
    child.origin.x = 0;
    move.x = 0;
    
    fail_if(canvas_will_be_out_of_parent_x(&child, &move), "should be in");
    
    move.x = -28490;
    
    fail_unless(canvas_will_be_out_of_parent_x(&child, &move), "should not be in");
    
    move.x = 90;
    
    fail_if(canvas_will_be_out_of_parent_x(&child, &move), "should be in");
    
    move.x = 91;
    
    fail_unless(canvas_will_be_out_of_parent_x(&child, &move), "should not be in");
    
    move.x = 928420;
    
    fail_unless(canvas_will_be_out_of_parent_x(&child, &move), "should not be in");
}
END_TEST

START_TEST(test_canvas_will_be_out_of_parent_y) {

    Canvas root;
    Canvas child;
    Point move;
    
    root.origin.x = 100;
    root.origin.y = 100;
    root.size.x = 100;
    root.size.y = 100;
    
    child.parent = &root;
    
    child.size.x = 10;
    child.size.y = 10;
    
    child.origin.y = 0;
    move.y = 0;
    
    fail_if(canvas_will_be_out_of_parent_y(&child, &move), "should be in");
    
    move.y = -28490;
    
    fail_unless(canvas_will_be_out_of_parent_y(&child, &move), "should not be in");
    
    move.y = 90;
    
    fail_if(canvas_will_be_out_of_parent_y(&child, &move), "should be in");
    
    move.y = 91;
    
    fail_unless(canvas_will_be_out_of_parent_y(&child, &move), "should not be in");
    
    move.y = 928420;
    
    fail_unless(canvas_will_be_out_of_parent_y(&child, &move), "should not be in");
}
END_TEST

Suite* suite_canvas_will_be_out_of_parent(void) {

    Suite* s;
    TCase* tc_core;
    
    s = suite_create("suite_canvas_will_be_out_of_parent");
    
    /* Core test case */
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_canvas_will_be_out_of_parent_bottom);
    tcase_add_test(tc_core, test_canvas_will_be_out_of_parent_top);
    tcase_add_test(tc_core, test_canvas_will_be_out_of_parent_left);
    tcase_add_test(tc_core, test_canvas_will_be_out_of_parent_right);
    tcase_add_test(tc_core, test_canvas_will_be_out_of_parent_x);
    tcase_add_test(tc_core, test_canvas_will_be_out_of_parent_y);
    
    suite_add_tcase(s, tc_core);
    
    return s;
}

Suite* suite_canvas_get_corner(void) {

    Suite* s;
    TCase* tc_core;
    
    s = suite_create("suite_canvas_get_corner");
    
    /* Core test case */
    tc_core = tcase_create("Core");
    
    /*
    tcase_add_test(tc_core, test_canvas_get_bottom_left_corner);
    tcase_add_test(tc_core, test_canvas_get_bottom_right_corner);
    tcase_add_test(tc_core, test_canvas_get_top_left_corner);
    tcase_add_test(tc_core, test_canvas_get_top_right_corner);
    */
    
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
    
    s = suite_canvas_contains_point();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    
    s = suite_canvas_is_out_of_parent();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    
    s = suite_canvas_will_be_out_of_parent();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    
    s = suite_canvas_get_corner();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
