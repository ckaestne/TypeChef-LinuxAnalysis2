/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/**
 * bonobo-ui-toolbar-button-item.h: a toolbar button
 *
 * Author: Ettore Perazzoli
 *
 * Copyright (C) 2000 Helix Code, Inc.
 */

#ifndef _BONOBO_UI_TOOLBAR_BUTTON_ITEM_H_
#define _BONOBO_UI_TOOLBAR_BUTTON_ITEM_H_

#include <glib.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

#include "bonobo-ui-toolbar-item.h"

#ifndef BONOBO_UI_DISABLE_DEPRECATED

G_BEGIN_DECLS

#define BONOBO_TYPE_UI_TOOLBAR_BUTTON_ITEM		(bonobo_ui_toolbar_button_item_get_type ())
#define BONOBO_UI_TOOLBAR_BUTTON_ITEM(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), BONOBO_TYPE_UI_TOOLBAR_BUTTON_ITEM, BonoboUIToolbarButtonItem))
#define BONOBO_UI_TOOLBAR_BUTTON_ITEM_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), BONOBO_TYPE_UI_TOOLBAR_BUTTON_ITEM, BonoboUIToolbarButtonItemClass))
#define BONOBO_IS_UI_TOOLBAR_BUTTON_ITEM(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), BONOBO_TYPE_UI_TOOLBAR_BUTTON_ITEM))
#define BONOBO_IS_UI_TOOLBAR_BUTTON_ITEM_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), BONOBO_TYPE_UI_TOOLBAR_BUTTON_ITEM))

typedef struct _BonoboUIToolbarButtonItemPrivate BonoboUIToolbarButtonItemPrivate;

typedef struct {
	BonoboUIToolbarItem parent;

	BonoboUIToolbarButtonItemPrivate *priv;
} BonoboUIToolbarButtonItem;

typedef struct {
	BonoboUIToolbarItemClass parent_class;

	/* Virtual methods */
	void (* set_icon)       (BonoboUIToolbarButtonItem *button_item,
				 gpointer                   image);
	void (* set_label)      (BonoboUIToolbarButtonItem *button_item,
				 const char                *label);

	/* Signals.  */
	void (* clicked)	(BonoboUIToolbarButtonItem *toolbar_button_item);
	void (* set_want_label) (BonoboUIToolbarButtonItem *toolbar_button_item);

	gpointer dummy[2];
} BonoboUIToolbarButtonItemClass;

GType    bonobo_ui_toolbar_button_item_get_type           (void) G_GNUC_CONST;
void       bonobo_ui_toolbar_button_item_construct          (BonoboUIToolbarButtonItem *item,
							     GtkButton                 *button_widget,
							     GdkPixbuf                 *icon,
							     const char                *label);
GtkWidget *bonobo_ui_toolbar_button_item_new                (GdkPixbuf                 *icon,
							     const char                *label);

void       bonobo_ui_toolbar_button_item_set_image          (BonoboUIToolbarButtonItem *button_item,
							     gpointer                   image);
void       bonobo_ui_toolbar_button_item_set_label          (BonoboUIToolbarButtonItem *button_item,
							     const char                *label);

GtkButton *bonobo_ui_toolbar_button_item_get_button_widget  (BonoboUIToolbarButtonItem *button_item);

G_END_DECLS

#endif /* BONOBO_UI_DISABLE_DEPRECATED */

#endif /* _BONOBO_UI_TOOLBAR_BUTTON_ITEM_H_ */
