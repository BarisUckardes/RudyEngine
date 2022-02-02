#include "ReflectionRawTypes.h"
#define GENERATE_RAW_TYPE(type) Rudy::ReflectionType* GET_RAW_NAME(type)_reflection_type_acccessor_::s_OwnerType = new Rudy::ReflectionType(#type,sizeof(type));

GENERATE_RAW_TYPE(int);
GENERATE_RAW_TYPE(uint);
GENERATE_RAW_TYPE(float);
GENERATE_RAW_TYPE(short);
GENERATE_RAW_TYPE(ushort);
GENERATE_RAW_TYPE(double);
GENERATE_RAW_TYPE(long);
GENERATE_RAW_TYPE(ulong);
GENERATE_RAW_TYPE(char);
GENERATE_RAW_TYPE(bool);