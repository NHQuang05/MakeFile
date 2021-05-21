
PROJ_DIR 	= E:/Make/BlynkLed
PROJ_NAME	= BLYNKLED
OUTPUT_PATH	:= $(PROJ_DIR)/out

SRC_DIR	:= $(PROJ_DIR)/src
ASM_DIR := $(PROJ_DIR)/startup
INC_DIR	:= $(PROJ_DIR)/inc

LINKER_FILE	:= $(PROJ_DIR)/linker/stm32f40xx.ld

COMPILER_DIRS	:= C:/GCC_ARM
CC				:= $(COMPILER_DIRS)/bin/arm-none-eabi-gcc
ASM				:= $(COMPILER_DIRS)/bin/arm-none-eabi-as
LD				:= $(COMPILER_DIRS)/bin/arm-none-eabi-ld 

FILE_TO_LINK	:= $(OUTPUT_PATH)/main.o $(OUTPUT_PATH)/startup_stm32f40xx.o

CC_OPT			:= -mcpu=cortex-m4 -c -O0 -g -mthumb -I$(INC_DIR)
ASM_OPT			:= -mcpu=cortex-m4 -c -mthumb
LD_OPT			:= -T $(LINKER_FILE) -Map $(OUTPUT_PATH)/$(PROJ_NAME).map $(FILE_TO_LINK)

$(OUTPUT_PATH)/main.o: $(SRC_DIR)/main.c $(INC_DIR)
	@echo "---LOG: compile $(SRC_DIR)/main.c file"
	$(CC) $(CC_OPT) $(SRC_DIR)/main.c -o $(OUTPUT_PATH)/main.o
	
$(OUTPUT_PATH)/startup_stm32f40xx.o: $(ASM_DIR)/startup_stm32f40xx.s
	@echo "---LOG: compile $(ASM_DIR)/startup_stm32f40xx.s file"
	$(ASM) $(ASM_OPT) $(ASM_DIR)/startup_stm32f40xx.s -o $(OUTPUT_PATH)/startup_stm32f40xx.o
	
build: $(FILE_TO_LINK) $(LINKER_FILE)
	@echo "---LOG: create($(PROJ_NAME).elf)"
	$(LD) $(LD_OPT) -o $(OUTPUT_PATH)/$(PROJ_NAME).elf
	$(COMPILER_DIRS)/arm-none-eabi/bin/objcopy.exe -O ihex "$(OUTPUT_PATH)/$(PROJ_NAME).elf" "$(OUTPUT_PATH)/$(PROJ_NAME).hex"
	
.PHONY: clean
clean:
	rm out/*