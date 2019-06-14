#@TYPE: Machine inc.
#@NAME: zynqmp layer

DEFAULTTUNE = "cortexa53"
require conf/machine/include/tune-cortexa53.inc

MACHINE_FEATURES += "ext3 pci usbgadget usbhost vfat keyboard network"

KERNEL_IMAGETYPE = "Image"
KERNEL_DEVICETREE_xilinx-zynqmp = "xilinx/zynqmp-zcu102-rev1.0.dtb"

SERIAL_CONSOLE = "115200 ttyPS0"

PREFERRED_PROVIDER_virtual/kernel ??= "linux-yocto"
PREFERRED_VERSION_linux-yocto ?= "5.0%"

# multilib support
MULTILIBS ?= "multilib:lib32"
DEFAULTTUNE_virtclass-multilib-lib32 ?= "armv7athf-neon"
