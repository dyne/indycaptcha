VERSION=0.1
CFLAGS += -Wall -Wextra -I.
SOURCES := jutils.o captcha.o
LDADD := -l:libgd.a
LDFLAGS := -L../lib/gd/Bin


ifneq (,$(findstring shared,$(MAKECMDGOALS)))
CFLAGS += -fPIC
LDFLAGS += -shared
LDADD += -lm
endif

ifneq (,$(findstring debug,$(MAKECMDGOALS)))
CFLAGS += -ggdb
LDADD += -lm -lpng -lfreetype
endif

static-lib: ${SOURCES}
	ar r libindycaptcha.a ${SOURCES}

shared: shared-lib shared-bin

shared-lib: ${SOURCES}
	${CC} ${CFLAGS} ${SOURCES} -o libindycaptcha.so ${LDFLAGS} ${LDADD}

shared-bin: main.o ${SOURCES}
	${CC} ${CFLAGS} ${SOURCES} main.o -o indycaptcha ${LDFLAGS} ${LDADD}

debug-bin: SOURCES += main.o
debug-bin: ${SOURCES} main.o
	${CC} ${CFLAGS} ${SOURCES} -o indycaptcha ${LDFLAGS} ${LDADD}

clean:
	rm -f libcaptcha.a ${SOURCES} main.o

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -DVERSION=\"${VERSION}\"
