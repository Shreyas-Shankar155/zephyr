/*
 * Copyright (c) 2025 Texas Instruments Incorporated
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/sys/util.h>
#include <zephyr/sys/device_mmio.h>
#include <zephyr/arch/common/sys_io.h>

#if defined CONFIG_SOC_AM261X_R5F0_0
#define KICK0_OFFSET     (0x02A4)
#define KICK1_OFFSET     (0x02A8)
#define KICK0_UNLOCK_VAL (0x83E70B13)
#define KICK1_UNLOCK_VAL (0x95A4F1E0)
#define KICK_LOCK_VAL    (0x0U)
#endif

#define CTRL_PARTITION_SIZE        (0x4000)
#define CTRL_PARTITION(base, part) ((base) + (part) * CTRL_PARTITION_SIZE)

#if defined CONFIG_SOC_AM261X_R5F0_0
#define MAIN_PADCFG_BASE (0x53100000)
#endif

static const uintptr_t ctrl_partitions[] = {
#if defined CONFIG_SOC_AM261X_R5F0_0
	CTRL_PARTITION(MAIN_PADCFG_BASE, 0),
#endif
};

void k3_unlock_all_ctrl_partitions(void)
{
	ARRAY_FOR_EACH(ctrl_partitions, i) {
		mm_reg_t base_addr = ctrl_partitions[i];

#ifdef DEVICE_MMIO_IS_IN_RAM
		device_map(&base_addr, base_addr, sizeof(base_addr), K_MEM_CACHE_NONE);
#endif

		sys_write32(KICK0_UNLOCK_VAL, base_addr + KICK0_OFFSET);
		sys_write32(KICK1_UNLOCK_VAL, base_addr + KICK1_OFFSET);
	}
}