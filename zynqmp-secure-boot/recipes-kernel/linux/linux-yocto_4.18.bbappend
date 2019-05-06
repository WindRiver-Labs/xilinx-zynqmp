#
# Copyright (C) 2019 Wind River Systems, Inc.
#

#
# Rewrite this function to add signature node
#
fitimage_emit_section_kernel_xilinx-zynqmp() {

	kernel_csum="sha1"
	if [ -n "${UBOOT_SIGN_ENABLE}" ] ; then
		kernel_sign_keyname="${UBOOT_SIGN_KEYNAME}"
	fi

	ENTRYPOINT="${UBOOT_ENTRYPOINT}"
	if [ -n "${UBOOT_ENTRYSYMBOL}" ]; then
		ENTRYPOINT=`${HOST_PREFIX}nm vmlinux | \
			awk '$3=="${UBOOT_ENTRYSYMBOL}" {print "0x"$1;exit}'`
	fi

	cat << EOF >> ${1}
                kernel@${2} {
                        description = "Linux kernel";
                        data = /incbin/("${3}");
                        type = "kernel";
                        arch = "${UBOOT_ARCH}";
                        os = "linux";
                        compression = "${4}";
                        load = <${UBOOT_LOADADDRESS}>;
                        entry = <${ENTRYPOINT}>;
                        hash@1 {
                                algo = "${kernel_csum}";
                        };
                        signature@1 {
                                algo = "${kernel_csum},rsa2048";
                                key-name-hint = "${kernel_sign_keyname}";
                        };
                };
EOF
}

#
# Rewrite this function to add signature node
#
fitimage_emit_section_dtb_xilinx-zynqmp() {

	dtb_csum="sha1"
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
                fdt@${2} {
                        description = "Flattened Device Tree blob";
                        data = /incbin/("${3}");
                        type = "flat_dt";
                        arch = "${UBOOT_ARCH}";
                        compression = "none";
                        ${dtb_loadline}
                        hash@1 {
                                algo = "${dtb_csum}";
                        };
                        signature@1 {
                                algo = "${dtb_csum},rsa2048";
                                key-name-hint = "${dtb_sign_keyname}";
                        };
                };
EOF
}
