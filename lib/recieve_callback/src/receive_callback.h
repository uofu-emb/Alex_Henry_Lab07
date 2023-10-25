#pragma once
#include <can/can_loopback.h>
#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

#define LED0_NODE DT_ALIAS(led0)

#if DT_NODE_HAS_STATUS(LED0_NODE, okay)
#define LED0	DT_GPIO_LABEL(LED0_NODE, gpios)
#define PIN0	DT_GPIO_PIN(LED0_NODE, gpios)
#define FLAGS0	DT_GPIO_FLAGS(LED0_NODE, gpios)
#else
#error "Unsupported board: led0 devicetree alias is not defined"
#define LED0	""
#define PIN0	0
#define FLAGS0	0
#endif

void led_setup();

void rx_callback(struct zcan_frame *frame, void *arg);