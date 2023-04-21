# Compiler and Linker
CC          := gcc
CXX         := g++

# Project name
PROJECT     := LinkedListDriver

# Directories: Includes, Sources, Binaries
SRC_DIR     := src
INC_DIR     := include
DIST_DIR    := dist

# Flags, Libraries and Includes
CFLAGS      := -Wall -pedantic -ansi -std=c++11 -I$(INC_DIR)
LDFLAGS     := -I$(INC_DIR)

# Do not modify below...
OBJ_DIR     := $(DIST_DIR)/obj
TARGET      := $(DIST_DIR)/$(PROJECT)

SRCS        := $(shell find $(SRC_DIR) -name *.cc)
OBJS        := $(patsubst %.cc,$(OBJ_DIR)/%.o,$(SRCS))

SRC_DIRS    := $(shell find . -name *.cc -exec dirname {} \; | uniq)

all: $(TARGET)

$(TARGET) : build-repo $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: %.cc
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJ_DIR)

dist-clean: clean
	@$(RM) -rf $(DIST_DIR)

build-repo:
	@$(call make-repo)

define make-repo
   for dir in $(SRC_DIRS); \
   do \
	mkdir -p $(OBJ_DIR)/$$dir; \
   done
endef

.PHONY: all build-repo clean dist-clean
