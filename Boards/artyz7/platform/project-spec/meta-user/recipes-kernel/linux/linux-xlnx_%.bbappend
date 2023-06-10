FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://bsp.cfg"
KERNEL_FEATURES:append = " bsp.cfg"
SRC_URI += "file://user_2023-06-06-18-32-00.cfg \
            file://user_2023-06-06-18-41-00.cfg \
            "

