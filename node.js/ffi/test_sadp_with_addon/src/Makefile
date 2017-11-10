CC = g++
VS_ROOT  = .
SRCS  = $(wildcard $(VS_ROOT)/*.cpp)
OBJS := $(SRCS:%.cpp=%.o)
INCLUDE = -I../include
SHARED = -shared -o
LDLIBS = -lsadp
LIBPATH = ../lib
BINPATH = ../
RUNPATH = ./


# If no configuration is specified, "Debug" will be used
ifndef CFG
CFG=Debug
endif

ifeq "$(CFG)" "Debug"
LIBFILE = libinquire.so
OUTFILE = inquire
CFLAGS = -g -o0 -Wall
else
LIBFILE = libinquire.so
OUTFILE = inquire
CFLAGS = -o0 -Wall  
endif

COMPILE = $(CC) $(CFLAGS) $(INCLUDE) -c "$<" -o "$@" 
LINK = $(CC) $(CFLAGS) $(OBJS) -o $(OUTFILE) -L$(LIBPATH) $(LDLIBS) -Wl,-rpath=$(RUNPATH)

all:$(OUTFILE) $(LIBFILE)
	@echo "Build sadp_demo Finished"
	mv $(OUTFILE) $(BINPATH)
	mv $(LIBFILE) $(LIBPATH)

$(LIBFILE):$(OBJS)
	$(CC) $(OBJS) $(SHARED) -fpic -o $(LIBFILE)

$(OUTFILE):$(OBJS)
	$(LINK)

%.o:%.cpp
	$(COMPILE)



clean:
	rm -f $(OBJS)
	rm -f $(LIBPATH)$(OUTFILE)
	
	
