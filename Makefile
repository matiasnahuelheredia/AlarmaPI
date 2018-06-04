CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11

OBJS =		src/Alarma.o


LIBS = -lpthread -ltins 

TARGET =	build/Alarma

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)


all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
