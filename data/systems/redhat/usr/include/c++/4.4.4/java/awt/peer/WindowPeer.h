
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_peer_WindowPeer__
#define __java_awt_peer_WindowPeer__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class AWTEvent;
        class BufferCapabilities;
        class BufferCapabilities$FlipContents;
        class Color;
        class Component;
        class Cursor;
        class Dialog;
        class Dimension;
        class Font;
        class FontMetrics;
        class Graphics;
        class GraphicsConfiguration;
        class Image;
        class Insets;
        class Point;
        class Rectangle;
        class Toolkit;
      namespace event
      {
          class PaintEvent;
      }
      namespace image
      {
          class ColorModel;
          class ImageObserver;
          class ImageProducer;
          class VolatileImage;
      }
      namespace peer
      {
          class ContainerPeer;
          class WindowPeer;
      }
    }
  }
  namespace sun
  {
    namespace awt
    {
        class CausedFocusEvent$Cause;
    }
  }
}

class java::awt::peer::WindowPeer : public ::java::lang::Object
{

public:
  virtual void toBack() = 0;
  virtual void toFront() = 0;
  virtual void updateAlwaysOnTop() = 0;
  virtual jboolean requestWindowFocus() = 0;
  virtual void setAlwaysOnTop(jboolean) = 0;
  virtual void updateFocusableWindowState() = 0;
  virtual void setModalBlocked(::java::awt::Dialog *, jboolean) = 0;
  virtual void updateMinimumSize() = 0;
  virtual void updateIconImages() = 0;
  virtual ::java::awt::Insets * insets() = 0;
  virtual ::java::awt::Insets * getInsets() = 0;
  virtual void beginValidate() = 0;
  virtual void endValidate() = 0;
  virtual void beginLayout() = 0;
  virtual void endLayout() = 0;
  virtual jboolean isPaintPending() = 0;
  virtual jboolean isRestackSupported() = 0;
  virtual void cancelPendingPaint(jint, jint, jint, jint) = 0;
  virtual void restack() = 0;
  virtual jint checkImage(::java::awt::Image *, jint, jint, ::java::awt::image::ImageObserver *) = 0;
  virtual ::java::awt::Image * createImage(::java::awt::image::ImageProducer *) = 0;
  virtual ::java::awt::Image * createImage(jint, jint) = 0;
  virtual void disable() = 0;
  virtual void dispose() = 0;
  virtual void enable() = 0;
  virtual ::java::awt::image::ColorModel * getColorModel() = 0;
  virtual ::java::awt::FontMetrics * getFontMetrics(::java::awt::Font *) = 0;
  virtual ::java::awt::Graphics * getGraphics() = 0;
  virtual ::java::awt::Point * getLocationOnScreen() = 0;
  virtual ::java::awt::Dimension * getMinimumSize() = 0;
  virtual ::java::awt::Dimension * getPreferredSize() = 0;
  virtual ::java::awt::Toolkit * getToolkit() = 0;
  virtual void handleEvent(::java::awt::AWTEvent *) = 0;
  virtual void hide() = 0;
  virtual jboolean isFocusTraversable() = 0;
  virtual jboolean isFocusable() = 0;
  virtual ::java::awt::Dimension * minimumSize() = 0;
  virtual ::java::awt::Dimension * preferredSize() = 0;
  virtual void paint(::java::awt::Graphics *) = 0;
  virtual jboolean prepareImage(::java::awt::Image *, jint, jint, ::java::awt::image::ImageObserver *) = 0;
  virtual void print(::java::awt::Graphics *) = 0;
  virtual void repaint(jlong, jint, jint, jint, jint) = 0;
  virtual void requestFocus() = 0;
  virtual jboolean requestFocus(::java::awt::Component *, jboolean, jboolean, jlong) = 0;
  virtual void reshape(jint, jint, jint, jint) = 0;
  virtual void setBackground(::java::awt::Color *) = 0;
  virtual void setBounds(jint, jint, jint, jint) = 0;
  virtual void setCursor(::java::awt::Cursor *) = 0;
  virtual void setEnabled(jboolean) = 0;
  virtual void setFont(::java::awt::Font *) = 0;
  virtual void setForeground(::java::awt::Color *) = 0;
  virtual void setVisible(jboolean) = 0;
  virtual void show() = 0;
  virtual ::java::awt::GraphicsConfiguration * getGraphicsConfiguration() = 0;
  virtual void setEventMask(jlong) = 0;
  virtual jboolean isObscured() = 0;
  virtual jboolean canDetermineObscurity() = 0;
  virtual void coalescePaintEvent(::java::awt::event::PaintEvent *) = 0;
  virtual void updateCursorImmediately() = 0;
  virtual jboolean handlesWheelScrolling() = 0;
  virtual ::java::awt::image::VolatileImage * createVolatileImage(jint, jint) = 0;
  virtual void createBuffers(jint, ::java::awt::BufferCapabilities *) = 0;
  virtual ::java::awt::Image * getBackBuffer() = 0;
  virtual void flip(::java::awt::BufferCapabilities$FlipContents *) = 0;
  virtual void destroyBuffers() = 0;
  virtual ::java::awt::Rectangle * getBounds() = 0;
  virtual void reparent(::java::awt::peer::ContainerPeer *) = 0;
  virtual void setBounds(jint, jint, jint, jint, jint) = 0;
  virtual jboolean isReparentSupported() = 0;
  virtual void layout() = 0;
  virtual jboolean requestFocus(::java::awt::Component *, jboolean, jboolean, jlong, ::sun::awt::CausedFocusEvent$Cause *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __java_awt_peer_WindowPeer__