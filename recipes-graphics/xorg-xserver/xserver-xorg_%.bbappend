REMOVED_OPENGL_PKGCONFIGS_xilinx-zynqmp ?= "${@bb.utils.contains('PNWHITELIST_wr-xilinx-zynqmp', 'libmali-xlnx', 'glamor', '', d)}"
