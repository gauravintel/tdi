/*
 * Copyright(c) 2021 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this software except as stipulated in the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/** @file tdi_defs.h
 *
 *  @brief Contains Common data types used in TDI
 */
#ifndef _TDI_DEFS_H
#define _TDI_DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 32-bit ID for all TDI info IDs
 */
typedef uint32_t tdi_id_t;

/**
 * @brief 32-bit ID for table entry handles
 */
typedef uint32_t tdi_handle_t;

/**
 * @brief 32-bit ID for Device ID
 */
typedef uint32_t tdi_dev_id_t;

/**
 * @brief enum of table APIs available
 */
enum tdi_table_api_type_e {
  /** Entry Add. Most common API. Applicable to most tables*/
  TDI_TABLE_API_TYPE_ADD = 0,
  /** Entry Modify. Applicable to most tables*/
  TDI_TABLE_API_TYPE_MODIFY = 1,
  /** Entry Modify incremental. Useful in cases where the data is an
  array and only one element needs to be changed.*/
  TDI_TABLE_API_TYPE_MODIFY_INC = 2,

  /** Entry Delete. Not applicable for some tables like counter,
                  register, meter*/
  TDI_TABLE_API_TYPE_DELETE = 3,
  /** Clear. Only applicable for tables which have DELETE right now*/
  TDI_TABLE_API_TYPE_CLEAR = 4,
  /** Default Entry Set. Only applicable for Match
                              action tables, direct or indirect. If table has
                              const default action, then this would fail*/
  TDI_TABLE_API_TYPE_DEFAULT_ENTRY_SET = 5,
  /** Default Entry Reset. Only applicable for Match
                             action tables, direct or indirect. Idempotent*/
  TDI_TABLE_API_TYPE_DEFAULT_ENTRY_RESET = 6,
  /** Default Entry Get. Only applicable for Match
                            action tables, direct or indirect.*/
  TDI_TABLE_API_TYPE_DEFAULT_ENTRY_GET = 7,
  /** Entry Get. Applicable to most tables.*/
  TDI_TABLE_API_TYPE_GET = 8,
  /** Entry Get First. Applicable to most tables.*/
  TDI_TABLE_API_TYPE_GET_FIRST = 9,
  /** Entry Get Next n entries. Applicable for most tables*/
  TDI_TABLE_API_TYPE_GET_NEXT_N = 10,
  /** Get Usage. get the current usage of the tables. Not applicable
             for some tables like counter, register, meter */
  TDI_TABLE_API_TYPE_USAGE_GET = 11,
  /** Get entry by handle instead of key. */
  TDI_TABLE_API_TYPE_GET_BY_HANDLE = 12,
  /** Get entry key by handle. */
  TDI_TABLE_API_TYPE_KEY_GET = 13,
  /** Get entry handle from key. */
  TDI_TABLE_API_TYPE_HANDLE_GET = 14,
  /** Invalid not supported API. */
  TDI_TABLE_API_TYPE_INVALID_API = 15
};

/**
 * @brief Enum of Data Types each Data field can take. This is NOT
 *    Data field Type
 */
enum tdi_field_data_type_e {
  TDI_FIELD_DATA_TYPE_INT_ARR = 0,
  TDI_FIELD_DATA_TYPE_BOOL_ARR = 1,
  TDI_FIELD_DATA_TYPE_UINT64 = 2,
  TDI_FIELD_DATA_TYPE_BYTE_STREAM = 3,
  TDI_FIELD_DATA_TYPE_FLOAT = 4,
  TDI_FIELD_DATA_TYPE_CONTAINER = 5,
  TDI_FIELD_DATA_TYPE_STRING = 6,
  TDI_FIELD_DATA_TYPE_BOOL = 7,
  TDI_FIELD_DATA_TYPE_STRING_ARR = 8,
  TDI_FIELD_DATA_TYPE_UNKNOWN = 9,
};

/**
* @brief P4 Arch types. If any new p4 arch needs to be
* used not currently known by TDI, then use TDI_ARCH_TYPE_UNKNOWN
*/
enum tdi_arch_type_e {
  TDI_ARCH_TYPE_BEGIN = 0,
  TDI_ARCH_TYPE_PSA,
  TDI_ARCH_TYPE_PNA,
  TDI_ARCH_TYPE_TNA,
  TDI_ARCH_TYPE_UNKNOWN,
};


/**
 * @brief Mgr type. Devices need to
 * define all of the types themselves
 */
typedef enum {
  TDI_MGR_TYPE_BEGIN = 0,
} tdi_mgr_type_e;

/**
* @brief Target top level enum and reservation
*/
enum tdi_target_e {
  TDI_TARGET_CORE = 0,
  TDI_TARGET_ARCH = 0x08,
  TDI_TARGET_DEVICE = 0x80,
};

/**
* @brief Flags top level enum and reservation
*/
enum tdi_flags_e {
  TDI_FLAGS_CORE = 0,
  TDI_FLAGS_ARCH = 0x08,
  TDI_FLAGS_DEVICE = 0x80,
};

/**
* @brief Table type top level enum and reservation.
* Taking larger reservation space than other enums due
* to possibility of high number of table types
*/
enum tdi_table_type_e {
  TDI_TABLE_TYPE_CORE   = 0x0000,
  TDI_TABLE_TYPE_ARCH   = 0x0080,
  TDI_TABLE_TYPE_DEVICE = 0x0800,
};

/**
* @brief Match type top level enum and reservation
*/
enum tdi_match_type_e {
  TDI_MATCH_TYPE_CORE = 0,
  TDI_MATCH_TYPE_ARCH = 0x08,
  TDI_MATCH_TYPE_DEVICE = 0x80,
};

/**
* @brief Attributes top level enum and reservation
*/
enum tdi_attributes_type_e {
  TDI_ATTRIBUTES_TYPE_CORE = 0,
  TDI_ATTRIBUTES_TYPE_ARCH = 0x08,
  TDI_ATTRIBUTES_TYPE_DEVICE = 0x80,
};

/**
* @brief Attribute field enums. Either of
* core, arch or target will define entire list and
* hence doesn't need to be split.
*
*/
enum tdi_attributes_field_type_e {
  TDI_ATTRIBUTES_FIELD_BEGIN = 0,
};
 

/**
* @brief Operations top level enum and reservation
*/
enum tdi_operations_type_e {
  TDI_OPERATIONS_TYPE_CORE = 0,
  TDI_OPERATIONS_TYPE_ARCH = 0x08,
  TDI_OPERATIONS_TYPE_DEVICE = 0x80,
};

/**
* @brief Operations field enums. Either of
* core, arch or target will define entire list and
* hence doesn't need to be split.
*
*/
enum tdi_operations_field_type_e {
  TDI_OPERATIONS_FIELD_BEGIN = 0,
};
 

/** Identifies an error code. */
typedef int tdi_status_t;

#define TDI_STATUS_VALUES                                                    \
  TDI_STATUS_(TDI_SUCCESS, "Success"), TDI_STATUS_(TDI_NOT_READY, "Not ready"), \
      TDI_STATUS_(TDI_NO_SYS_RESOURCES, "No system resources"),               \
      TDI_STATUS_(TDI_INVALID_ARG, "Invalid arguments"),                      \
      TDI_STATUS_(TDI_ALREADY_EXISTS, "Already exists"),                      \
      TDI_STATUS_(TDI_HW_COMM_FAIL, "HW access fails"),                       \
      TDI_STATUS_(TDI_OBJECT_NOT_FOUND, "Object not found"),                  \
      TDI_STATUS_(TDI_MAX_SESSIONS_EXCEEDED, "Max sessions exceeded"),        \
      TDI_STATUS_(TDI_SESSION_NOT_FOUND, "Session not found"),                \
      TDI_STATUS_(TDI_NO_SPACE, "Not enough space"),                          \
      TDI_STATUS_(TDI_EAGAIN,                                                 \
                 "Resource temporarily not available, try again later"),    \
      TDI_STATUS_(TDI_INIT_ERROR, "Initialization error"),                    \
      TDI_STATUS_(TDI_TXN_NOT_SUPPORTED, "Not supported in transaction"),     \
      TDI_STATUS_(TDI_TABLE_LOCKED, "Resource held by another session"),      \
      TDI_STATUS_(TDI_IO, "IO error"),                                        \
      TDI_STATUS_(TDI_UNEXPECTED, "Unexpected error"),                        \
      TDI_STATUS_(TDI_ENTRY_REFERENCES_EXIST,                                 \
                 "Action data entry is being referenced by match entries"), \
      TDI_STATUS_(TDI_NOT_SUPPORTED, "Operation not supported"),              \
      TDI_STATUS_(TDI_HW_UPDATE_FAILED, "Updating hardware failed"),          \
      TDI_STATUS_(TDI_NO_LEARN_CLIENTS, "No learning clients registered"),    \
      TDI_STATUS_(TDI_IDLE_UPDATE_IN_PROGRESS,                                \
                 "Idle time update state already in progress"),             \
      TDI_STATUS_(TDI_DEVICE_LOCKED, "Device locked"),                        \
      TDI_STATUS_(TDI_INTERNAL_ERROR, "Internal error"),                      \
      TDI_STATUS_(TDI_TABLE_NOT_FOUND, "Table not found"),                    \
      TDI_STATUS_(TDI_IN_USE, "In use"),                                      \
      TDI_STATUS_(TDI_NOT_IMPLEMENTED, "Object not implemented")
enum tdi_status_enum {
#define TDI_STATUS_(x, y) x
  TDI_STATUS_VALUES,
  TDI_STS_MAX
#undef TDI_STATUS_
};
static const char *tdi_err_strings[TDI_STS_MAX + 1] = {
#define TDI_STATUS_(x, y) y
    TDI_STATUS_VALUES, "Unknown error"
#undef TDI_STATUS_
};
static inline const char *tdi_err_str(tdi_status_t sts) {
  if (TDI_STS_MAX <= sts || 0 > sts) {
    return tdi_err_strings[TDI_STS_MAX];
  } else {
    return tdi_err_strings[sts];
  }
}


/**
 * @brief Small helper macro and struct for typedef.
 * For sake of strict typechecking, instead of typedef-ing
 * \n void to our handles, we make a small struct with one element.
 */
#define DECLARE_HANDLE(name) \
  struct name##__ {          \
    int unused;              \
  };                         \
  typedef struct name##__ name


// C frontend typedefs
DECLARE_HANDLE(tdi_info_hdl);
DECLARE_HANDLE(tdi_session_hdl);
DECLARE_HANDLE(tdi_table_hdl);
DECLARE_HANDLE(tdi_table_key_hdl);
DECLARE_HANDLE(tdi_table_data_hdl);
DECLARE_HANDLE(tdi_table_attributes_hdl);
DECLARE_HANDLE(tdi_entry_scope_arguments_hdl);
DECLARE_HANDLE(tdi_learn_hdl);
DECLARE_HANDLE(tdi_table_operations_hdl);

/**
 * @brief learn_data_hdl and table_data_hdl are the same,
 *  \n hence simple typedef like TdiLearnData in
 *  \n include/tdi_learn.hpp
 */
typedef tdi_table_data_hdl tdi_learn_data_hdl;

/* C and C++ void typedefs */
DECLARE_HANDLE(tdi_learn_msg_hdl);

#ifdef __cplusplus
}
#endif

#endif