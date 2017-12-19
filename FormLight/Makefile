TARGET := FormLight

# Define directory
BINDIR := ../bin
OBJDIR := ../obj

# Define compiler and flags
CC := g++
CFLAGS_DEBUG := -std=c++14 -g -Wall -Wno-unknown-pragmas -Wno-unused-result -Wno-write-strings -Wno-invalid-offsetof -Wno-strict-aliasing -Wno-format-security -Wno-overflow -pthread
CFLAGS := -std=c++14 -O3 -Wall -Wno-unknown-pragmas -Wno-unused-result -Wno-write-strings -Wno-invalid-offsetof -Wno-strict-aliasing -Wno-format-security -Wno-overflow -pthread

# Define libraries and includes
LIBS := -lsqlite3 -lfreeimage -lGL -lGLU -lglut -lX11
INCFLAGS := -I/.

# List of source files
#FILES = main.cpp controls.cpp GLPainter.cpp GLFont.cpp GLShader.cpp GLTexture.cpp linux.cpp File.cpp VectorMatrix.cpp Image.cpp OpenGL.cpp GLX.cpp
OBJECTS = main.o controls.o GLPainter.o GLFont.o GLShader.o GLTexture.o linux.o File.o VectorMatrix.o Image.o OpenGL.o GLX.o

# Targets
.PHONY: all clean $(TARGET) test

all: $(TARGET)

$(OBJDIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS_DEBUG) $(INCFLAGS) $< -o $@

$(TARGET): $(addprefix $(OBJDIR)/, $(OBJECTS))
	$(CC) $(CFLAGS_DEBUG) $(INCFLAGS) $(addprefix $(OBJDIR)/, $(OBJECTS)) $(LIBS) -o $(BINDIR)/$(TARGET)

clean:
	rm $(addprefix $(OBJDIR)/, $(OBJECTS)) $(BINDIR)/$(TARGET)

#$(TARGET):
#	$(CC) $(CFLAGS_DEBUG) $(INCFLAGS) -o $@ $(FILES) $(LIBS) -o $(BIN)$(TARGET)