
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_rmi_server_UID__
#define __java_rmi_server_UID__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace rmi
    {
      namespace server
      {
          class UID;
      }
    }
  }
}

class java::rmi::server::UID : public ::java::lang::Object
{

public:
  UID();
  UID(jshort);
  jint hashCode();
  jboolean equals(::java::lang::Object *);
  static ::java::rmi::server::UID * read(::java::io::DataInput *);
  void write(::java::io::DataOutput *);
public: // actually package-private
  static jint getMachineId();
public:
  ::java::lang::String * toString();
private:
  static const jlong serialVersionUID = 1086053664494604050LL;
  static jshort uidCounter;
  static jlong last;
  static jint machineId;
  jshort __attribute__((aligned(__alignof__( ::java::lang::Object)))) count;
  jint unique;
  jlong time;
public:
  static ::java::lang::Class class$;
};

#endif // __java_rmi_server_UID__
