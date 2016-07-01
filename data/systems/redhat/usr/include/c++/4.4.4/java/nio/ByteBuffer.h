
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_nio_ByteBuffer__
#define __java_nio_ByteBuffer__

#pragma interface

#include <java/nio/Buffer.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace gcj
    {
        class RawData;
    }
  }
  namespace java
  {
    namespace nio
    {
        class ByteBuffer;
        class ByteOrder;
        class CharBuffer;
        class DoubleBuffer;
        class FloatBuffer;
        class IntBuffer;
        class LongBuffer;
        class ShortBuffer;
    }
  }
}

class java::nio::ByteBuffer : public ::java::nio::Buffer
{

public: // actually package-private
  ByteBuffer(jint, jint, jint, jint, ::gnu::gcj::RawData *, JArray< jbyte > *, jint);
public:
  static ::java::nio::ByteBuffer * allocateDirect(jint);
  static ::java::nio::ByteBuffer * allocate(jint);
  static ::java::nio::ByteBuffer * wrap(JArray< jbyte > *, jint, jint);
  static ::java::nio::ByteBuffer * wrap(JArray< jbyte > *);
  virtual ::java::nio::ByteBuffer * get(JArray< jbyte > *, jint, jint);
  virtual ::java::nio::ByteBuffer * get(JArray< jbyte > *);
  virtual ::java::nio::ByteBuffer * put(::java::nio::ByteBuffer *);
  virtual ::java::nio::ByteBuffer * put(JArray< jbyte > *, jint, jint);
  virtual ::java::nio::ByteBuffer * put(JArray< jbyte > *);
  virtual jboolean hasArray();
  virtual JArray< jbyte > * array();
  virtual jint arrayOffset();
  virtual jint hashCode();
  virtual jboolean equals(::java::lang::Object *);
  virtual jint ByteBuffer$compareTo(::java::nio::ByteBuffer *);
  virtual ::java::nio::ByteOrder * order();
  virtual ::java::nio::ByteBuffer * order(::java::nio::ByteOrder *);
  virtual jbyte get() = 0;
  virtual ::java::nio::ByteBuffer * put(jbyte) = 0;
  virtual jbyte get(jint) = 0;
  virtual ::java::nio::ByteBuffer * put(jint, jbyte) = 0;
  virtual ::java::nio::ByteBuffer * compact() = 0;
public: // actually package-private
  virtual void shiftDown(jint, jint, jint);
public:
  virtual jboolean isDirect() = 0;
  virtual ::java::nio::ByteBuffer * slice() = 0;
  virtual ::java::nio::ByteBuffer * duplicate() = 0;
  virtual ::java::nio::ByteBuffer * asReadOnlyBuffer() = 0;
  virtual ::java::nio::ShortBuffer * asShortBuffer() = 0;
  virtual ::java::nio::CharBuffer * asCharBuffer() = 0;
  virtual ::java::nio::IntBuffer * asIntBuffer() = 0;
  virtual ::java::nio::LongBuffer * asLongBuffer() = 0;
  virtual ::java::nio::FloatBuffer * asFloatBuffer() = 0;
  virtual ::java::nio::DoubleBuffer * asDoubleBuffer() = 0;
  virtual jchar getChar() = 0;
  virtual ::java::nio::ByteBuffer * putChar(jchar) = 0;
  virtual jchar getChar(jint) = 0;
  virtual ::java::nio::ByteBuffer * putChar(jint, jchar) = 0;
  virtual jshort getShort() = 0;
  virtual ::java::nio::ByteBuffer * putShort(jshort) = 0;
  virtual jshort getShort(jint) = 0;
  virtual ::java::nio::ByteBuffer * putShort(jint, jshort) = 0;
  virtual jint getInt() = 0;
  virtual ::java::nio::ByteBuffer * putInt(jint) = 0;
  virtual jint getInt(jint) = 0;
  virtual ::java::nio::ByteBuffer * putInt(jint, jint) = 0;
  virtual jlong getLong() = 0;
  virtual ::java::nio::ByteBuffer * putLong(jlong) = 0;
  virtual jlong getLong(jint) = 0;
  virtual ::java::nio::ByteBuffer * putLong(jint, jlong) = 0;
  virtual jfloat getFloat() = 0;
  virtual ::java::nio::ByteBuffer * putFloat(jfloat) = 0;
  virtual jfloat getFloat(jint) = 0;
  virtual ::java::nio::ByteBuffer * putFloat(jint, jfloat) = 0;
  virtual jdouble getDouble() = 0;
  virtual ::java::nio::ByteBuffer * putDouble(jdouble) = 0;
  virtual jdouble getDouble(jint) = 0;
  virtual ::java::nio::ByteBuffer * putDouble(jint, jdouble) = 0;
  virtual ::java::lang::String * toString();
  virtual jint compareTo(::java::lang::Object *);
public: // actually package-private
  ::java::nio::ByteOrder * __attribute__((aligned(__alignof__( ::java::nio::Buffer)))) endian;
  JArray< jbyte > * backing_buffer;
  jint array_offset;
public:
  static ::java::lang::Class class$;
};

#endif // __java_nio_ByteBuffer__
