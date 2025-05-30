# Copyright (c) 2023 Enphase Energy
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)
zephyr_sources(common/ctrl_partitions.c)

if( CONFIG_SOC_SERIES_AM261X_R5 )
  zephyr_sources(r5/soc.c)
  #zephyr_sources_ifdef(CONFIG_ARM_MPU r5/arm_mpu_regions.c)

  zephyr_include_directories(r5)

  set(SOC_LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/r5/linker.ld CACHE INTERNAL "")

endif()
