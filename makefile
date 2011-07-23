################################################################################
# Makefile for myhello.wt
################################################################################

#-------------------------------------------------------------------------------
# NOTE: Make sure that you have the following environment variables set in order
# to compile and run this project
#
# LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/usr/lib:/usr/local/lib"
# LIBRARY_PATH="$LIBRARY_PATH:/usr/lib:/usr/local/lib"
#
#-------------------------------------------------------------------------------

# Path to standard Wt resources
WT_RESOURCES = /usr/local/shared/wt/resources

# Include directories
INCLUDE_DIRS =	-I/usr/include \
				-I/usr/local/include \
				-Iinclude

# Library directories
LIB_DIRS =	-L/usr/lib \
			-L/usr/local/lib

# Libraries to link to
LINK_LIBS = -lwt \
			-lwthttp

# The compiler
COMPILER = g++

# Compiler flags
CFLAGS = -Wall

# The executable
EXEC = myhello.wt

# The object files needed
OBJS =	myhello.o \
		HelloApplication.o


################################################################################
# Build the executable from the object files
################################################################################

# Build the executable
$(EXEC) : $(OBJS)
	@echo Building the executable
	@$(COMPILER) $(CFLAGS) \
	$(OBJS) \
	$(INCLUDE_DIRS) $(LIB_DIRS) $(LINK_LIBS) \
	-o $(EXEC)
	@-ln -s $(WT_RESOURCES) .

# Build the main object file
myhello.o : myhello.cpp
	@echo Building myhello.o
	@$(COMPILER) $(CFLAGS) \
	$(INCLUDE_DIRS) $(LIB_DIRS) $(LINK_LIBS) \
	-c myhello.cpp

# Build HelloApplication object
HelloApplication.o : src/HelloApplication.cpp
	@echo Building HelloApplication.o
	@$(COMPILER) $(CFLAGS) \
	$(INCLUDE_DIRS) $(LIB_DIRS) $(LINK_LIBS) \
	-c src/HelloApplication.cpp


################################################################################
# Clean up the build dependencies
################################################################################
clean:
	@echo Removing the object files
	@rm -f $(OBJS)

