/**************************************************************

serialize.h

serialization utilities
***************************************************************/
#include <arpa/inet.h>
#include <byteswap.h>
#include <malloc.h>

//packet layout
#define ENDIAN_TYPE_FLD 1
#define DATA_LEN_FLD 8
#define CTRL_DATA_LEN_FLD 8

//use this number to test whether the machine is little or big endian
#define TEST_NUM 1

enum endian_type {
	   _BIG_ENDIAN,
	   _LITTLE_ENDIAN
};

typedef struct {
  size_t size; //size of the data segment
  void *data;
  enum endian_type data_endian_type;
} serialized_t;

enum endian_type _this_host_endian_type(void);

//create serialized_t data structure from data, given data length
serialized_t serialize(void *data, size_t data_len);

//get an actual byte stream (a packet) from the serialized_t object
void * to_byte_stream(serialized_t serialized_data);


