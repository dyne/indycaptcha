libs:
	make -C lib

shared: libs
	make -C src shared

debug: libs
	make -C src debug-bin

static: libs
	make -C src static-lib

clean:
	make -C src clean
	make -C lib clean
