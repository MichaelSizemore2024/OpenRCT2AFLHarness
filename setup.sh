export AFL_PATH=$HOME/AFLplusplus
export PATH=$PATH:$AFL_PATH
sudo sh -c "echo core >/proc/sys/kernel/core_pattern"
sudo sysctl -w kernel.core_pattern="core" > /dev/null
sudo sysctl -w kernel.randomize_va_space=0 > /dev/null
#sudo sh -c "echo performance | tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor"
