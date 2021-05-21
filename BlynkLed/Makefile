#Makefile for STM32F407VG

PROJ_DIR 	= E:/Make/BlynkLed
PROJ_NAME	= BLYNKLED
OUTPUT_PATH	:= $(PROJ_DIR)/out

########################### SRC, ASM, INC, LINKER Direction ##################################################

SRC_DIR	= $(PROJ_DIR)/src
# SRC_DIR	+= $(PROJ_DIR)/lib/STM32F4xx_HAL_Driver/Src

ASM_DIR = $(PROJ_DIR)/startup

INC_DIR	= $(PROJ_DIR)/inc
# INC_DIR	+= $(PROJ_DIR)/lib/STM32F4xx_HAL_Driver/Inc
# INC_DIR	+= $(PROJ_DIR)/lib/CMSIS/Device/ST/STM32F4xx/Include
# INC_DIR	+= $(PROJ_DIR)/lib/CMSIS/Include

LINKER_FILE	:= $(PROJ_DIR)/linker/stm32f40xx.ld
####################### Get all file in folders: main.c, gpio.c, gpio.h,... #############################

SRC_FILES	:= $(foreach SRC_DIR,$(SRC_DIR),$(wildcard $(SRC_DIR)/*))
INC_FILES 	:= $(foreach INC_DIR,$(INC_DIR),$(wildcard $(INC_DIR)/*))

####################### Get all file name .c: main.c, gpio.c... and convert .c => .o ##############

OBJ_FILES	:= $(notdir $(SRC_FILES))	
OBJ_FILES	:= $(subst .c,.o,$(OBJ_FILES))

####################### Get out out/main.o , out/gpio.o ... ########################################

PATH_OBJS := $(foreach O_FILES,$(O_FILES),$(OUTPUT_PATH)/$(O_FILES)) 

####################### Direction to tool ######################################################

COMPILER_DIRS	:= C:/GCC_ARM
CC				:= $(COMPILER_DIRS)/bin/arm-none-eabi-gcc
ASM				:= $(COMPILER_DIRS)/bin/arm-none-eabi-as
LD				:= $(COMPILER_DIRS)/bin/arm-none-eabi-ld 

####################### Option to build #######################################################
FILE_TO_LINK	:= $(OUTPUT_PATH)/main.o $(OUTPUT_PATH)/startup_stm32f40xx.o

CC_OPT			:= -mcpu=cortex-m4 -c -O0 -g -mthumb -I$(INC_DIR)
ASM_OPT			:= -mcpu=cortex-m4 -c -mthumb
LD_OPT			:= -T $(LINKER_FILE) -Map $(OUTPUT_PATH)/$(PROJ_NAME).map $(FILE_TO_LINK)

########################## Vpath .c and .h file##########################################################

vpath %.c $(SRC_DIR)
vpath %.h $(INC_DIR)

#########################################################################################################

$(OUTPUT_PATH)/startup_stm32f40xx.o: $(ASM_DIR)/startup_stm32f40xx.s
	@echo "---LOG: compile $(ASM_DIR)/startup_stm32f40xx.s file"
	$(ASM) $(ASM_OPT) $(ASM_DIR)/startup_stm32f40xx.s -o $(OUTPUT_PATH)/startup_stm32f40xx.o
	
build: $(OUTPUT_PATH)/startup_stm32f40xx.o $(OBJ_FILES) $(LINKER_FILE)
	@echo "---LOG: BUILD elf, hex"
	$(LD) $(LD_OPT) $(PATH_OBJS) -o $(OUTPUT_PATH)/$(PROJ_NAME).elf
	$(COMPILER_DIRS)/arm-none-eabi/bin/objcopy.exe -O ihex "$(OUTPUT_PATH)/$(PROJ_NAME).elf" "$(OUTPUT_PATH)/$(PROJ_NAME).hex"
	
%.o: %.c $(INC_FILES)
	@echo "---LOG: .c => .o file"
	#$(CC) $(CC_OPT) $(SRC_DIR)/main.c -o $(OUTPUT_PATH)/main.o
	$(CC) $(CC_OPT) -c $< -o $(OUTPUT_PATH)/main.o

	
.PHONY: clean
clean:
	rm out/*