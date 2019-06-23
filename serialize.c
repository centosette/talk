/********************************************
serialize.c
********************************************/

#include "serialize.h"
#include <inttypes.h>

enum endian_type _this_host_endian_type()
{
  uint16_t test;
  test = TEST_NUM;
  if (htons(test)==bswap_16(test)) return (_LITTLE_ENDIAN);
  return (_BIG_ENDIAN);
}

serialized_t serialize(void *data, size_t data_len)
{
  void *buffer;
  buffer = (void *)malloc(data_len);
  if (buffer == NULL)
    {
      //The memory allocation failed
    }
  serialized_t serialized_data;
  serialized_data.data = buffer;
  serialized_data.size = data_len;
  serialized_data.data_endian_type = _this_host_endian_type();
  return serialized_data;
}

void * to_byte_stream(serialized_t serialized_data)
{
}
  
