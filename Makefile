RM := rm
CC := clang
CFLAGS := -Wall -Wextra -std=c17 -pedantic -g -lm

BUILDDIR := build
SRCDIR := src
SRCS := $(wildcard $(SRCDIR)/*.c)
TARGETS := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%,$(SRCS))

all: $(BUILDDIR) $(TARGETS)

$(BUILDDIR):
	mkdir $@

$(BUILDDIR)/%: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

%: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $(BUILDDIR)/$@ $<

clean:
	$(RM) -rf $(BUILDDIR)/*


.PHONY: clean all
