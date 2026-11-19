/**
 * Convert joystick directions to numpad notation
 * Elizabeth Posusta - Nov 2026
 */
#include <string.h>
#include <math.h>
#include <LiquidCrystal.h>

#define RS 3
#define EN 5
#define D4 8
#define D5 9
#define D6 10
#define D7 11
#define JOYSTICK_MAX 1023

typedef struct {
    int x;
    int y;
} Pos;

Pos stickpos = Pos {.x = 0.0, .y = 0.0};

char* direction = "Neutral";
char* notation = "5";

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    lcd.begin(2, 16);
    stickpos = Pos {.x = analogRead(A0), .y = analogRead(A1)};
}

bool in_deadzone(int x, int y) {
    int origin = JOYSTICK_MAX / 2;
    int radius = 50;

    if(x < origin + 50 && x > origin - 50 && y < origin + 50 && y > origin - 50){
        return true;
    }
    return false;
}

double get_theta(int _x, int _y) {
    double origin = (double)JOYSTICK_MAX / (double)2;
    double x = (double)_x - origin;
    double y = (double)_y - origin;
    return atan2(y, x);
}

int get_octant(int x, int y) {
    double theta = get_theta(x, y);
    return (int)(theta / (PI / 4.0f));
}

void loop() {
    lcd.print(get_octant(stickpos.x, stickpos.y));
    if(analogRead(A0) != stickpos.x || analogRead(A1) != stickpos.y) {
        stickpos.x = analogRead(A0);
        stickpos.y = analogRead(A1);
    }
    delay(50);
    lcd.home();
    lcd.clear();
}
