# GxEPD2_test
ESP32-C3

```
sudo apt -y install python3-full python3-virtualenv
virtualenv .
source bin/activate
pip3 install platformio

pip3 install --upgrade pip
python3 -m pip install --upgrade setuptools

git clone https://github.com/markbirss/GxEPD2_test.git
cd GxEPD2_test

pio run -e esp32-c3-devkit -t upload
```
