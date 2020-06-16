YAML_DT_BOARD_FLAGS_xilinx-zynqmp = "{BOARD zcu102-rev1.0}"
YAML_KERNEL_VERSION_xilinx-zynqmp = "wrlinux-cicd-zcu102"
XSCTH_PROC_xilinx-zynqmp = "psu_cortexa53_0"

DEPENDS += "virtual/kernel"

do_configure_prepend_xilinx-zynqmp() {
    if [ -e ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION} ]; then
        rm -rf ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}
    fi
    mkdir -p ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/BOARD
    cp ${STAGING_KERNEL_DIR}/arch/${ARCH}/boot/dts/xilinx/zynqmp-zcu102-rev1.0.dts ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/BOARD/zcu102-rev1.0.dtsi
    mkdir -p ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/include/dt-bindings/gpio
    mkdir -p ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/include/dt-bindings/input
    mkdir -p ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/include/dt-bindings/interrupt-controller
    mkdir -p ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/include/dt-bindings/phy
    mkdir -p ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/include/dt-bindings/pinctrl
    cp ${STAGING_KERNEL_DIR}/include/dt-bindings/gpio/gpio.h ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/include/dt-bindings/gpio
    cp ${STAGING_KERNEL_DIR}/include/dt-bindings/input/input.h ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/include/dt-bindings/input
    cp ${STAGING_KERNEL_DIR}/include/dt-bindings/interrupt-controller/irq.h ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/include/dt-bindings/interrupt-controller
    cp ${STAGING_KERNEL_DIR}/include/dt-bindings/phy/phy.h ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/include/dt-bindings/phy
    cp ${STAGING_KERNEL_DIR}/include/dt-bindings/pinctrl/pinctrl-zynqmp.h ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/include/dt-bindings/pinctrl
    mkdir -p ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/zynqmp
    cp ${STAGING_KERNEL_DIR}/arch/${ARCH}/boot/dts/xilinx/zynqmp.dtsi ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/zynqmp/zynqmp.dtsi
    cp ${STAGING_KERNEL_DIR}/arch/${ARCH}/boot/dts/xilinx/zynqmp-clk-ccf.dtsi ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/zynqmp/zynqmp-clk-ccf.dtsi
    cp ${STAGING_KERNEL_DIR}/arch/${ARCH}/boot/dts/xilinx/zynqmp-zcu102-revA.dts ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/zynqmp/zynqmp-zcu102-revA.dtsi
    cp ${STAGING_KERNEL_DIR}/arch/${ARCH}/boot/dts/xilinx/zynqmp-zcu102-revB.dts ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/zynqmp/zynqmp-zcu102-revB.dtsi

    sed -i 's/zynqmp-zcu102-revB.dts/zynqmp-zcu102-revB.dtsi/g' ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/BOARD/zcu102-rev1.0.dtsi
    sed -i 's/zynqmp-zcu102-revA.dts/zynqmp-zcu102-revA.dtsi/g' ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/zynqmp/zynqmp-zcu102-revB.dtsi
    sed -i '/dts-v1/d' ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/zynqmp/zynqmp-zcu102-revA.dtsi

    mkdir -p ${B}/device-tree/include/dt-bindings/power
    mkdir -p ${B}/device-tree/include/dt-bindings/reset
    cp ${STAGING_KERNEL_DIR}/include/dt-bindings/power/xlnx-zynqmp-power.h ${B}/device-tree/include/dt-bindings/power
    cp ${STAGING_KERNEL_DIR}/include/dt-bindings/reset/xlnx-zynqmp-resets.h ${B}/device-tree/include/dt-bindings/reset
}

COMPATIBLE_MACHINE_xilinx-zynqmp = "xilinx-zynqmp"
