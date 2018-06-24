CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11 -Wunused-variable

OBJS =		src/Alarma.o src/I2cDisplay.o


LIBS = -lpthread -ltins -lcppgpio

TARGET =	build/Alarma

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)


all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
