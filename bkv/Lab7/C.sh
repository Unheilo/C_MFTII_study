#!/bin/bash
gcc  -I /usr/include/cairo -I /usr/include/harfbuzz -I /usr/include/atk-1.0 -I /usr/include/gdk-pixbuf-2.0 -I /usr/include/glib-2.0 -I /usr/include/pango-1.0 -I /usr/lib/x86_64-linux-gnu/gtk-2.0/include -I /usr/lib/x86_64-linux-gnu/glib-2.0/include $1  -L /usr/lib/x86_64-linux-gnu -lcairo -lgtk-3 -lgdk-3 -latk-1.0  -lglib-2.0 -lgobject-2.0 -lpthread -L. -lmat


