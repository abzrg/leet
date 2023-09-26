RM := rm
CC := clang
CFLAGS := -Wall -Wextra -std=c17 -pedantic -g -Wno-unused-function
ASANFLAGS :=
LDFLAGS := -lm
CPPFLAGS := -I./


# Check if the OS is Windows
ifeq ($(OS),Windows_NT)
  # Check if the compiler is Microsoft Visual C++
  ifeq ($(CC),cl)
    LDFLAGS += -link Kernel32.lib
  else
    # Check if clang is available on Windows using the 'where' command
    ifeq (0,$(shell where clang >NUL 2>&1 && echo 0))
      CC := clang
    else
      CC := gcc
    endif
  endif
else
  # Check if the compiler is Clang; otherwise, fallback to GCC
  ifeq (0,$(shell command -v clang >/dev/null 2>&1 && echo 0))
    CC := clang
  else
    CC := gcc
  endif
endif


BUILDDIR := build
SRCDIR := src
SRCS := $(wildcard $(SRCDIR)/*.c)
TARGETS := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%,$(SRCS))


all: $(BUILDDIR) $(TARGETS)


$(BUILDDIR):
	mkdir $@

$(BUILDDIR)/%: $(SRCDIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(ASANFLAGS) -o $@ $<

%: $(SRCDIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(ASANFLAGS) -o $(BUILDDIR)/$@ $<

clean:
	$(RM) -rf $(BUILDDIR)/*


.PHONY: clean all scan
