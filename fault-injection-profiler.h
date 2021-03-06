/*
 * fault-injection-profiler.h
 * 
 *  FIESer by Christian M. Fuchs 2017/2018
 * 
 *  Created on: 18.12.2015
 *      Author: Andrea Hoeller
 * 
 * License: GNU GPL, version 2 or later.
 *   See the COPYING file in the top-level directory.
 */

#ifndef FAULT_INJECTION_PROFILER_H_
#define FAULT_INJECTION_PROFILER_H_

#include "qemu/osdep.h"
#include "qemu-common.h"
#include "qemu/config-file.h"
#include "cpu.h"

#include "fault-injection-infrastructure.h"
#include "fault-injection-controller.h"

#define OUTPUT_FILE_NAME_ACCESSED_MEMORY_ADDRESSES "profiling_memory.txt"
#define OUTPUT_FILE_NAME_ACCESSED_REGS "profiling_registers.txt"
#define OUTPUT_FILE_NAME_CONDITION_FLAGS "condition_flags.txt"
#define OUTPUT_FILE_NAME_DEBUGLOG "debug_log.txt"

extern unsigned int profile_ram_addresses;
extern unsigned int profile_pc_status;
extern unsigned int profile_registers;
extern unsigned int profile_condition_flags;


void profiler_log_memory_access(CPUArchState *env, hwaddr *addr, uint32_t *value, AccessType access_type);
void profiler_close_files(void);
void set_profile_ram_addresses(int flag);
void profiler_log(CPUArchState *env, hwaddr *addr, uint32_t *value, AccessType access_type);
void profiler_log_register_access(CPUArchState *env, hwaddr *addr, uint32_t *value, AccessType access_type);
void profiler_debuglog(const char* msg, ...);

#endif /* FAULT_INJECTION_PROFILER_H_ */
