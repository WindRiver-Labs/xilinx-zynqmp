#
# Copyright (C) 2019 Wind River Systems, Inc.
#

UBOOT_SIGN_ENABLE = "1"
UBOOT_SIGN_KEYDIR = "${@bb.utils.contains('KERNEL_RAS_TYPE', 'rsa4096', '${LAYER_PATH_zynqmp-secure-layer}/zynqmp_keys/fitImage-rsa4096-keys', '${LAYER_PATH_zynqmp-secure-layer}/zynqmp_keys/fitImage-rsa2048-keys', d)}"
UBOOT_MKIMAGE_DTCOPTS = "-I dts -O dtb -p 2000"
UBOOT_SIGN_KEYNAME = "dev"

UBOOT_ENTRYPOINT = "0x80000"
UBOOT_LOADADDRESS = "0x80000"

UBOOT_ELF="u-boot.elf"
UBOOT_ELF_SUFFIX ?= "elf"

UBOOT_MACHINE = "xilinx_zynqmp_zcu102_rev1_0_defconfig"
SPL_BINARY ?= "spl/boot.bin"
PREFERRED_PROVIDER_u-boot = "u-boot-xlnx"

KERNEL_CLASSES  = " kernel-fitimage "

# Xilinx secure boot feature supports rsa2048 and rsa4096 key type.
# Set KERNEL_RAS_TYPE as the expected value. The default one is rsa2048.
KERNEL_RAS_TYPE = "rsa2048"
#KERNEL_RAS_TYPE = "rsa4096"

# Xilinx secure boot feature supports sha1 and sha256 digest.
# Set KERNEL_CSUM_TYPE as the expected value. The default one is sha1.
KERNEL_CSUM_TYPE = "sha1"
#KERNEL_CSUM_TYPE = "sha256"

IMAGE_INSTALL += " u-boot-xlnx"
PNWHITELIST_zynqmp-secure-layer += 'u-boot-xlnx'
