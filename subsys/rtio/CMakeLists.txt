# Copyright (c) 2022 Intel Corporation
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_RTIO)
	zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/rtio/rtio.h)

	zephyr_library()

	zephyr_include_directories(${ZEPHYR_BASE}/subsys/rtio)

	zephyr_library_sources(rtio_executor.c)
	zephyr_library_sources(rtio_init.c)
	zephyr_library_sources(rtio_sched.c)
	zephyr_library_sources_ifdef(CONFIG_USERSPACE rtio_handlers.c)
endif()

zephyr_library_sources_ifdef(CONFIG_RTIO_WORKQ rtio_workq.c)
