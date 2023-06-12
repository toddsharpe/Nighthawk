# Nighthawk

# Platform

## Board generation
```
petalinux-create --type project --template zynq --name platform
petalinux-config --get-hw-description ../hardware
```

## Building Sources
```
tsharpe@tsharpe-i3020:~/GitHub/toddsharpe/Nighthawk/Src$ ~/GitHub/toddsharpe/UBuild/latest.sh build -p Demo
Action: Build
Building Linux/Monitor for Host
        Successfully built /home/tsharpe/GitHub/toddsharpe/Nighthawk/build/Linux/Monitor/Monitor
```

```
tsharpe@tsharpe-i3020:~/GitHub/toddsharpe/Nighthawk/Src$ ~/GitHub/toddsharpe/UBuild/latest.sh package -p Demo
Action: Package
Packaging Demo for Zip
        Successfully built /home/tsharpe/GitHub/toddsharpe/Nighthawk/build/packages/Demo.zip
```