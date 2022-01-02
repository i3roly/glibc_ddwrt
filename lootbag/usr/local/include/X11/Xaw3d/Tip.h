/*
 * Copyright (c) 1999 by The XFree86 Project, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE XFREE86 PROJECT BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name of the XFree86 Project shall
 * not be used in advertising or otherwise to promote the sale, use or other
 * dealings in this Software without prior written authorization from the
 * XFree86 Project.
 *
 * Author: Paulo César Pereira de Andrade
 */

#ifndef _XawTip_h
#define _XawTip_h

/*
 * Tip Widget
 */

#include "Xaw3dP.h"
#include <X11/Xaw3d/Simple.h>

/* Resources:

  Name		    Class		RepType		Default Value
  ----		    -----		-------		-------------
  background	    Background		Pixel		XtDefaultBackground
  backgroundPixmap  BackgroundPixmap	Pixmap		XtUnspecifiedPixmap
  border	    BorderColor		Pixel		XtDefaultForeground
  borderWidth	    BorderWidth		Dimension	1
  destroyCallback   Callback		XtCallbackList	NULL
  font		    Font		XFontStruct*	XtDefaultFont
  foreground	    Foreground		Pixel		XtDefaultForeground
  height	    Height		Dimension	text height
  internalHeight    Height		Dimension	2
  internalWidth     Width		Dimension	2
  label		    Label		String		NULL
  timeout	    Timeout		Int		500
  width		    Width		Dimension	text width
  x		    Position		Position	0
  y		    Position		Position	0

*/

typedef struct _TipClassRec *TipWidgetClass;
typedef struct _TipRec *TipWidget;

extern WidgetClass tipWidgetClass;

#define XawTextEncoding8bit	0
#define XawTextEncodingChar2b	1

#define XtNencoding "encoding"
#define XtNtimeout "timeout"
#define XtNtip "tip"

#ifdef XAW_INTERNATIONALIZATION
#ifndef XtNfontSet
#define XtNfontSet "fontSet"
#endif
#ifndef XtCFontSet
#define XtCFontSet "FontSet"
#endif
#endif

#define XtCEncoding "Encoding"
#define XtCTimeout "Timeout"
#define XtCTip "Tip"

#ifndef _XtStringDefs_h_
#define XtNforeground "foreground"
#define XtNlabel "label"
#define XtNfont "font"
#define XtNinternalWidth "internalWidth"
#define XtNinternalHeight "internalHeight"
#endif

/*
 * Public Functions
 */

/*
 * Function:
 *	XawTipEnable
 *
 * Parameters:
 *	Widget - widget for tooltip
 *	String - tooltip label
 *
 * Description:
 *	Enables the tip event handler for this widget.
 */
void XawTipEnable(
 Widget,
 String
);

/*
 * Function:
 *	XawTipDisable
 *
 * Parameters:
 *	Widget - widget for tooltip
 *
 * Description:
 *	Disables the tip event handler for this widget.
 */
void XawTipDisable(
 Widget
);

#endif /* _XawTip_h */
