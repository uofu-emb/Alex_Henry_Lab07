#pragma once
#include <device.h>



void send_hiprio_message_cont(const struct device *dev);
void send_loprio_message_periodic(const struct device *dev, uint32_t delay);