
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_lang_annotation_ElementType__
#define __java_lang_annotation_ElementType__

#pragma interface

#include <java/lang/Enum.h>
#include <gcj/array.h>


class java::lang::annotation::ElementType : public ::java::lang::Enum
{

  ElementType(::java::lang::String *, jint);
public:
  static JArray< ::java::lang::annotation::ElementType * > * values();
  static ::java::lang::annotation::ElementType * valueOf(::java::lang::String *);
  static ::java::lang::annotation::ElementType * ANNOTATION_TYPE;
  static ::java::lang::annotation::ElementType * CONSTRUCTOR;
  static ::java::lang::annotation::ElementType * FIELD;
  static ::java::lang::annotation::ElementType * LOCAL_VARIABLE;
  static ::java::lang::annotation::ElementType * METHOD;
  static ::java::lang::annotation::ElementType * PACKAGE;
  static ::java::lang::annotation::ElementType * PARAMETER;
  static ::java::lang::annotation::ElementType * TYPE;
private:
  static const jlong serialVersionUID = 2798216111136361587LL;
  static JArray< ::java::lang::annotation::ElementType * > * ENUM$VALUES;
public:
  static ::java::lang::Class class$;
};

#endif // __java_lang_annotation_ElementType__
