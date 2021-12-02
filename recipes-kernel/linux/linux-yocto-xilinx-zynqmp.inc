#
# Copyright (C) 2019 Wind River Systems, Inc.
#


COMPATIBLE_MACHINE_xilinx-zynqmp = "xilinx-zynqmp"

TARGET_SUPPORTED_KTYPES_xilinx-zynqmp = "standard preempt-rt"

FILESEXTRAPATHS_prepend_xilinx-zynqmp := "${THISDIR}/files:"

SRC_URI_append_xilinx-zynqmp = " \
    file://0001-arch-arm64-dts-add-dts-file-for-CANFD-feature-on-xil.patch \
"

KERNEL_VERSION_SANITY_SKIP = "1"
SRCREV_machine_xilinx-zynqmp ?= "${AUTOREV}"
SRCREV_meta_xilinx-zynqmp ?= "${AUTOREV}"
