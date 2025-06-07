#!/bin/bash
set -e

# Install build dependencies for Fulcrum on Debian/Ubuntu.

sudo apt-get update
sudo apt-get install -y build-essential pkg-config git cmake \
    qtbase5-dev qtbase5-dev-tools qtchooser qt5-qmake \
    zlib1g-dev libbz2-dev libssl-dev \
    libzmq3-dev libminiupnpc-dev

# Install modern C++20 compiler
sudo apt-get install -y software-properties-common
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install -y gcc-13 g++-13

# Optional packages for additional features
# sudo apt-get install -y librocksdb-dev libjemalloc-dev

echo "All dependencies installed. Run 'qmake' followed by 'make -j$(nproc)' to build Fulcrum."
