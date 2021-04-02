do_compile_xilinx-zynqmp() {
    default_dtb="${DEFAULT_DTB}"
    if [ "$default_dtb" = "" ] ; then
        for k in `echo ${KERNEL_DEVICETREE} |grep -v dtbo`; do
            default_dtb="$(basename $k)"
            break;
        done
        bbwarn 'DEFAULT_DTB=""'
        bbwarn "boot.scr set to DEFAULT_DTB=$default_dtb"
    fi  
    if [ "${OSTREE_BOOTSCR}" = "fs_links" ] ; then
        bootscr_fs_links
    else
        bootscr_env_import
    fi  

    build_date=`date -u +%s`
    sed -i -e  "s/instdate=BUILD_DATE/instdate=@$build_date/" ${WORKDIR}/uEnv.txt
    sed -i '3a\setenv loadaddr 0x10000000\nsetenv fdt_addr 0xE0000\nsetenv initrd_addr 0x40000000\nsetenv console  ttyPS0\nsetenv baudrate 115200' ${WORKDIR}/uEnv.txt
    mkimage -A arm -T script -O linux -d ${WORKDIR}/uEnv.txt ${WORKDIR}/boot.scr
}


