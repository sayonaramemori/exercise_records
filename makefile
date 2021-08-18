src=$(wildcard src/*.cpp)
obj=$(patsubst %.c, %.o, $(src))

ALL:main

clean:
	-rm -f $(obj)

$(obj):%.o:%.cpp
	g++ $^ -c $@ -Wall

main:$(obj)
	g++ $^ -o $@

.PHONY:ALL clean

