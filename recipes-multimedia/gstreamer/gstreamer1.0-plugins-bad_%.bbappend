DEPENDS_append_xilinx-zynqmp += " ${@bb.utils.contains('DISTRO_FEATURES', 'x11', ' libxdamage libxfixes', '', d)}"
PACKAGECONFIG_append_xilinx-zynqmp = " kms"
