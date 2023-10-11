FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://bsp.cfg"
KERNEL_FEATURES:append = " bsp.cfg"
SRC_URI += "file://user_2023-06-13-03-55-00.cfg \
            file://user_2023-06-13-04-32-00.cfg \
            file://user_2023-10-02-14-46-00.cfg \
            "

