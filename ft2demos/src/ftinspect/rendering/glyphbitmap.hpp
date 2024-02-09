// glyphbitmap.hpp

// Copyright (C) 2016-2022 by Werner Lemberg.


#pragma once

#include <QGraphicsItem>
#include <QPen>

#include <ft2build.h>
#include <freetype/freetype.h>
#include <freetype/ftoutln.h>


class GlyphBitmap
: public QGraphicsItem
{
public:
  GlyphBitmap(FT_Outline* outline,
              FT_Library library,
              FT_Pixel_Mode pixelMode,
              const QVector<QRgb>& monoColorTable,
              const QVector<QRgb>& grayColorTable);
  ~GlyphBitmap();
  QRectF boundingRect() const;
  void paint(QPainter* painter,
             const QStyleOptionGraphicsItem* option,
             QWidget* widget);

private:
  FT_Outline transformed;
  FT_Library library;
  unsigned char pixelMode;
  const QVector<QRgb>& monoColorTable;
  const QVector<QRgb>& grayColorTable;
  QRectF bRect;
};


// end of glyphbitmap.hpp
