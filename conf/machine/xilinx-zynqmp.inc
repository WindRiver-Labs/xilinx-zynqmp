#@TYPE: Machine inc.
#@NAME: zynqmp layer

DEFAULTTUNE = "aarch64"
require conf/machine/include/arm/arch-armv8.inc

MACHINE_FEATURES += "usbhost ext3 vfat pci"

KERNEL_IMAGETYPE = "Image"

SERIAL_CONSOLE = "115200 ttyPS0"

IMAGE_FSTYPES += "tar.bz2 wic wic.bmap"
WKS_FILE = "sdimage.wks"
do_image_wic[depends] += "mtools-native:do_populate_sysroot"

# multilib support
MULTILIBS ?= "multilib:lib32"
DEFAULTTUNE_virtclass-multilib-lib32 ?= "armv7athf-neon"

COMPATIBLE_HOST_pn-netmap_xilinx-zynqmp = "null"
