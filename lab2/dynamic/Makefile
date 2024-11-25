# Компілятор і опції
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Iinclude -fPIC

# Шляхи
SRC_DIR = src
INC_DIR = include
LIB_DIR = lib
BUILD_DIR = build

# Назви файлів
DYNAMIC_LIB = $(LIB_DIR)/libemployee.so
EXECUTABLE = program

# Файли
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
HEADERS = $(wildcard $(INC_DIR)/*.h)

# Цільова програма
all: $(EXECUTABLE)

# Збірка виконавчого файлу
$(EXECUTABLE): $(DYNAMIC_LIB) main.o
	$(CXX) $(CXXFLAGS) -o $@ main.o -L$(LIB_DIR) -Wl,-rpath,$(LIB_DIR) -lemployee

# Компіляція main.cpp
main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@

# Створення динамічної бібліотеки
$(DYNAMIC_LIB): $(OBJECTS)
	mkdir -p $(LIB_DIR)
	$(CXX) -shared -o $@ $^

# Компіляція .cpp у .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очищення
clean:
	rm -rf $(BUILD_DIR) *.o $(EXECUTABLE) $(DYNAMIC_LIB)
