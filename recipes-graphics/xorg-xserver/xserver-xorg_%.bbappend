OPENGL_PKGCONFIGS_remove_xilinx-zynqmp ?= "${@bb.utils.contains('PNWHITELIST_wr-xilinx-zynqmp', 'libmali-xlnx', 'glamor', '', d)}"
