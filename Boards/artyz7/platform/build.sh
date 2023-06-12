#! /bin/bash

# Clean
petalinux-build -x mrproper -f

# Pull XSA again?

petalinux-build
petalinux-package --boot --fsbl ./images/linux/zynq_fsbl.elf --fpga ./images/linux/system.bit --u-boot --force
