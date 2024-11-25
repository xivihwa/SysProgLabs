# Компілятор і опції
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Iinclude

# Шляхи
SRC_DIR = src
INC_DIR = include
LIB_DIR = lib
BUILD_DIR = build

# Назви файлів
STATIC_LIB = $(LIB_DIR)/libemployee.a
EXECUTABLE = program

# Файли
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
HEADERS = $(wildcard $(INC_DIR)/*.h)

# Цільова програма
all: $(EXECUTABLE)

# Збірка виконавчого файлу
$(EXECUTABLE): $(STATIC_LIB) main.o
	$(CXX) $(CXXFLAGS) -o $@ main.o $(STATIC_LIB)

# Компіляція main.cpp
main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@

# Створення статичної бібліотеки
$(STATIC_LIB): $(OBJECTS)
	ar rcs $@ $^

# Компіляція .cpp у .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очищення
clean:
	rm -rf $(BUILD_DIR) *.o $(EXECUTABLE) $(STATIC_LIB)
