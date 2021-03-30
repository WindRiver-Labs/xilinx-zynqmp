#@TYPE: Machine inc.
#@NAME: zynqmp layer

DEFAULTTUNE = "cortexa53"
require conf/machine/include/tune-cortexa53.inc

MACHINE_FEATURES += "ext3 pci usbgadget usbhost vfat keyboard network"

KERNEL_IMAGETYPE = "Image"
KERNEL_DEVICETREE_xilinx-zynqmp = "xilinx/zynqmp-zcu102-rev1.0.dtb xilinx/zynqmp-zcu102-rev1.0-canfd.dtb"

SERIAL_CONSOLE = "115200 ttyPS0"

PREFERRED_PROVIDER_virtual/kernel ??= "linux-yocto"
PREFERRED_VERSION_linux-yocto ?= "5.10%"

MACHINE_EXTRA_RRECOMMENDS = " kernel-modules kernel-devicetree"
IMAGE_FSTYPES += "tar.bz2 wic wic.bmap"

# wic support
WKS_FILE ?= "zynqmp-sdimage.wks"
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot"
IMAGE_BOOT_FILES ?= " Image zynqmp-zcu102-rev1.0.dtb "

# multilib support
MULTILIBS ?= "multilib:lib32"
DEFAULTTUNE_virtclass-multilib-lib32 ?= "armv7athf-neon"

XSERVER_append += "xf86-video-armsoc"
OSTREE_BOOTLOADER_INCLUDE ?= ""
OSTREE_SD_UBOOT_WIC1 ?= ""
OSTREE_SD_BOOT_ALIGN ?= "4096"
OSTREE_FDISK_BLM ?= "8192"
OSTREE_FDISK_FSZ ?= "132"
OSTREE_KERNEL ?= "Image"
OSTREE_UBOOT_CMD ?= "booti"
OSTREE_WKS_EFI_SIZE ?= "--size=64M"
INSTAB ?= "1"

MACHINEOVERRIDES_prepend_xilinx-zynqmp = "mali400:zynqmp:zynqmpeg:"
