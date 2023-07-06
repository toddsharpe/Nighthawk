#
# This file is the bootscript recipe.
#

SUMMARY = "Simple bootscript application"
SECTION = "PETALINUX/apps"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://bootscript file://runtime_kill"

S = "${WORKDIR}"

#FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
inherit update-rc.d

INITSCRIPT_NAME = "bootscript"
INITSCRIPT_PARAMS = "start 90 5 ."

do_install() {
		install -d ${D}/${bindir}
		install -m 0755 ${S}/bootscript ${D}/${bindir}
		install -d ${D}/${bindir}
		install -m 0755 ${S}/runtime_kill ${D}/${bindir}
		install -d ${D}${sysconfdir}/init.d
		install -m 0755 ${S}/bootscript ${D}${sysconfdir}/init.d/bootscript
}

FILES_${PN} += "${sysconfdir}/*"