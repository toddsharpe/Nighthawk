
connect
for {set i 0} {$i < 20} {incr i} {
	if { [ta] != "" } break;
	after 50
}
puts stderr "INFO: Configuring the FPGA..."
puts stderr "INFO: Downloading bitstream: /home/tsharpe/GitHub/toddsharpe/Nighthawk/Boards/artyz7/platform/images/linux/system.bit to the target."
fpga "/home/tsharpe/GitHub/toddsharpe/Nighthawk/Boards/artyz7/platform/images/linux/system.bit"
targets -set -nocase -filter {name =~ "arm*#0"}

source /home/tsharpe/GitHub/toddsharpe/Nighthawk/Boards/artyz7/platform/project-spec/hw-description/ps7_init.tcl; ps7_post_config
if { [string first "Stopped" [state]] != 0 } {
stop
}
set mctrlval [format 0x%x [mrd -value 0xF8007080]]
puts "mctrlval=$mctrlval"
puts stderr "INFO: Downloading ELF file: /home/tsharpe/GitHub/toddsharpe/Nighthawk/Boards/artyz7/platform/images/linux/zynq_fsbl.elf to the target."
dow  "/home/tsharpe/GitHub/toddsharpe/Nighthawk/Boards/artyz7/platform/images/linux/zynq_fsbl.elf"
con

after 3000
stop
puts stderr "INFO: Loading image: /home/tsharpe/GitHub/toddsharpe/Nighthawk/Boards/artyz7/platform/images/linux/system.dtb at 0x00100000"
dow -data  "/home/tsharpe/GitHub/toddsharpe/Nighthawk/Boards/artyz7/platform/images/linux/system.dtb" 0x00100000
puts stderr "INFO: Downloading ELF file: /home/tsharpe/GitHub/toddsharpe/Nighthawk/Boards/artyz7/platform/images/linux/u-boot.elf to the target."
dow  "/home/tsharpe/GitHub/toddsharpe/Nighthawk/Boards/artyz7/platform/images/linux/u-boot.elf"
con

after 1000; stop
puts stderr "INFO: Loading image: /home/tsharpe/GitHub/toddsharpe/Nighthawk/Boards/artyz7/platform/images/linux/uImage at 0x00200000"
dow -data  "/home/tsharpe/GitHub/toddsharpe/Nighthawk/Boards/artyz7/platform/images/linux/uImage" 0x00200000
puts stderr "INFO: Loading image: /home/tsharpe/GitHub/toddsharpe/Nighthawk/Boards/artyz7/platform/images/linux/boot.scr at 0x03000000"
dow -data  "/home/tsharpe/GitHub/toddsharpe/Nighthawk/Boards/artyz7/platform/images/linux/boot.scr" 0x03000000

con
puts stderr "INFO: Enter bootm 0x00200000 - 0x00100000 in uboot terminal if auto boot fails"
exit
puts stderr "INFO: Saving XSDB commands to mytcl. You can run 'xsdb mytcl' to execute"
