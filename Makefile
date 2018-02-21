CFLAGS += -Wall

ALL = cpueater memeater

all: $(ALL)

clean:
	$(RM) $(ALL)

.PHONY: clean

