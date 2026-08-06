ROOT_DIR := $(abspath $(CURDIR)/..)
OBJCRYST_TEST_DIR := $(ROOT_DIR)/src/objcryst/test
UNIT_SRC_DIR := $(OBJCRYST_TEST_DIR)/unit
BUILD ?= fast
ARCH ?= $(shell uname -m)
BUILD_DIR ?= $(ROOT_DIR)/build/$(BUILD)-$(ARCH)
LIBOBJCRYST ?= $(firstword $(wildcard $(BUILD_DIR)/src/libObjCryst*.so) \
	$(wildcard $(BUILD_DIR)/src/libObjCryst*.dylib) \
	$(wildcard $(BUILD_DIR)/src/libObjCryst*.dll) \
	$(wildcard $(BUILD_DIR)/src/libObjCryst*.a) \
	$(wildcard $(BUILD_DIR)/libObjCryst*.so) \
	$(wildcard $(BUILD_DIR)/libObjCryst*.dylib) \
	$(wildcard $(BUILD_DIR)/libObjCryst*.dll) \
	$(wildcard $(BUILD_DIR)/libObjCryst*.a))
BIN_DIR := $(CURDIR)/bin/$(BUILD)-$(ARCH)
OBJ_DIR := $(CURDIR)/obj/$(BUILD)-$(ARCH)
RUNNER := $(CURDIR)/run_unit_tests.sh
TEST_RUNNER := $(CURDIR)/test_runner.sh

RM ?= rm -f
MKDIR_P ?= mkdir -p

CXX ?= c++
CXXFLAGS ?= -O2 -std=c++14
CPPFLAGS += -DREAL=double \
	-I$(ROOT_DIR)/src \
	-I$(ROOT_DIR)/src/objcryst \
	-I$(ROOT_DIR)/src/objcryst/test/unit \
	-I$(BUILD_DIR)/src \
	-I$(BUILD_DIR)/src/objcryst \
	-I$(BUILD_DIR)/src/version \
	-I$(ROOT_DIR)/src/objcryst/ObjCryst \
	-I$(ROOT_DIR)/src/objcryst/cctbx/include
LDFLAGS += -L$(abspath $(dir $(LIBOBJCRYST)))
LDLIBS += $(abspath $(LIBOBJCRYST))
ifeq ($(origin CONDA_PREFIX), undefined)
CONDA_PREFIX :=
endif

ifeq ($(shell uname -s),Darwin)
RPATH_FLAG = -Wl,-rpath,$(dir $(LIBOBJCRYST))
ifneq ($(strip $(CONDA_PREFIX)),)
RPATH_FLAG += -Wl,-rpath,$(CONDA_PREFIX)/lib
endif
else
RPATH_FLAG = -Wl,-rpath,$(dir $(LIBOBJCRYST))
endif

UNIT_TESTS := unit_cell_smoke crystallography_workflow \
	api_spacegroup api_crystal api_molecule api_scattering \
	api_powderpattern api_cif api_optimization api_indexing \
	ground_truth

UNIT_BINS := $(addprefix $(BIN_DIR)/,$(UNIT_TESTS))
UNIT_OBJS := $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(UNIT_TESTS)))

.SECONDARY: $(UNIT_OBJS)

.PHONY: all build run clean tidy check-layout

all: build run

build: check-layout $(UNIT_BINS) $(RUNNER)

run: build $(RUNNER)
	@cd $(UNIT_SRC_DIR) && TEST_TIMEOUT="$${FOX_TEST_TIMEOUT:-30s}" BUILD="$(BUILD)" "$(RUNNER)"

check-layout:
	@test -d "$(UNIT_SRC_DIR)" || { echo "Missing upstream unit test sources at $(UNIT_SRC_DIR)"; exit 1; }
	@test -f "$(TEST_RUNNER)" || { echo "Missing shared test runner at $(TEST_RUNNER)"; exit 1; }
	@test -n "$(LIBOBJCRYST)" || { echo "No built libObjCryst found under $(BUILD_DIR). Build libobjcryst first."; exit 1; }
	@test -f "$(ROOT_DIR)/src/objcryst/test/data/cif/PbSO4-COD-1528837.cif" || { echo "Missing required test data in src/objcryst/test/data"; exit 1; }

$(BIN_DIR) $(OBJ_DIR):
	@$(MKDIR_P) "$@"

$(OBJ_DIR)/%.o: $(UNIT_SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/%: $(OBJ_DIR)/%.o | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(RPATH_FLAG) $< -o $@ $(LDLIBS)

$(RUNNER):
	@chmod +x "$(RUNNER)"

tidy:
	@$(RM) $(UNIT_OBJS)

clean: tidy
	@$(RM) $(UNIT_BINS) "$(RUNNER)"
