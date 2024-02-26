#include "M5DinMeter.h"

using namespace m5;

M5DinMeter DinMeter;

void M5DinMeter::begin(bool enableEncoder) {
    M5.begin();
    if (enableEncoder) {
        Encoder.begin();
    }
}

void M5DinMeter::begin(m5::M5Unified::config_t cfg, bool enableEncoder) {
    M5.begin(cfg);
    if (enableEncoder) {
        Encoder.begin();
    }
}

void M5DinMeter::update(void) {
    M5.update();
}
