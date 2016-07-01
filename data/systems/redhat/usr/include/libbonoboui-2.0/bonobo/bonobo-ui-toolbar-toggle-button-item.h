/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/**
 * bonobo-ui-toolbar-toggle-button-item.h
 *
 * Author:
 *     Ettore Perazzoli
 *
 * Copyright (C) 2000 Helix Code, Inc.
 */

#ifndef _BONOBO_UI_TOOLBAR_TOGGLE_BUTTON_ITEM_H_
#define _BONOBO_UI_TOOLBAR_TOGGLE_BUTTON_ITEM_H_

#include <glib.h>
#include "bonobo-ui-toolbar-button-item.h"

#ifndef BONOBO_UI_DISABLE_DEPRECATED

G_BEGIN_DECLS

#define BONOBO_TYPE_UI_TOOLBAR_TOGGLE_BUTTON_ITEM             (bonobo_ui_toolbar_toggle_button_item_get_type ())
#define BONOBO_UI_TOOLBAR_TOGGLE_BUTTON_ITEM(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), BONOBO_TYPE_UI_TOOLBAR_TOGGLE_BUTTON_ITEM, BonoboUIToolbarToggleButtonItem))
#define BONOBO_UI_TOOLBAR_TOGGLE_BUTTON_ITEM_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), BONOBO_TYPE_UI_TOOLBAR_TOGGLE_BUTTON_ITEM, BonoboUIToolbarToggleButtonItemClass))
#define BONOBO_IS_UI_TOOLBAR_TOGGLE_BUTTON_ITEM(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BONOBO_TYPE_UI_TOOLBAR_TOGGLE_BUTTON_ITEM))
#define BONOBO_IS_UI_TOOLBAR_TOGGLE_BUTTON_ITEM_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), BONOBO_TYPE_UI_TOOLBAR_TOGGLE_BUTTON_ITEM))


typedef struct _BonoboUIToolbarToggleButtonItemPrivate BonoboUIToolbarToggleButtonItemPrivate;

typedef struct {
	BonoboUIToolbarButtonItem parent;
} BonoboUIToolbarToggleButtonItem;

typedef struct {
	BonoboUIToolbarButtonItemClass parent_class;

	void (* toggled) (BonoboUIToolbarToggleButtonItem *toggle_button_item);

	gpointer dummy[2];
} BonoboUIToolbarToggleButtonItemClass;


GType    bonobo_ui_toolbar_toggle_button_item_get_type   (void) G_GNUC_CONST;
void       bonobo_ui_toolbar_toggle_button_item_construct  (BonoboUIToolbarToggleButtonItem *toggle_button_item,
							 GdkPixbuf                     *icon,
							 const char                    *label);
GtkWidget *bonobo_ui_toolbar_toggle_button_item_new        (GdkPixbuf                     *icon,
							 const char                    *label);

void      bonobo_ui_toolbar_toggle_button_item_set_active  (BonoboUIToolbarToggleButtonItem *item,
							 gboolean                       active);
gboolean  bonobo_ui_toolbar_toggle_button_item_get_active  (BonoboUIToolbarToggleButtonItem *item);

G_END_DECLS

#endif /* BONOBO_UI_DISABLE_DEPRECATED */

#endif /* _BONOBO_UI_TOOLBAR_TOGGLE_BUTTON_ITEM_H_ */
