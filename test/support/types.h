#ifndef STDINT_H
#define STDINT_H
   #ifndef TEST
      typedef   signed char     int8_t;
      typedef   signed short    int16_t;
      typedef   signed long     int32_t;

      /*!< Unsigned integer types  */
      typedef unsigned char     uint8_t;
      typedef unsigned short    uint16_t;
      typedef unsigned long     uint32_t;
   #else
      #include <stdint.h>
   #endif
#endif
