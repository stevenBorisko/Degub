# make <Degub path>/Degub.o a prerequisite for your executable

DEGUB_PATH := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
$(DEGUB_PATH)Degub.o: $(DEGUB_PATH)Degub.c $(DEGUB_PATH)Degub.h
	$(CC) -c $< -o $@ $(CFLAGS)
	@echo "Degub compiled"

DegubClean:
	@echo "Degub cleaned"
