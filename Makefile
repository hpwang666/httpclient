INCLUDES = 	-I ./
		
##### Change the following for your environment: 
CROSS_COMPILE =
C_COMPILER = $(CROSS_COMPILE)gcc -c 
C_FLAGS =  $(INCLUDES) -Wall -O2 


CPLUSPLUS_COMPILER =	$(CROSS_COMPILE)g++ -c
CPLUSPLUS_FLAGS =	$(COMPILE_OPTS) 

LINK =			$(CROSS_COMPILE)gcc 
LINK_OPTS +=		-lpthread 



##### End of variables to change

TARGET = http_client

ALL = $(TARGET)
all: $(ALL)

SOURCES =  $(wildcard *.c) 
HEADERS = $(wildcard *.h)  

#change .cpp files  to .o files
OBJFILES = $(SOURCES:%.c=%.o)

$(OBJFILES):	%.o:%.c   $(HEADERS) 
	@echo CC $<
	@$(C_COMPILER)  $(C_FLAGS) -o $@ $<





$(TARGET):	$(OBJFILES) 
	@echo " linking $(TARGET) from $(OBJFILES) "
	@$(LINK)  -o $@ $^  $(LINK_OPTS)
###注意编译和连接时的OPTS的位置不一样	
prepare:
	@echo "preparing..."

clean:
	-rm -rf *.o $(ALL) *~ 
install:
	install $(TARGET) $(INSTALL_DIR)

##### Any additional, platform-specific rules come here:
