#@TYPE: Machine inc.
#@NAME: zynqmp layer

DEFAULTTUNE = "aarch64"
require conf/machine/include/arm/arch-armv8.inc

MACHINE_FEATURES += "ext3 pci usbgadget usbhost vfat keyboard screen network"
DISTRO_FEATURES_remove = " wayland"

KERNEL_IMAGETYPE = "Image"
KERNEL_DEVICETREE_xilinx-zynqmp = "xilinx/zynqmp-zcu102-rev1.0.dtb"

SERIAL_CONSOLE = "115200 ttyPS0"

IMAGE_FSTYPES += "tar.bz2"

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

# PREFERRED_PROVIDER_virtual/mesa_xilinx-zynqmp = "mesa-gl"
# PREFERRED_PROVIDER_virtual/libgl_xilinx-zynqmp = "mesa-gl"
# PREFERRED_PROVIDER_virtual/libgles1_xilinx-zynqmp = "libmali-xlnx"
# PREFERRED_PROVIDER_virtual/libgles2_xilinx-zynqmp = "libmali-xlnx"
# PREFERRED_PROVIDER_virtual/egl_xilinx-zynqmp = "libmali-xlnx"
