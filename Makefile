RACK_DIR ?= ../../Rack

# FLAGS will be passed to both the C and C++ compiler
FLAGS +=
CFLAGS +=
CXXFLAGS += -w

# Careful about linking to shared libraries, since you can't assume much about the user's environment and library search path.
# Static libraries are fine, but they should be added to this plugin's build system.
LDFLAGS +=

# Add .cpp files to the build
SOURCES += $(wildcard src/Folding/*.cpp)
SOURCES += $(wildcard src/*.cpp)


# Add files to the ZIP package when running `make dist`
# The compiled plugin and "plugin.json" are automatically added.
DISTRIBUTABLES += res
DISTRIBUTABLES += $(wildcard LICENSE*)

include $(RACK_DIR)/plugin.mk
