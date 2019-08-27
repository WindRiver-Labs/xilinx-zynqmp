#@TYPE: Machine inc.
#@NAME: zynqmp layer

DEFAULTTUNE = "aarch64"
require conf/machine/include/arm/arch-armv8.inc

MACHINE_FEATURES += "ext3 pci usbgadget usbhost vfat keyboard screen network"
DISTRO_FEATURES_remove = " wayland"

KERNEL_IMAGETYPE = ""
KERNEL_IMAGETYPES = " ${@bb.utils.contains('UBOOT_SIGN_ENABLE', '1', 'fitImage', 'Image.gz Image', d)}"
KERNEL_DEVICETREE = "xilinx/zynqmp-zcu102-rev1.0.dtb xilinx/zynqmp-zcu102-fpga-update.dtb"

SERIAL_CONSOLE = "115200 ttyPS0"

MACHINE_EXTRA_RRECOMMENDS = " kernel-modules kernel-devicetree"
IMAGE_FSTYPES += "tar.bz2 wic wic.bmap"
WKS_FILE ?= "zynqmp-sdimage.wks"
IMAGE_INSTALL_append = " ${@bb.utils.contains('UBOOT_SIGN_ENABLE', '1', 'kernel-devicetree kernel-image-fitimage', 'kernel-devicetree kernel-image-image', d)}"
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot"
IMAGE_BOOT_FILES ?= " ${@bb.utils.contains('UBOOT_SIGN_ENABLE', '1', 'fitImage', 'Image zynqmp-zcu102-rev1.0.dtb', d)}"

# multilib support
MULTILIBS ?= "multilib:lib32"
DEFAULTTUNE_virtclass-multilib-lib32 ?= "armv7athf-neon"

COMPATIBLE_HOST_pn-netmap_xilinx-zynqmp = "null"

XSERVER ?= "xserver-xorg \
	   xserver-xorg-extension-dri \
	   xserver-xorg-extension-dri2 \
	   xf86-input-mouse \
	   xf86-input-keyboard \
	   xf86-input-evdev \
	   xf86-video-fbdev \
	   xf86-video-armsoc \
	   matchbox-wm"

PREFERRED_PROVIDER_virtual/kernel ??= "linux-yocto"
OSTREE_BOOTLOADER_INCLUDE ?= ""
OSTREE_SD_UBOOT_WIC1 ?= ""
OSTREE_SD_BOOT_ALIGN ?= "4096"
OSTREE_FDISK_BLM ?= "8192"
OSTREE_FDISK_FSZ ?= "132"
OSTREE_KERNEL ?= "Image"
OSTREE_UBOOT_CMD ?= "booti"
