#! /bin/bash

sudo ip addr add 172.16.1.1/12 dev enx5882a88b4f28 

sudo systemctl restart rsync
sudo systemctl restart isc-dhcp-server
sudo systemctl restart tftpd-hpa

sudo systemctl status rsync
sudo systemctl status isc-dhcp-server
sudo systemctl status tftpd-hpa
