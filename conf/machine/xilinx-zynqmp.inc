#@TYPE: Machine inc.
#@NAME: zynqmp layer

DEFAULTTUNE = "cortexa53"
require conf/machine/include/tune-cortexa53.inc

MACHINE_FEATURES += "ext3 pci usbgadget usbhost vfat keyboard network"

KERNEL_IMAGETYPE = ""
KERNEL_IMAGETYPES = " ${@bb.utils.contains('UBOOT_SIGN_ENABLE', '1', 'fitImage', 'Image.gz Image', d)}"
KERNEL_DEVICETREE_xilinx-zynqmp = "xilinx/zynqmp-zcu102-rev1.0.dtb xilinx/zynqmp-zcu102-rev1.0-canfd.dtb"

SERIAL_CONSOLE = "115200 ttyPS0"

PREFERRED_PROVIDER_virtual/kernel ??= "linux-yocto"

MACHINE_EXTRA_RRECOMMENDS = " kernel-modules kernel-devicetree"
IMAGE_FSTYPES += "tar.bz2 wic wic.bmap"

# wic support
WKS_FILE ?= "zynqmp-sdimage.wks"
IMAGE_INSTALL_append = " ${@bb.utils.contains('UBOOT_SIGN_ENABLE', '1', 'kernel-devicetree kernel-image-fitimage', 'kernel-devicetree kernel-image-image', d)}"
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot"
IMAGE_BOOT_FILES ?= " ${@bb.utils.contains('UBOOT_SIGN_ENABLE', '1', 'fitImage', 'Image zynqmp-zcu102-rev1.0.dtb', d)}"

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
