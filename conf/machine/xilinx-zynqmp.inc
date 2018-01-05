#@TYPE: Machine inc.
#@NAME: zynqmp layer

DEFAULTTUNE = "aarch64"
require conf/machine/include/arm/arch-armv8.inc

MACHINE_FEATURES += "usbhost ext3 vfat pci"

KERNEL_IMAGETYPE = "Image"

SERIAL_CONSOLE = "115200 ttyPS0"

IMAGE_FSTYPES += "tar.bz2 wic wic.bmap"
WKS_FILE = "sdimage.wks"
do_image_wic[depends] += "mtools-native:do_populate_sysroot  dosfstools-native:do_populate_sysroot"

# multilib support
MULTILIBS ?= "multilib:lib32"
DEFAULTTUNE_virtclass-multilib-lib32 ?= "armv7athf-neon"

COMPATIBLE_HOST_pn-netmap_xilinx-zynqmp = "null"

# xserver-common, x11-common
VIRTUAL-RUNTIME_xserver_common ?= "x11-common"

# xserver-nodm-init, anaconda-init
VIRTUAL-RUNTIME_graphical_init_manager ?= "xserver-nodm-init"

XSERVER ?= "xserver-xorg \
	   xserver-xorg-extension-dri \
	   xserver-xorg-extension-dri2 \
	   xserver-xorg-extension-glx \
	   xserver-xorg-extension-extmod \
	   xserver-xorg-extension-dbe \
	   xserver-xorg-module-libint10 \
	   ${VIRTUAL-RUNTIME_graphical_init_manager} \
	   xf86-input-mouse \
	   xf86-input-keyboard \
	   xf86-input-evdev \
	   xf86-input-synaptics \
	   xf86-video-fbdev \
	   xf86-video-modesetting \
	   xf86-video-armsoc \
	   mesa \
	   mesa-demos \
	   ${VIRTUAL-RUNTIME_xserver_common} \
	   matchbox-wm"

PREFERRED_PROVIDER_libglu = "libglu"
PREFERRED_VERSION_virtual/mesa = "9.2.0"
