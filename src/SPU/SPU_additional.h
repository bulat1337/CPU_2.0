#ifndef SPU_ADDITIONAL
#define SPU_ADDITIONAL

/**
 * @file SPU_additional.h
 * @brief Additional functions for the SPU program.
 */

#include "SPU.h"

#define FREAD(buf, elem_size, amount, file_ptr)\
	size_t read_elems = fread(buf, elem_size, amount, file_ptr);	\
	if(read_elems != amount)										\
	{																\
		CPU_LOG("ERROR: fread read unexpected amount of elems.\n");	\
		CPU_LOG("\t expected amount: %lu.\n", amount);				\
		CPU_LOG("\t read amount: %lu.\n", read_elems);				\
																	\
		return SPU_INVALID_FREAD;									\
	}

const size_t STD_USER_STACK_SIZE = 10;
const size_t STD_RET_STACK_SIZE  = 2;

/**
 * @brief Processes the input file and performs operations based on the byte code.
 * @param input_file Pointer to the input file.
 * @param output_file Pointer to the output file.
 * @return Returns SPU_ALL_GOOD if successful, otherwise returns an error code.
 */
error_t process(FILE *input_file, FILE *output_file);

/**
 * @brief Constructor for the Virtual Machine.
 * @param vm Pointer to the Virtual Machine structure.
 * @return Returns SPU_ALL_GOOD if successful, otherwise returns an error code.
 */
error_t VM_ctor(struct VM *vm);

/**
 * @brief Destructor for the Virtual Machine.
 * @param vm Pointer to the Virtual Machine structure.
 * @return Returns SPU_ALL_GOOD if successful, otherwise returns an error code.
 */
error_t VM_dtor(struct VM *vm);

#endif
