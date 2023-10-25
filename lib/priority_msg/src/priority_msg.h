#pragma once
#include <device.h>



void send_hiprio_message(const struct device *dev, uint32_t id, uint32_t delay);
void send_loprio_message(const struct device *dev, uint32_t id, uint32_t delay);