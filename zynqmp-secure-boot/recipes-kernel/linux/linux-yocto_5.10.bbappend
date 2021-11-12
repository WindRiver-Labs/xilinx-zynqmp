#
# Copyright (C) 2019 Wind River Systems, Inc.
#

#
# Rewrite this function to add signature node
#
fitimage_emit_section_kernel_xilinx-zynqmp() {

	kernel_csum=${KERNEL_CSUM_TYPE}
	if [ -n "${UBOOT_SIGN_ENABLE}" ] ; then
		kernel_sign_keyname="${UBOOT_SIGN_KEYNAME}"
	fi

	ENTRYPOINT="${UBOOT_ENTRYPOINT}"
	if [ -n "${UBOOT_ENTRYSYMBOL}" ]; then
		ENTRYPOINT=`${HOST_PREFIX}nm vmlinux | \
			awk '$3=="${UBOOT_ENTRYSYMBOL}" {print "0x"$1;exit}'`
	fi

	cat << EOF >> ${1}
                kernel-${2} {
                        description = "Linux kernel";
                        data = /incbin/("${3}");
                        type = "kernel";
                        arch = "${UBOOT_ARCH}";
                        os = "linux";
                        compression = "${4}";
                        load = <${UBOOT_LOADADDRESS}>;
                        entry = <${ENTRYPOINT}>;
                        hash-1 {
                                algo = "${kernel_csum}";
                        };
                        signature-1 {
                                algo = "${kernel_csum},${KERNEL_RAS_TYPE}";
                                key-name-hint = "${kernel_sign_keyname}";
                        };
                };
EOF
}

#
# Rewrite this function to add signature node
#
fitimage_emit_section_dtb_xilinx-zynqmp() {

	dtb_csum=${KERNEL_CSUM_TYPE}
	if [ -n "${UBOOT_SIGN_ENABLE}" ] ; then
		dtb_sign_keyname="${UBOOT_SIGN_KEYNAME}"
	fi

	dtb_loadline=""
	dtb_ext=${DTB##*.}
	if [ "${dtb_ext}" = "dtbo" ]; then
		if [ -n "${UBOOT_DTBO_LOADADDRESS}" ]; then
			dtb_loadline="load = <${UBOOT_DTBO_LOADADDRESS}>;"
		fi
	elif [ -n "${UBOOT_DTB_LOADADDRESS}" ]; then
		dtb_loadline="load = <${UBOOT_DTB_LOADADDRESS}>;"
	fi
	cat << EOF >> ${1}
                fdt-${2} {
                        description = "Flattened Device Tree blob";
                        data = /incbin/("${3}");
                        type = "flat_dt";
                        arch = "${UBOOT_ARCH}";
                        compression = "none";
                        ${dtb_loadline}
                        hash-1 {
                                algo = "${dtb_csum}";
                        };
                        signature-1 {
                                algo = "${dtb_csum},${KERNEL_RAS_TYPE}";
                                key-name-hint = "${dtb_sign_keyname}";
                        };
                };
EOF
}

#
# Rewrite this function to rsa4096 support
#
# $1 ... .its filename
# $2 ... Linux kernel ID
# $3 ... DTB image name
# $4 ... ramdisk ID
# $5 ... u-boot script ID
# $6 ... config ID
# $7 ... default flag
#
fitimage_emit_section_config_xilinx-zynqmp() {

	conf_csum=${KERNEL_CSUM_TYPE}
	if [ -n "${UBOOT_SIGN_ENABLE}" ] ; then
		conf_sign_keyname="${UBOOT_SIGN_KEYNAME}"
	fi

	# Test if we have any DTBs at all
	sep=""
	conf_desc=""
	kernel_line=""
	fdt_line=""
	ramdisk_line=""
	setup_line=""
	default_line=""

	if [ -n "${2}" ]; then
		conf_desc="Linux kernel"
		sep=", "
		kernel_line="kernel = \"kernel-${2}\";"
	fi

	if [ -n "${3}" ]; then
		conf_desc="${conf_desc}${sep}FDT blob"
		sep=", "
		fdt_line="fdt = \"fdt-${3}\";"
	fi

	if [ -n "${4}" ]; then
		conf_desc="${conf_desc}${sep}ramdisk"
		sep=", "
		ramdisk_line="ramdisk = \"ramdisk-${4}\";"
	fi

	if [ -n "${6}" ]; then
		conf_desc="${conf_desc}${sep}setup"
		setup_line="setup = \"setup-${5}\";"
	fi

	if [ "${7}" = "1" ]; then
		default_line="default = \"conf-${3}\";"
	fi

	cat << EOF >> ${1}
                ${default_line}
                conf-${3} {
			description = "${6} ${conf_desc}";
			${kernel_line}
			${fdt_line}
			${ramdisk_line}
			${setup_line}
                        hash-1 {
                                algo = "${conf_csum}";
                        };
EOF

	if [ ! -z "${conf_sign_keyname}" ] ; then

		sign_line="sign-images = "
		sep=""

		if [ -n "${2}" ]; then
			sign_line="${sign_line}${sep}\"kernel\""
			sep=", "
		fi

		if [ -n "${3}" ]; then
			sign_line="${sign_line}${sep}\"fdt\""
			sep=", "
		fi

		if [ -n "${4}" ]; then
			sign_line="${sign_line}${sep}\"ramdisk\""
			sep=", "
		fi

		if [ -n "${5}" ]; then
			sign_line="${sign_line}${sep}\"setup\""
		fi

		sign_line="${sign_line};"

		cat << EOF >> ${1}
                        signature-1 {
                                algo = "${conf_csum},${KERNEL_RAS_TYPE}";
                                key-name-hint = "${conf_sign_keyname}";
				${sign_line}
                        };
EOF
	fi

	cat << EOF >> ${1}
                };
EOF
}
