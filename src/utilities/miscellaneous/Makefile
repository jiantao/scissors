OBJ_DIR = ../../../obj

# C++
SOURCES = hashes_collection.cpp \
		parameter_parser.cpp \
		thread.cpp \
		aligner.cpp \
		alignment_filter.cpp

OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SOURCES) )
LIBS = -lz
INCLUDE = -I../..

# C
CSOURCES = md5.c 

COBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(CSOURCES) )

all: $(OBJECTS) $(COBJECTS)

$(OBJECTS): $(SOURCES)
	@echo "  * compiling" $(*F).cpp
	@$(CXX) -c $(CXXFLAGS) $(*F).cpp $(INCLUDE) -o $@ $(LIBS)

$(COBJECTS): $(CSOURCES)
	@echo "  * compiling" $(*F).c
	@$(CC) -c $(CFLAGS) $(*F).c $(CINCLUDE) -o $@

.PHONY: all

