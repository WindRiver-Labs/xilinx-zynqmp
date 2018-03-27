#@TYPE: Machine inc.
#@NAME: zynqmp layer

DEFAULTTUNE = "aarch64"
require conf/machine/include/arm/arch-armv8.inc

MACHINE_FEATURES += "ext3 pci usbgadget usbhost vfat"

KERNEL_IMAGETYPE = "Image"
KERNEL_DEVICETREE_xilinx-zynqmp = "xilinx/zynqmp-zcu102-rev1.0.dtb"

SERIAL_CONSOLE = "115200 ttyPS0"

IMAGE_FSTYPES += "tar.bz2"

# multilib support
MULTILIBS ?= "multilib:lib32"
DEFAULTTUNE_virtclass-multilib-lib32 ?= "armv7athf-neon"

COMPATIBLE_HOST_pn-netmap_xilinx-zynqmp = "null"
