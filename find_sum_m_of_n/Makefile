TARGET = test_app
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
CC = g++
CLANG = clang++
INCLUDES = 
LIBS = 
CCFLAGS = 
LINKFLAGS = -std=c++11

all:$(TARGET)
$(TARGET): $(OBJS)
	$(CLANG) $^ -o $@ $(INCLUDES) $(LIBS) $(LINKFLAGS)
$(OBJS): $(SRCS)
	$(CLANG) -c $< $(CCFLAGS)

clean:
	rm $(TARGET)
	rm $(OBJS)

.PHONY:all



#$(TARGET): $(OBJS)
	#$(CC) $^ -o $@ $(INCLUDES) $(LIBS)
#$(OBJS): $(SRCS)
	#$(CC) -c $< $(CCFLAGS)
