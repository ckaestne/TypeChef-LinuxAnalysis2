
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_net_ssl_provider_ExtensionList__
#define __gnu_javax_net_ssl_provider_ExtensionList__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace net
      {
        namespace ssl
        {
          namespace provider
          {
              class Extension;
              class Extension$Type;
              class ExtensionList;
          }
        }
      }
    }
  }
  namespace java
  {
    namespace nio
    {
        class ByteBuffer;
    }
  }
}

class gnu::javax::net::ssl::provider::ExtensionList : public ::java::lang::Object
{

public:
  ExtensionList(::java::nio::ByteBuffer *);
  ExtensionList(::java::util::List *);
  virtual ::java::nio::ByteBuffer * buffer();
  virtual ::gnu::javax::net::ssl::provider::Extension * get(jint);
  virtual jint size();
  virtual jint length();
  virtual void set(jint, ::gnu::javax::net::ssl::provider::Extension *);
  virtual void set(jint, ::gnu::javax::net::ssl::provider::Extension$Type *, jint);
  virtual void setLength(jint);
  virtual ::java::util::Iterator * iterator();
  virtual ::java::lang::String * toString();
  virtual ::java::lang::String * toString(::java::lang::String *);
public: // actually package-private
  static jint access$0(::gnu::javax::net::ssl::provider::ExtensionList *);
private:
  ::java::nio::ByteBuffer * __attribute__((aligned(__alignof__( ::java::lang::Object)))) buffer__;
  jint modCount;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_net_ssl_provider_ExtensionList__