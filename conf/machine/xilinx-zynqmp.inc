#@TYPE: Machine inc.
#@NAME: zynqmp layer

DEFAULTTUNE = "aarch64"
require conf/machine/include/arm/arch-armv8.inc

MACHINE_FEATURES += "ext3 pci usbgadget usbhost vfat keyboard screen network"
DISTRO_FEATURES_remove = " wayland"

KERNEL_IMAGETYPE = "Image"
KERNEL_DEVICETREE_xilinx-zynqmp = "xilinx/zynqmp-zcu102-rev1.0.dtb"

SERIAL_CONSOLE = "115200 ttyPS0"

IMAGE_FSTYPES += "tar.bz2 wic wic.bmap"
WKS_FILE ?= "zynqmp-sdimage.wks"
IMAGE_INSTALL_append = " kernel-devicetree kernel-image-image"
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot"
IMAGE_BOOT_FILES ?= " Image zynqmp-zcu102-rev1.0.dtb"


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

PREFERRED_VERSION_linux-yocto ?= "4.12%"
