cmd_Makefile := cd ..; /usr/local/lib/node_modules/node-gyp/gyp/gyp_main.py -fmake --ignore-environment "--toplevel-dir=." -I/Users/zac/xml/build/config.gypi -I/usr/local/lib/node_modules/node-gyp/addon.gypi -I/Users/zac/.node-gyp/0.10.29/common.gypi "--depth=." "-Goutput_dir=." "--generator-output=build" "-Dlibrary=shared_library" "-Dvisibility=default" "-Dnode_root_dir=/Users/zac/.node-gyp/0.10.29" "-Dmodule_root_dir=/Users/zac/xml" binding.gyp