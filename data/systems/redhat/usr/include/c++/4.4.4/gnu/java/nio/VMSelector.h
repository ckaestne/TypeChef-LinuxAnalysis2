
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_nio_VMSelector__
#define __gnu_java_nio_VMSelector__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace nio
      {
          class VMSelector;
      }
    }
  }
}

class gnu::java::nio::VMSelector : public ::java::lang::Object
{

public:
  VMSelector();
public: // actually package-private
  static jint select(JArray< jint > *, JArray< jint > *, JArray< jint > *, jlong);
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_nio_VMSelector__
