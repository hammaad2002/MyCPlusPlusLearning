if test -d tmp;then
    rm -rf tmp
fi
mkdir -p tmp/build
cd tmp/build
cmake ../..
make -j$(nproc)

cp example.cpython-310-x86_64-linux-gnu.so ../../example.cpython-310-x86_64-linux-gnu.so