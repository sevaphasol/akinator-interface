CC = g++
CFLAGS = -g -I include -I stack/include -Wcast-qual -Wconversion -Wctor-dtor-privacy \
		 -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op \
         -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual     \
		 -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing           \
		 -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -fexceptions -pipe     \

LDFLAGS = -lmenu -lpanel -lncursesw

SOURCES_DIR     = src
OBJECTS_DIR     = bin
BUILD_DIR       = build

EXECUTABLE 	    = interface
EXECUTABLE_PATH = $(BUILD_DIR)/$(EXECUTABLE)

SOURCE_FILES = $(wildcard $(SOURCES_DIR)/*.cpp)
OBJECT_FILES = $(subst $(SOURCES_DIR), $(OBJECTS_DIR), $(SOURCE_FILES:.cpp=.o))

all: $(EXECUTABLE_PATH)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJECTS_DIR):
	mkdir -p $(OBJECTS_DIR)

$(EXECUTABLE_PATH): $(OBJECT_FILES) $(BUILD_DIR)
	$(CC) $(OBJECT_FILES) -o $@ $(LDFLAGS)

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp $(OBJECTS_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -fr $(OBJECTS_DIR) $(BUILD_DIR) $(LOGS_DIR)