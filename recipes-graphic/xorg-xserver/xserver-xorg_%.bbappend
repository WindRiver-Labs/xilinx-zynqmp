PACKAGECONFIG_remove_xilinx-zynqmp = "${@bb.utils.contains('PNWHITELIST_xilinx', 'libmali-xlnx', ' dri glx xwayland', '', d)}"
