#! /bin/bash

# Clean
petalinux-build -x mrproper -f

# Pull XSA again?
#petalinux-config --get-hw-description ../hardware

petalinux-build
petalinux-package --boot --fsbl ./images/linux/zynq_fsbl.elf --fpga ./images/linux/system.bit --u-boot --force
