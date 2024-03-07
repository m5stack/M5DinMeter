/**
 * @file encoder.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5DinMeter Encoder Test
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
    DinMeter.Display.setTextSize(2);
}

long oldPosition = -999;

void loop() {
    DinMeter.update();
    long newPosition = DinMeter.Encoder.read();
    if (newPosition != oldPosition) {
        DinMeter.Speaker.tone(8000, 20);
        DinMeter.Display.clear();
        oldPosition = newPosition;
        Serial.println(newPosition);
        DinMeter.Display.drawString(String(newPosition),
                                    DinMeter.Display.width() / 2,
                                    DinMeter.Display.height() / 2);
    }
    if (DinMeter.BtnA.wasPressed()) {
        DinMeter.Encoder.readAndReset();
    }
    if (DinMeter.BtnA.pressedFor(5000)) {
        DinMeter.Encoder.write(100);
    }
}