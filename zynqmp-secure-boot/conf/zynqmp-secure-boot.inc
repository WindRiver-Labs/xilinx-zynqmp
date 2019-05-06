#
# Copyright (C) 2019 Wind River Systems, Inc.
#

UBOOT_SIGN_ENABLE = "1"
UBOOT_SIGN_KEYDIR = "${LAYER_PATH_zynqmp-secure-layer}/zynqmp_keys/fitImgae-rsa2048-keys"
UBOOT_MKIMAGE_DTCOPTS = "-I dts -O dtb -p 2000"
UBOOT_SIGN_KEYNAME = "dev"

UBOOT_ENTRYPOINT = "0x80000"
UBOOT_LOADADDRESS = "0x80000"

UBOOT_MACHINE = "xilinx_zynqmp_zcu102_rev1_0_defconfig"
SPL_BINARY ?= "spl/boot.bin"
PREFERRED_PROVIDER_u-boot = "u-boot-xlnx"

KERNEL_CLASSES  = " kernel-fitimage "

IMAGE_INSTALL += " u-boot-xlnx"
PNWHITELIST_zynqmp-secure-layer += 'u-boot-xlnx'
