################################### METADATA ###################################

# Contributors: roadelou
# Contacts: 
# Creation Date: 2021-03-06
# Language: Makefile

################################### ALIASES ####################################

SRC = $(wildcard $(CURDIR)/src/*.c)
HEAD = $(wildcard $(CURDIR)/include/*.h)

BUILD_DIR = $(CURDIR)/build
EXEC = $(BUILD_DIR)/abro.elf

################################### SPECIAL ####################################

.PHONY: clean all

#################################### RULES #####################################

all: $(EXEC)

clean:
	rm -f $(EXEC)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(EXEC): $(SRC) $(HEAD) $(BUILD_DIR)
	$(CC) $(SRC) -Wall -pedantic -I $(CURDIR)/include -o $(EXEC)

##################################### EOF ######################################
