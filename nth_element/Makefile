TARGET = test_app
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
CC = g++
INCLUDES =
#就拿数学库来说，他的库名是m，他的库文件名是libm.so，很容易看出，把库文件名的头lib和尾.so去掉就是库名了
LIBS =
CCFLAGS = 
LDFLAGS = 

all:$(TARGET)
$(TARGET): $(OBJS)
	$(CC) $^ -o $@ $(LIBS) $(LDFLAGS)
$(OBJS): $(SRCS)
	$(CC) -c $< $(CCFLAGS) $(INCLUDES) 

clean:
	rm $(OBJS)
	rm $(TARGET)


.PHONY:all
