# GNU Make solution makefile autogenerated by Premake
# Type "make help" for usage help

ifndef config
  config=debug
endif
export config

PROJECTS := inaction

.PHONY: all clean help $(PROJECTS)

all: $(PROJECTS)

inaction: 
	@echo "==== Building inaction ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f inaction.make

clean:
	@${MAKE} --no-print-directory -C . -f inaction.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "   debug"
	@echo "   release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   inaction"
	@echo ""
	@echo "For more information, see http://industriousone.com/premake/quick-start"
