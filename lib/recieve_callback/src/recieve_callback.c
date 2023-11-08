#include "receive_callback.h"

const struct device *led_dev;
bool led_is_off;

void led_setup()
{
    led_dev = device_get_binding(LED0);
    led_is_off = true;
    gpio_pin_configure(led_dev, PIN0, GPIO_OUTPUT_ACTIVE | FLAGS0);
    gpio_pin_set(led_dev, PIN0, (int)led_is_off);
    led_is_off = !led_is_off;
}

void rx_callback(struct zcan_frame *frame, void *arg)
{
    printk("Data value 1 = %d", frame->data[0]);
    gpio_pin_set(led_dev, PIN0, (int)led_is_off);
    led_is_off = !led_is_off;
}