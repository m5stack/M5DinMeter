/**
 * @file buzzer.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5DinMeter Buzzer Test
 * @version 0.1
 * @date 2024-03-07
 *
 *
 * @Hardwares: M5DinMeter
 * @Platform Version: Arduino M5Stack Board Manager v2.1.1
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 */
#include "M5DinMeter.h"

void setup() {
    auto cfg = M5.config();
    DinMeter.begin(cfg, true);
    DinMeter.Display.setRotation(1);
    DinMeter.Display.setTextColor(GREEN);
    DinMeter.Display.setTextDatum(middle_center);
    DinMeter.Display.setTextFont(&fonts::Orbitron_Light_32);
    DinMeter.Display.setTextSize(1);
    DinMeter.Display.drawString("Buzzer Test", DinMeter.Display.width() / 2,
                                DinMeter.Display.height() / 2);
}

void loop() {
    DinMeter.Speaker.tone(10000, 100);
    delay(1000);
    DinMeter.Speaker.tone(4000, 20);
    delay(1000);
}