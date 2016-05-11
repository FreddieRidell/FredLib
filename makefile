CC = clang++
INCLUDEPATHS = -I./Inc
COMPILEFLAGS = -std=gnu++14 -Wall -pthread -g
PROJECTNAME = FreddieLib
EXE_NAME = $(PROJECTNAME).out
TESTS_EXE_NAME = test

# cpp source files and compiled objects
CPP_SRC = $(shell find Src -name "*.cpp")
TEST_SRC = $(shell find Test -name "*.cpp")
CPP_UNITS = $(CPP_SRC:%.cpp=%.o)
TEST_UNITS = $(TEST_SRC:%.cpp=%.o)

DEPENDANCY_FILES = $(CPP_SRC:%.cpp=%.d) $(TEST_SRC:%.cpp=%.d)
MAKEFILES = $(shell find Makefiles -name "*.makefile")

all: $(EXE_NAME)

test: $(TESTS_EXE_NAME)

run: $(EXE_NAME)
	./$(EXE_NAME)

runTest: $(TESTS_EXE_NAME)
	./$(TESTS_EXE_NAME)

include $(MAKEFILES)
-include $(DEPENDANCY_FILES)

$(EXE_NAME): $(DEPENDANCY_FILES) $(CPP_UNITS)
	@ echo "Compiling main runtime"
	@ $(CC) $(CPP_UNITS) \
	$(INCLUDEPATHS) \
	$(COMPILEFLAGS) \
	-o $(EXE_NAME)

$(TESTS_EXE_NAME): $(DEPENDANCY_FILES) $(EXE_NAME) $(TEST_UNITS) $(GTEST_LIBRARY) $(GMOCK_LIBRARY)
	@ echo "Compiling test runtime"
	@ $(CC) \
	$(TEST_UNITS) \
	$(filter-out Src/main.o, $(CPP_UNITS)) \
	$(GTEST_LIBRARY) \
	$(GMOCK_LIBRARY) \
	$(INCLUDEPATHS) \
	-I$(GTEST_HEADER) \
	-I$(GMOCK_HEADER) \
	$(COMPILEFLAGS) \
	-o $(TESTS_EXE_NAME)

clean:
	rm -rf $(CPP_UNITS) $(TEST_UNITS) $(DEPENDANCY_FILES)
