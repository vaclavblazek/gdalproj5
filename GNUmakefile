# run all targets sequentially
.NOTPARALLEL:

.DEFAULT_GOAL := all

BUILDDIR=build

all .DEFAULT: FORCE
	$(call bootstrap)
    # forward to build directory
	@(unset MAKELEVEL; cd $(BUILDDIR) && $(MAKE) $@)

FORCE:

.PHONY: FORCE purge

purge:
	rm -rf $(BUILDDIR)

define bootstrap_dirs
	@echo "* Building in $(BUILDDIR)"
	@(mkdir -p $(BUILDDIR))
endef

define bootstrap
	$(call bootstrap_dirs)
	@test -f $(BUILDDIR)/Makefile || (cd $(BUILDDIR) && cmake ..)
endef

