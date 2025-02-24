/*
 * Copyright (c) 2016 Park Bumgyu, Samsung Electronics Co., Ltd <bumgyu.park@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Exynos ACME(A Cpufreq that Meets Every chipset) driver implementation
 */

#include <linux/cpufreq.h>

#define EXYNOS_UFC_TYPE_NAME_LEN	16

enum exynos_ufc_ctrl_type {
	PM_QOS_MIN_LIMIT = 0,
	PM_QOS_MIN_WO_BOOST_LIMIT,
	PM_QOS_MAX_LIMIT,
	TYPE_END
};

struct exynos_ufc_freq {
	u32			master_freq;
	u32			limit_freq;
};

struct exynos_ufc_info {
	struct list_head	node;
	int			ctrl_type;

	struct exynos_ufc_freq *freq_table;
};

#ifdef CONFIG_ACPM_DVFS
extern void __iomem *map_base;
extern void __iomem *sram_base;

extern int fvmap_change_voltage(unsigned int dvfs_id,
				unsigned int freq, unsigned int voltage);
extern void fvmap_copy_from_sram(void __iomem *map_base,
				 void __iomem *sram_base,
				 unsigned int requested_voltage_change[3]);
#endif
