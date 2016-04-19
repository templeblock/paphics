#include "quadrilateral.h"

/*void quadrilateral_draw_old(Canvas canvas, Point p1, Point p2, Point p3, Point p4, Uint32 color) {

    Point max_left;
    Point max_right;
    Point other1;
    Point other2;

    if (p1.x <= p2.x && p1.x <= p2.x && p1.x <= p3.x && p1.x <= p4.x) {
        max_left = p1;
    } else if (p2.x <= p3.x && p2.x <= p4.x) {
        max_left = p2;
    } else if (p3.x <= p4.x) {
        max_left = p3;
    } else {
        max_left = p4;
    }

    if (p1.x >= p2.x && p1.x >= p2.x && p1.x >= p3.x && p1.x >= p4.x) {
        max_right = p1;
    } else if (p2.x >= p3.x && p2.x >= p4.x) {
        max_right = p2;
    } else if (p3.x >= p4.x) {
        max_right = p3;
    } else {
        max_right = p4;
    }

    if (!(equals(p1, max_left)) && !(equals(p1, max_right))) {
        other1 = p1;
    } else if (!(equals(p2, max_left)) && !(equals(p2, max_right))) {
        other1 = p2;
    } else if (!(equals(p3, max_left)) && !(equals(p3, max_right))) {
        other1 = p3;
    } else {
        other1 = p4;
    }

    if (!(equals(p1, max_left)) && !(equals(p1, max_right)) && !(equals(p1, other1))) {
        other2 = p1;
    } else if (!(equals(p2, max_left)) && !(equals(p2, max_right)) && !(equals(p2, other1))) {
        other2 = p2;
    } else if (!(equals(p4, max_left)) && !(equals(p4, max_right)) && !(equals(p4, other1))) {
        other2 = p4;
    } else {
        other2 = p3;
    }

    Line line1;
    Line line2;
    Line line3;
    Line line4;

    line1.a = max_left;
    line1.b = other1;

    line2.a = other1;
    line2.b = max_right;

    line3.a = max_right;
    line3.b = other2;

    line4.a = other2;
    line4.b = max_left;

    line1.color = color;
    line2.color = color;
    line3.color = color;
    line4.color = color;

    line_draw(canvas, &line1);
    line_draw(canvas, &line2);
    line_draw(canvas, &line3);
    line_draw(canvas, &line4);

}*/

void quadrilateral_draw(Canvas canvas, Point p1, Point p2, Point p3, Point p4, Uint32 color) {

    Point leftToRight[4];
    Point topToBottom[4];
    Point tmp;
    Line line1;
    Line line2;
    Line line3;
    Line line4;

    point_sort_leftToRight(4, leftToRight, p1, p2, p3, p4);
    point_sort_topToBottom(4, topToBottom, p1, p2, p3, p4);

    printf("\nGauche[0]: (%d, %d)", leftToRight[0].x, leftToRight[0].y);
    printf("\nGauche[1]: (%d, %d)", leftToRight[1].x, leftToRight[1].y);
    printf("\nGauche[2]: (%d, %d)", leftToRight[2].x, leftToRight[2].y);
    printf("\nGauche[3]: (%d, %d)\n", leftToRight[3].x, leftToRight[3].y);

    printf("\nHaut[0]: (%d, %d)", topToBottom[0].x, topToBottom[0].y);
    printf("\nHaut[1]: (%d, %d)", topToBottom[1].x, topToBottom[1].y);
    printf("\nHaut[2]: (%d, %d)", topToBottom[2].x, topToBottom[2].y);
    printf("\nHaut[3]: (%d, %d)\n", topToBottom[3].x, topToBottom[3].y);

    if (equals(leftToRight[0], topToBottom[3])) {

        line1.a = leftToRight[0];
        line1.b = leftToRight[1];

        line2.a = leftToRight[0];
        line2.b = topToBottom[2];

        if (equals(line1.a, leftToRight[2]) || equals(line1.b, leftToRight[2]) || equals(line2.b, leftToRight[2])) {
            tmp = leftToRight[3];
        } else {
            tmp = leftToRight[4];
        }

        line3.a = topToBottom[2];
        line3.b = tmp;

        line4.a = leftToRight[1];
        line4.b = tmp;

    } else if (equals(leftToRight[0], topToBottom[0])) {

        line1.a = leftToRight[0];
        line1.b = leftToRight[1];

        line2.a = leftToRight[0];
        line2.b = topToBottom[1];

        if (equals(line1.a, leftToRight[2]) || equals(line1.b, leftToRight[2]) || equals(line2.b, leftToRight[2])) {
            tmp = leftToRight[3];
        } else {
            tmp = leftToRight[4];
        }

        line3.a = topToBottom[1];
        line3.b = tmp;

        line4.a = leftToRight[1];
        line4.b = tmp;

    } else {

        line1.a = leftToRight[0];
        line1.b = topToBottom[0];

        line2.a = leftToRight[0];
        line2.b = topToBottom[3];

        if (equals(line1.a, topToBottom[1])) {
            tmp = topToBottom[2];
        } else {
            tmp = topToBottom[1];
        }

        line3.a = tmp;
        line3.b = topToBottom[0];

        line4.a = tmp;
        line4.b = topToBottom[3];
    }

    line1.color = color;
    line2.color = color;
    line3.color = color;
    line4.color = color;

    line_draw(&canvas, &line1);
    line_draw(&canvas, &line2);
    line_draw(&canvas, &line3);
    line_draw(&canvas, &line4);

}
