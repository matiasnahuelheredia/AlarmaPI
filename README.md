# AlarmaPI
Alarm for Raspberry PI

### Hardware Requeriments
* Raspberry PI 
* Wifi Dongle
* Motorola C115 (optional)
* Jack for Motorola C115 handset and Arduino Female Wires 
* I2C Display 24 x 4

### Dependencies

* Boost.Asio or standalone Asio
* Boost is required to compile the examples
* For HTTPS: OpenSSL libraries 
* libpcap
* openssl
### Dependencies Instalation
*Centos
```sh
yum install git -y
yum install libpcap-devel -y
yum install cmake -y
yum install openssl* -y
```
*Fedora
```sh
dnf install git -y
dnf install *libpcap* -y
dnf install cmake -y
dnf install *openssl* -y
```

*Debian
```sh
apt-get install libpcap-dev -y
apt-get install i2c-tools -y
apt-get install cmake -y
apt-get install openssl-devel -y

```

```sh
su
cd /opt/
git clone https://github.com/mfontanini/libtins.git
# Create the build directory
mkdir build
cd build

# Configure the project. Add any relevant configuration flags
cmake ../ -DLIBTINS_ENABLE_CXX11=1

# Compile!
make
make install
ldconfig
```

### Compile and run
Compile with
```sh
make
./Alarma
```
