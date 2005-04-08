/***************************************************************************
 *   Copyright (C) 2005 by Enrico Ros <eros.kde@email.it>                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef _KPDF_PAGEPAINTER_H_
#define _KPDF_PAGEPAINTER_H_

class KPDFPage;
class QPainter;
class QRect;

/**
 * @short Paints a KPDFPage to an open painter using given flags.
 */
class PagePainter
{
    public:
        // list of flags passed to the painting function. by OR-ing those flags
        // you can decide wether or not to permit drawing of a certain feature.
        enum PagePainterFlags { Accessibility = 1, EnhanceLinks = 2,
                                EnhanceImages = 4, Highlights = 8,
                                Annotations = 16 };

        // draw (using painter 'p') the 'page' requested by 'id' using features
        // in 'flags'. 'limits' is the bounding rect of the paint operation,
        // 'scaledWidth' and 'scaledHeight' the expected size of page contents
        static void paintPageOnPainter( QPainter * p, const KPDFPage * page, int pixID,
            int flags, int scaledWidth, int scaledHeight, const QRect & pageLimits );

    private:
        // create an image taking the 'cropRect' portion of a pixmap. the
        // cropRect must be inside the source pixmap
        static void cropPixmapOnImage( QImage & dest, const QPixmap * src,
            const QRect & cropRect );

        // create an image taking the 'cropRect' portion of a pixmap scaled
        // to 'scaledWidth' by 'scaledHeight' pixels. cropRect must be inside
        // the QRect(0,0, scaledWidth,scaledHeight)
        static void scalePixmapOnImage( QImage & dest, const QPixmap * src,
            int scaledWidth, int scaledHeight, const QRect & cropRect );

        // set the alpha component of the image to a given value
        static void changeImageAlpha( QImage & image, unsigned int alpha );

        // colorize a gray image to the given color
        static void colorizeImage( QImage & image, const QColor & color,
                unsigned int alpha = 255 );
};

#endif
