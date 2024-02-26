/**
 * @file display.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5DinMeter Display Test
 * @version 0.1
 * @date 2023-09-26
 *
 *
 * @Hardwares: M5DinMeter
 * @Platform Version: Arduino M5Stack Board Manager v2.1.1
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 */
#include "M5DinMeter.h"

void draw_function(LovyanGFX* gfx) {
    int x      = rand() % gfx->width();
    int y      = rand() % gfx->height();
    int r      = (gfx->width() >> 4) + 2;
    uint16_t c = rand();
    gfx->fillRect(x - r, y - r, r * 2, r * 2, c);
}

void setup() {
    auto cfg = M5.config();
    DinMeter.begin(cfg, false);

    int textsize = DinMeter.Display.height() / 60;
    if (textsize == 0) {
        textsize = 1;
    }
    DinMeter.Display.setTextSize(textsize);
}

void loop() {
    int x      = rand() % DinMeter.Display.width();
    int y      = rand() % DinMeter.Display.height();
    int r      = (DinMeter.Display.width() >> 4) + 2;
    uint16_t c = rand();
    DinMeter.Display.fillCircle(x, y, r, c);
    draw_function(&DinMeter.Display);
}