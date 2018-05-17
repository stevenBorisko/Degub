# make <Degub path>/Degub.o a prerequisite for your executable

# --- Definitions ---

DEGUB_PATH := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

# --- Rules ---

# Main object
$(DEGUB_PATH)Degub.o: $(DEGUB_PATH)Degub.c $(DEGUB_PATH)Degub.h
	$(CC) -c $< -o $@ $(CFLAGS)

# Clean
DegubClean:
	rm -f $(DEGUB_PATH)*.o
