#
# Copyright (C) 2016 Wind River Systems, Inc.
#

TARGET_SUPPORTED_KTYPES_xilinx-zynqmp = "standard preempt-rt"

KBRANCH_DEFAULT_standard_xilinx-zynqmp = "standard/${KMACHINE}"
KBRANCH_DEFAULT_preempt-rt_xilinx-zynqmp = "standard/preempt-rt/${KMACHINE}"

KERNEL_DEVICETREE_xilinx-zynqmp = "xilinx/zynqmp-zcu102.dtb"
