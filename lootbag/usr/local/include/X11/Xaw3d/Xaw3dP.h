/*
 * Xaw3dP.h
 *
 * Global definitions and declarations. Not for public consumption.
 */

/*********************************************************************
Copyright (C) 1992 Kaleb Keithley
Copyright (C) 2000, 2003 David J. Hawkey Jr.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and
its documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appear in all copies and
that both that copyright notice and this permission notice appear in
supporting documentation, and that the names of the copyright holders
not be used in advertising or publicity pertaining to distribution
of the software without specific, written prior permission.

THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS. IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER
RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF
CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*********************************************************************/

#ifndef _Xaw3dP_h
#define _Xaw3dP_h

#include <X11/IntrinsicP.h>

/* These are set during the build to reflect capability and options. */
/* I18n support */
/* XPM support */
/* gray stipples */
/* arrow scrollbars */

#ifndef XtX
#define XtX(w)			(((RectObj)w)->rectangle.x)
#endif
#ifndef XtY
#define XtY(w)			(((RectObj)w)->rectangle.y)
#endif
#ifndef XtWidth
#define XtWidth(w)		(((RectObj)w)->rectangle.width)
#endif
#ifndef XtHeight
#define XtHeight(w)		(((RectObj)w)->rectangle.height)
#endif
#ifndef XtBorderWidth
#define XtBorderWidth(w)	(((RectObj)w)->rectangle.border_width)
#endif

#ifdef XAW_GRAY_BLKWHT_STIPPLES
extern unsigned long
grayPixel(
    unsigned long,
    Display *,
    Screen *
);
#else
#define grayPixel(p, dpy, scn)	(p)
#endif

#ifdef XAW_MULTIPLANE_PIXMAPS
extern Pixmap
stipplePixmap(
    Widget,
    Pixmap,
    Colormap,
    Pixel,
    unsigned int
);
#endif

#endif	/* _Xaw3dP_h */
