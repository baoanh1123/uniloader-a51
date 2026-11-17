// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2026, Antigravity
 */
#include <board.h>
#include <util.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>
#include <soc/exynos9610.h>

int a51_init(void)
{
	/* Allow framebuffer to be written to */
	*(volatile int *) (DECON_F_BASE + HW_SW_TRIG_CONTROL) = 0x1281;
	return 0;
}

static struct video_info a51_fb = {
	.format = FB_FORMAT_ARGB8888,
	.width = 1080,
	.height = 2400,
	.stride = 4,
	.scale = 2,
	.address = (void *)0xca000000
};

static const struct device a51_devices[] = {
	{ "simplefb", &a51_fb, "fb" },
};

struct board_data board_ops = {
	.name = "samsung-a51",
	.ops = {
		.early_init = a51_init,
	},
	.devices = a51_devices,
	.num_devices = ARRAY_SIZE(a51_devices),
	.quirks = 0
};
