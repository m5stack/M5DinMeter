/**
 * @file wakeup.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5DinMeter Timer Wakeup Test
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

#include <M5DinMeter.h>

void setup(void) {
    auto cfg = M5.config();
    DinMeter.begin(cfg, false);
    DinMeter.Display.setRotation(1);
    DinMeter.Display.setTextColor(GREEN);
    DinMeter.Display.setTextDatum(middle_center);
    DinMeter.Display.setTextFont(&fonts::FreeSerifItalic9pt7b);
    DinMeter.Display.setTextSize(1);

    DinMeter.Display.drawString("Press Btn", DinMeter.Display.width() / 2,
                                DinMeter.Display.height() / 2 - 45);
    DinMeter.Display.drawString("to sleep", DinMeter.Display.width() / 2,
                                DinMeter.Display.height() / 2 - 15);
    DinMeter.Display.drawString("After 5s", DinMeter.Display.width() / 2,
                                DinMeter.Display.height() / 2 + 15);
    DinMeter.Display.drawString("Wakeup", DinMeter.Display.width() / 2,
                                DinMeter.Display.height() / 2 + 45);
}

void loop(void) {
    DinMeter.update();

    if (DinMeter.BtnA.wasPressed()) {
        DinMeter.Power.timerSleep(5);
        // DinMeter.Power.timerSleep(const rtc_time_t& time);
        // DinMeter.Power.timerSleep(const rtc_date_t& date, const rtc_time_t&
        // time);
        // DinMeter.Power.powerOff(); shutdown
    }
}
