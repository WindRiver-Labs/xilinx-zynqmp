#@TYPE: Machine inc.
#@NAME: zynqmp layer

DEFAULTTUNE = "aarch64"
require conf/machine/include/arm/arch-armv8.inc

MACHINE_FEATURES += "usbhost ext3 vfat pci"

KERNEL_IMAGETYPE = "Image"

SERIAL_CONSOLES ?= "115200;ttyPS0 115200"
SERIAL_CONSOLES_CHECK ?= "${SERIAL_CONSOLES}"

IMAGE_FSTYPES ?= "tar.bz2"

CRIU_BUILD_ARCH = "armv8"

# multilib support
MULTILIBS ?= "multilib:lib32"
DEFAULTTUNE_virtclass-multilib-lib32 ?= "armv7athf-neon"
