VERSION=0.1
LDFLAGS += -lgd
CFLAGS += -Wall -Wextra -I.
SOURCES := jutils.o captcha.o

all: ${SOURCES}
	ar r libcaptcha.a ${SOURCES}

clean:
	rm -f libcaptcha.a ${SOURCES}

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -DVERSION=\"${VERSION}\"
