/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/sys/printk.h>

const struct device *i2c = DEVICE_DT_GET(DT_NODELABEL(i2c0));

void probe_i2c(void) {
    for (uint8_t addr = 0x03; addr <= 0x77; addr++) {
        int ret = i2c_write(i2c, NULL, 0, addr); /* zero-length write to probe */
        if (ret == 0) {
            printk("I2C device at 0x%02x\n", addr);
        }
    }
}

int main(void)
{
	printf("Hello World! %s\n", CONFIG_BOARD_TARGET);

	probe_i2c();

	return 0;
}
