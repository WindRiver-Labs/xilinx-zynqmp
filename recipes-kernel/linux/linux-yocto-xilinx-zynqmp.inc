#
# Copyright (C) 2019 Wind River Systems, Inc.
#


COMPATIBLE_MACHINE_xilinx-zynqmp = "xilinx-zynqmp"

TARGET_SUPPORTED_KTYPES_xilinx-zynqmp = "standard"

KERNEL_VERSION_SANITY_SKIP = "1"
SRCREV_machine_xilinx-zynqmp ?= "${AUTOREV}"
SRCREV_meta_xilinx-zynqmp ?= "${AUTOREV}"
