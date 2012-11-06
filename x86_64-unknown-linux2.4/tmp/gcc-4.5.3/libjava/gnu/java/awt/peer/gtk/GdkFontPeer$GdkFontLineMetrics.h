
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_peer_gtk_GdkFontPeer$GdkFontLineMetrics__
#define __gnu_java_awt_peer_gtk_GdkFontPeer$GdkFontLineMetrics__

#pragma interface

#include <java/awt/font/LineMetrics.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace awt
      {
        namespace peer
        {
          namespace gtk
          {
              class GdkFontPeer;
              class GdkFontPeer$GdkFontLineMetrics;
          }
        }
      }
    }
  }
}

class gnu::java::awt::peer::gtk::GdkFontPeer$GdkFontLineMetrics : public ::java::awt::font::LineMetrics
{

public:
  GdkFontPeer$GdkFontLineMetrics(::gnu::java::awt::peer::gtk::GdkFontPeer *, ::gnu::java::awt::peer::gtk::GdkFontPeer *, jint);
  virtual jfloat getAscent();
  virtual jint getBaselineIndex();
  virtual JArray< jfloat > * getBaselineOffsets();
  virtual jfloat getDescent();
  virtual jfloat getHeight();
  virtual jfloat getLeading();
  virtual jint getNumChars();
  virtual jfloat getStrikethroughOffset();
  virtual jfloat getStrikethroughThickness();
  virtual jfloat getUnderlineOffset();
  virtual jfloat getUnderlineThickness();
private:
  jint __attribute__((aligned(__alignof__( ::java::awt::font::LineMetrics)))) nchars;
public: // actually package-private
  ::gnu::java::awt::peer::gtk::GdkFontPeer * this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_peer_gtk_GdkFontPeer$GdkFontLineMetrics__
